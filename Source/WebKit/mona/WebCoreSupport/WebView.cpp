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
#include "FocusController.h"
#include "Page.h"
#include "WebPage.h"
#include "NotImplemented.h"
#include "PlatformKeyboardEvent.h"
#include "Frame.h"
#include "WebView.h"

extern void (*SharedTimerFiredFunction)();

// class MonaLauncher : public monagui::Frame {
//  public:
//   MonaLauncher(const std::string& url) : Frame("browser"), data_(0), is_first_(true), url_(url) {
//     setBackground(monagui::Color::blue);
//     setBounds(40, 40, 400, 400);
//     set_timer(10);
//   }

//   void paint(Graphics *g) {
//     if (data_) {
//       _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//       for (int i = 0; i < 400; i++) {
//         for (int j = 0; j < 400; j++) {
//           g->drawPixel(i, j, ((uint32_t*)(data_))[i + j * 400]);
//         }
//       }
//     }
//   }

//   void processEvent(Event* event) {
//     if (event->getType() == Event::TIMER) {
//       if (is_first_) {
//         kill_timer(event->arg1);
//         is_first_ = false;
//         web_view_.LoadURL(url_.c_str());
//         return;
//       }
//       if (SharedTimerFiredFunction) {
//         kill_timer(event->arg1);
//         _logprintf("before timer call %s %s:%d\n", __func__, __FILE__, __LINE__);
//         SharedTimerFiredFunction();
//         _logprintf("after timer call %s %s:%d\n", __func__, __FILE__, __LINE__);
//       }
//     }
//   }

//   void SetData(unsigned char* p) {
//     data_ = p;
//   }
//  private:
//   unsigned char* data_;
//   bool is_first_;
//   std::string url_;
//   WebCore::WebView web_view_;
// };

extern monagui::FontMetrics* g_fontMetrics;

using namespace WebCore;

WebView::WebView() : web_page_(new WebPage(this)),
                     image_buffer_(0),
                     Frame("browser"),
                     status_(new Label("")) {
  ASSERT(web_page_);
  web_page_->Init();
  setBackground(monagui::Color::blue);
  setBounds(40, 40, WEBVIEW_WIDTH, WEBVIEW_HEIGHT + 55);
  g_fontMetrics = getFontMetrics();

  status_->setBackground(monagui::Color::lightGray);
  status_->setBounds(0, WEBVIEW_HEIGHT, WEBVIEW_WIDTH, 30);
  add(status_.get());
}

void WebView::paint(Graphics *g) {
  if (image_buffer_) {
    for (int i = 0; i < WEBVIEW_WIDTH; i++) {
      for (int j = 0; j < WEBVIEW_HEIGHT; j++) {
        g->drawPixel(i, j, ((uint32_t*)(image_buffer_))[i + j * WEBVIEW_WIDTH]);
      }
    }
  }
}


void WebView::SetImageBuffer(unsigned char* p) {
  image_buffer_ = p;
}

void WebView::processEvent(monagui::Event* event) {
    if (event->getType() == monagui::Event::TIMER) {
      if (SharedTimerFiredFunction) {
        kill_timer(event->arg1);
        //        _logprintf("before timer call %s %s:%d\n", __func__, __FILE__, __LINE__);
        SharedTimerFiredFunction();
        //        _logprintf("after timer call %s %s:%d\n", __func__, __FILE__, __LINE__);
      }
    } else if (event->getType() == monagui::Event::KEY_PRESSED ||
               event->getType() == monagui::Event::KEY_RELEASED) {
        int keycode = ((KeyEvent *)event)->getKeycode();
        int modifiers = ((KeyEvent *)event)->getModifiers();
        PlatformKeyboardEvent keyEvent((monagui::KeyEvent *)event);
        WebCore::Frame* frame = web_page_->page()->focusController()->focusedOrMainFrame();
        frame->eventHandler()->keyEvent(keyEvent);
    } else if (event->getType() == monagui::Event::MOUSE_PRESSED) {
        PlatformMouseEvent mouseEvent((monagui::MouseEvent *)event);
        WebCore::Frame* frame = web_page_->page()->focusController()->focusedOrMainFrame();
        frame->eventHandler()->handleMousePressEvent(mouseEvent);
    } else if (event->getType() == monagui::Event::MOUSE_RELEASED) {
        PlatformMouseEvent mouseEvent((monagui::MouseEvent *)event);
        WebCore::Frame* frame = web_page_->page()->focusController()->focusedOrMainFrame();
        frame->eventHandler()->handleMouseReleaseEvent(mouseEvent);
    } else if (event->getType() == monagui::Event::MOUSE_MOVED) {
        PlatformMouseEvent mouseEvent((monagui::MouseEvent *)event);
        WebCore::Frame* frame = web_page_->page()->focusController()->focusedOrMainFrame();
        // We call mouseMoved here instead of handleMouseMovedEvent because we need
        // our ChromeClient to receive changes to the mouse position and
        // tooltip text, and mouseMoved handles all of that.
        frame->eventHandler()->mouseMoved(mouseEvent);
    } else {
    }
}

void WebView::LoadURL(const char* urlString, bool aquireFocus /* = true */) {
  web_page_->LoadURL(urlString);
  run();
}

void WebView::SetStatus(const char* text) {
  status_->setText(text);
}
