/*
 * Copyright (c) 2011  Higepon(Taro Minowa) <higepon@users.sourceforge.jp>r
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

#include "config.h"
#include "WebPage.h"
#include "NotImplemented.h"
#include "WebFrame.h"
#include "Frame.h"
#include "FrameView.h"
#include "ChromeClientMona.h"
#include "ContextMenuClientMona.h"
#include "EditorClientMona.h"
#include "DragClientMona.h"
#include "InspectorClientMona.h"
#include "Page.h"
#include "Settings.h"
#include "FrameLoaderClientMona.h"
#include "WebView.h"


using namespace WebCore;

WebPage::WebPage(WebView* web_view, const IntSize& viewSize) :
    web_view_(web_view),
    surface_(cairo_image_surface_create(CAIRO_FORMAT_ARGB32,
                                        WEBVIEW_WIDTH, WEBVIEW_HEIGHT)),
    m_viewSize(viewSize) {

  if (cairo_surface_status(surface_) != CAIRO_STATUS_SUCCESS) {
    monapi_fatal("cairo cairo_image_surface_create failure");
  }
  cairo_ = cairo_create(surface_);

  Page::PageClients clients;
  clients.chromeClient = new ChromeClientMona(this);
  clients.contextMenuClient = new ContextMenuClientMona();
  EditorClientMona* editorClient = new EditorClientMona(this);
  clients.editorClient = editorClient;
  clients.dragClient = new DragClientMona();
  clients.inspectorClient = new InspectorClientMona();

  m_page = adoptPtr(new Page(clients));
  m_page->settings()->setLoadsImagesAutomatically(true);
  m_page->settings()->setJavaScriptEnabled(true);
  m_page->settings()->setCaretBrowsingEnabled(true);
  m_page->settings()->setDeveloperExtrasEnabled(true);
  m_page->settings()->setPasswordEchoEnabled(true);
  m_page->settings()->setShouldPaintCustomScrollbars(true);
  m_page->settings()->setShowDebugBorders(true);
  m_page->settings()->setShowRepaintCounter(true);

  m_mainFrame = WebFrame::createMainFrame(this);
}

WebPage::~WebPage() {
  cairo_destroy(cairo_);
  cairo_surface_destroy(surface_);
}

uint8_t* WebPage::paint(const IntRect& rect, bool immediate) {
  if (rect.isEmpty()) {
    return NULL;
  }
  ASSERT(web_view_);
  ASSERT(m_mainFrame.get());
  ASSERT(m_mainFrame->coreFrame());

  Frame* frame = m_mainFrame->coreFrame();
  if (!frame->contentRenderer()) {
    _logprintf("skip becase of contentRenderer");
    return NULL;
  }

  FrameView* view = frame->view();

  // N.B.
  // I'm not sure this is correct place whether view isInLayout().
  if (!view->isInLayout()) {
    view->updateLayoutAndStyleIfNeededRecursive();
    return paintWithoutLayout(rect, immediate);
  } else {
    return NULL;
  }
}

uint8_t* WebPage::paintWithoutLayout(const IntRect& rect, bool immediate) {
  GraphicsContext context(cairo_);
  m_mainFrame->coreFrame()->view()->paint(&context, rect);
  return cairo_image_surface_get_data(surface_);
}

void WebPage::LoadURL(const char* urlString) {
  ASSERT(m_mainFrame.get());
  ASSERT(urlString);
  ASSERT(m_mainFrame->coreFrame());
  ASSERT(m_mainFrame->coreFrame()->loader());
  WTF::String url(urlString);
  m_mainFrame->coreFrame()->loader()->load(url, false);
}

void WebPage::SetStatus(const char* text) {
  web_view_->SetStatus(text);
}
