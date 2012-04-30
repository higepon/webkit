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
#include "FrameLoaderClientMona.h"
#include "WebView.h"


using namespace WebCore;

WebPage::WebPage(WebView* web_view) :
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

  m_page = adoptPtr(new Page(*clients));
  m_page->settings()->setLoadsImagesAutomatically(true);
  m_page->settings()->setJavaScriptEnabled(true);
  m_page->settings()->setCaretBrowsingEnabled(true);
  m_page->settings()->setDeveloperExtrasEnabled(true);
  m_page->settings()->setPasswordEchoEnabled(true);
  m_page->settings()->setShouldPaintCustomScrollbars(true);
  m_page->settings()->setShowDebugBorders(true);
  m_page->settings()->setShowRepaintCounter(true);
  editorClient->setPage(m_page.get()); // todo: compare to webkit2

  m_mainFrame = WebFrame::createMainFrame(this);

  // Todo: these should be moved to proper place
  m_mainFrame->createFrameLoaderClient(web_view, this);

  // WebFramePrivate* data = new WebFramePrivate;
  // data->name = "Hello";
  // data->page = m_page;
  // main_frame_ = new WebFrame(this, 0, data, web_view_);


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
  ASSERT(m_mainFrame.get());
  ASSERT(m_mainFrame->coreFrame());

  Frame* frame = m_mainFrame->coreFrame();
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
  //    _logprintf("MSG_PAINT end0 %d %s %s:%d\n", (int)MonAPI::Date::nowInMsec(), __func__, __FILE__, __LINE__);
  m_mainFrame->coreFrame()->view()->paint(&context, rect);
  //    _logprintf("MSG_PAINT end1 %d %s %s:%d\n", (int)MonAPI::Date::nowInMsec(), __func__, __FILE__, __LINE__);
  web_view_->SetImageBuffer(cairo_image_surface_get_data(surface_));

  // TODO: apply rect and immediate
  //  _logprintf("(%d %d %d %d) immediate=%d\n", rect.x(), rect.y(), rect.width(), rect.height(), immediate);
    web_view_->repaint();
  //  web_view_->paint(rect);
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

PassRefPtr<WebCore::Frame> WebPage::createFrame(const WebCore::KURL& url,
                                                const WTF::String& name, HTMLFrameOwnerElement* ownerElement, const WTF::String& referrer,
                                                bool allowsScrolling, int marginWidth, int marginHeight, FrameLoaderClientMona* loader) {
    RefPtr<Frame> childFrame = Frame::create(m_mainFrame->coreFrame()->page(), ownerElement, loader);
    loader->setFrame(childFrame.get());
    RefPtr<FrameView> frameView = FrameView::create(childFrame.get());
    //    frameView->setAllowsScrolling(allowsScrolling);
    childFrame->setView(frameView.get());
    //    frameView->deref();
    childFrame->init();
    childFrame->tree()->setName(name);
    m_mainFrame->coreFrame()->tree()->appendChild(childFrame);
    m_mainFrame->coreFrame()->loader()->loadURLIntoChildFrame(url, referrer, childFrame.get());
    // The frame's onload handler may have removed it from the document.
    if (!childFrame->tree()->parent())
        return 0;

    return childFrame.release();

  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   ASSERT(m_mainFrame);
  //   ASSERT(m_mainFrame->coreFrame());
  //   Frame* coreFrame = m_mainFrame->coreFrame();
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   FrameLoaderClientMona *loaderClient = new FrameLoaderClientMona(this, m_mainFrame);
  //   RefPtr<Frame> childFrame = Frame::create(m_page, ownerElement, loaderClient);
  //   loaderClient->setFrame(childFrame.get());
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   RefPtr<FrameView> frameView = FrameView::create(childFrame.get());
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   childFrame->setView(frameView.get());
  //   frameView->deref();
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   coreFrame->tree()->appendChild(childFrame);
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   childFrame->tree()->setName(name);
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   childFrame->init();
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   // RefPtr<Frame> childFrame = Frame::create(frame_->page(), ownerElement, this);
  //   // setFrame(childFrame.get());

  //   // RefPtr<FrameView> frameView = FrameView::create(childFrame.get());

  //   // frameView->setAllowsScrolling(allowsScrolling);
  //   // frameView->deref();
  //   // childFrame->setView(frameView.get());
  //   // childFrame->init();

  //   // childFrame->tree()->setName(name);
  //   // frame_->tree()->appendChild(childFrame);

  //   // frame_->loader()->loadURLIntoChildFrame(url, referrer, childFrame.get());

  //   // // The frame's onload handler may have removed it from the document.
  //   // if (!childFrame->tree()->parent())
  //   //     return 0;



  //   // The creation of the frame may have run arbitrary JavaScript that removed it from the page already.
  //   if (!childFrame->page())
  //       return 0;

  //   coreFrame->loader()->loadURLIntoChildFrame(url, referrer, childFrame.get());

  //   // The frame's onload handler may have removed it from the document.
  //   if (!childFrame->tree()->parent())
  //       return 0;

  //   return childFrame.release();
}
