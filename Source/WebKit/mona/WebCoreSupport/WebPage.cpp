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
#include "WebFramePrivate.h"
#include "ChromeClientMona.h"
#include "ContextMenuClientMona.h"
#include "EditorClientMona.h"
#include "DragClientMona.h"
#include "InspectorClientMona.h"
#include "Page.h"
#include "Settings.h"
#include "WebView.h"

using namespace WebCore;

WebPage::WebPage(WebView* web_view) :
    page_(0),
    main_frame_(0),
    web_view_(web_view),
    surface_(cairo_image_surface_create(CAIRO_FORMAT_ARGB32,
                                        WEBVIEW_WIDTH, WEBVIEW_HEIGHT)) {

  if (cairo_surface_status(surface_) != CAIRO_STATUS_SUCCESS) {
    monapi_fatal("cairo cairo_image_surface_create failure");
  }
  cairo_ = cairo_create(surface_);

  // todo: life cycle of clients
  Page::PageClients* clients = new Page::PageClients;
  ASSERT(clients);
  clients->chromeClient = new ChromeClientMona(this);
  clients->contextMenuClient = new ContextMenuClientMona();
  EditorClientMona* editorClient = new EditorClientMona();
  clients->editorClient = editorClient;
  clients->dragClient = new DragClientMona();
  clients->inspectorClient = new InspectorClientMona();

  page_ = new WebCore::Page(*clients);
  page_->settings()->setLoadsImagesAutomatically(true);
  page_->settings()->setJavaScriptEnabled(true);
  page_->settings()->setCaretBrowsingEnabled(true);
  page_->settings()->setDeveloperExtrasEnabled(true);
  page_->settings()->setPasswordEchoEnabled(true);
  editorClient->setPage(page_);

    // todo: Is this necessary?
  // fSettings = new BWebSettings(fPage->settings());
}

WebPage::~WebPage() {
  cairo_destroy(cairo_);
  cairo_surface_destroy(surface_);
}

void WebPage::paint(const IntRect& rect, bool immediate) {
  if (rect.isEmpty()) {
    return;
  }
  ASSERT(web_view_);
  ASSERT(main_frame_);
  ASSERT(main_frame_->Frame());

  Frame* frame = main_frame_->Frame();
  if (!frame->contentRenderer()) {
    _logprintf("skip becase of contentRenderer");
    return;
  }

  FrameView* view = frame->view();

  // N.B.
  // I'm not sure this is correct place whether view isInLayout().
  if (!view->isInLayout()) {
    view->updateLayoutAndStyleIfNeededRecursive();
    paintWithoutLayout(rect, immediate);
  }
}

void WebPage::paintWithoutLayout(const IntRect& rect, bool immediate) {
  GraphicsContext context(cairo_);
  main_frame_->Frame()->view()->paint(&context, rect);
  web_view_->SetImageBuffer(cairo_image_surface_get_data(surface_));

  // TODO: apply rect and immediate
  _logprintf("(%d %d %d %d) immediate=%d\n", rect.x(), rect.y(), rect.width(), rect.height(), immediate);
    web_view_->repaint();
  //  web_view_->paint(rect);
}

void WebPage::Init() {
  WebFramePrivate* data = new WebFramePrivate;
  data->name = "Hello";
  data->page = page_;
  main_frame_ = new WebFrame(this, 0, data, web_view_);
// _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
}

void WebPage::LoadURL(const char* urlString) {
  ASSERT(main_frame_);
  main_frame_->LoadURL(urlString);
}

void WebPage::SetStatus(const char* text) {
  web_view_->SetStatus(text);
}
