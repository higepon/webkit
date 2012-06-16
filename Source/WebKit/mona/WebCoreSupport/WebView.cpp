/*
 *   Copyright (c) 2011  Higepon(Taro Minowa) <higepon@users.sourceforge.jp>r
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <assert.h>
#include "config.h"
#include "ResourceHandleManager.h"
#include "FocusController.h"
#include "Page.h"
#include "WebPage.h"
#include "NotImplemented.h"
#include "PlatformKeyboardEvent.h"
#include "Frame.h"
#include "FrameLoaderClientMona.h"
#include "WebView.h"

extern void (*SharedTimerFiredFunction)();
extern monagui::FontMetrics* g_fontMetrics;

using namespace WebCore;

void WebCanvas::paint(Graphics* g) {
  const Rectangle rect = g->getClipBound();
  IntRect r(rect.x, rect.y, rect.height, rect.width);
  uint8_t* image_buffer = web_page_->paint(r, true);
  if (image_buffer == NULL) {
    return;
  }

  int xmax = rect.x + rect.width;
  int ymax = rect.y + rect.height;

  for (int j = rect.y; j < ymax; j++) {
    for (int i = rect.x; i < xmax; i++) {
      g->drawPixel(i, j, ((uint32_t*)(image_buffer))[i + j * getWidth()]);
    }
  }
}

void WebCanvas::processEvent(monagui::Event* event) {
  if (event->getType() == monagui::Event::KEY_PRESSED ||
             event->getType() == monagui::Event::KEY_RELEASED) {
    PlatformKeyboardEvent keyEvent((monagui::KeyEvent *)event);
    WebCore::Frame* frame = web_page_->corePage()->focusController()->focusedOrMainFrame();
    frame->eventHandler()->keyEvent(keyEvent);
  } else if (event->getType() == monagui::Event::MOUSE_PRESSED) {
    PlatformMouseEvent mouseEvent((monagui::MouseEvent *)event);
    WebCore::Frame* frame = web_page_->corePage()->focusController()->focusedOrMainFrame();
    frame->eventHandler()->handleMousePressEvent(mouseEvent);
  } else if (event->getType() == monagui::Event::MOUSE_RELEASED) {
    PlatformMouseEvent mouseEvent((monagui::MouseEvent *)event);
    WebCore::Frame* frame = web_page_->corePage()->focusController()->focusedOrMainFrame();
    frame->eventHandler()->handleMouseReleaseEvent(mouseEvent);
  } else if (event->getType() == monagui::Event::MOUSE_MOVED) {
    PlatformMouseEvent mouseEvent((monagui::MouseEvent *)event);
    WebCore::Frame* frame = web_page_->corePage()->focusController()->focusedOrMainFrame();
    // We call mouseMoved here instead of handleMouseMovedEvent because we need
    // our ChromeClient to receive changes to the mouse position and
    // tooltip text, and mouseMoved handles all of that.
    frame->eventHandler()->mouseMoved(mouseEvent);
  }
}

WebView::WebView() : web_page_(new WebPage(this, IntSize(WEBVIEW_WIDTH, WEBVIEW_HEIGHT))),
                     Frame("browser"),
                     status_(new Label("")),
                     canvas_(new WebCanvas(web_page_)) {
  ASSERT(web_page_);

  setBackground(monagui::Color::blue);
  setBounds(40, 150, WEBVIEW_WIDTH, WEBVIEW_HEIGHT + 55);
  g_fontMetrics = getFontMetrics();

  status_->setBackground(monagui::Color::lightGray);
  status_->setBounds(0, WEBVIEW_HEIGHT, WEBVIEW_WIDTH, 30);
  ResourceHandleManager::sharedInstance()->setCookieJarFileName("/USER/COOKIE.TXT");
  add(status_.get());
  canvas_->setBounds(0, 0, WEBVIEW_WIDTH, WEBVIEW_HEIGHT);
  canvas_->setBackground(monagui::Color::red);
  add(canvas_.get());
}

WebView::~WebView() {
}

void WebView::processEvent(monagui::Event* event) {
  if (event->getType() == monagui::Event::TIMER) {
    if (SharedTimerFiredFunction) {
      SharedTimerFiredFunction();
    }
  } else if (event->getType() == monagui::Event::CUSTOM_EVENT && event->header == MSG_UPDATE) {
    int x = event->arg1 & 0xffff;
    int y = event->arg1 >> 16;
    int w = event->arg2 & 0xffff;
    int h = event->arg2 >> 16;
    IntRect currentRect = MergeRepaintRequest(x, y, w, h);
    canvas_->repaint(currentRect.x(), currentRect.y(), currentRect.width(), currentRect.height());
  } else {
  }
}

IntRect WebView::MergeRepaintRequest(int x, int y, int w, int h) {
  for (int i = 0;;) {
    MessageInfo msg;
    int result = MonAPI::Message::peek(&msg, i);
    if (result == M_BAD_INDEX) {
      break;
    } else if (result == M_OK) {
      if (msg.header == MSG_UPDATE) {
        MonAPI::Message::peek(&msg, i, PEEK_REMOVE);
        int nx = msg.arg1 & 0xffff;
        int ny = msg.arg1 >> 16;
        int nw = msg.arg2 & 0xffff;
        int nh = msg.arg2 >> 16;
        x = nx < x ? nx : x;
        y = ny < y ? ny : y;
        w = nw > w ? nw : w;
        h = nh > h ? nh : h;
      }
      i++;
    }
  }
  return IntRect(x, y, w, h);
}

void WebView::Repaint(const IntRect& rect) {
  uint32_t xy =  (rect.y() << 16) | rect.x();
  uint32_t wh =  (rect.height() << 16) | rect.width();
  if (MonAPI::Message::send(MonAPI::System::getThreadID(), MSG_UPDATE, xy, wh) != M_OK) {
    monapi_warn("message send failure");
  }
}

void WebView::LoadURL(const char* urlString, bool aquireFocus /* = true */) {
  web_page_->LoadURL(urlString);
  run();
}

void WebView::SetStatus(const std::string& text) {
  if (getGraphics()) {
    std::string content(" ");
    content += text;
    status_->setText(content.c_str());
  }
}
