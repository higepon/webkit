/*
 * Copyright (C) 2009 Maxime Simon <simon.maxime@gmail.com>
 * Copyright (C) 2010 Stephan Aßmus <superstippi@gmx.de>
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
#include "WebFrame.h"

#include "Document.h"
#include "EditorClientMona.h"
#include "Element.h"
#include "Frame.h"
#include "FrameLoader.h"
#include "FrameLoaderClientMona.h"
#include "FrameView.h"
#include "HTMLFrameOwnerElement.h"
#include "KURL.h"
#include "Page.h"
#include "PlatformString.h"
#include "RenderObject.h"
#include "RenderTreeAsText.h"
#include "RenderView.h"
#include "WebFramePrivate.h"
#include "WebPage.h"
#include "markup.h"
#include <wtf/RefPtr.h>
#include <wtf/Vector.h>
#include <Entry.h>

using namespace WebCore;

void WebFrame::init(WebPage* page, const String& frameName, HTMLFrameOwnerElement* ownerElement)
{
    ASSERT(m_frameLoaderClient);
    RefPtr<WebCore::Frame> frame = Frame::create(page->corePage(), ownerElement, m_frameLoaderClient);
    m_coreFrame = frame.get();

    frame->tree()->setName(frameName);

    if (ownerElement) {
        ASSERT(ownerElement->document()->frame());
        ownerElement->document()->frame()->tree()->appendChild(frame);
    }

    frame->init();
}

PassRefPtr<WebFrame> WebFrame::createMainFrame(WebPage* page)
{
    RefPtr<WebFrame> frame = create();

    frame->init(page, String(), 0);

    return frame.release();
}

PassRefPtr<WebFrame> WebFrame::create()
{
    RefPtr<WebFrame> frame = adoptRef(new WebFrame);

    // Add explict ref() that will be balanced in WebFrameLoaderClient::frameLoaderDestroyed().
    frame->ref();

    return frame.release();
}

void WebFrame::createFrameLoaderClient(WebView* webView, WebPage* webPage)
{
  m_frameLoaderClient = new WebCore::FrameLoaderClientMona(webPage, this);
  m_frameLoaderClient->setWebView(webView);
  m_frameLoaderClient->setFrame(m_coreFrame); // todo: Is this necessary?
}

WebFrame::WebFrame()
    : m_coreFrame(0),
      m_frameLoaderClient(0)
{
}

// WebFrame::WebFrame(WebPage* web_page, WebFrame* parent_frame, WebFramePrivate* data, WebView* web_view)
//     : data_(data) {
//   data_->loaderClient = new WebCore::FrameLoaderClientMona(web_page, this);
//   data_->loaderClient->setWebView(web_view);
//   RefPtr<WebCore::Frame> frame = WebCore::Frame::create(data_->page, data_->ownerElement,
//                                                         data_->loaderClient);
//   // We don't keep the reference to the Frame, see WebFramePrivate.h.
//   m_coreFrame = frame.get();

//   // I'm not sure this is a right place to setFrame
//   // But necessary.
//   data_->loaderClient->setFrame(m_coreFrame);

//   if (parent_frame) {
//     parent_frame->Frame()->tree()->appendChild(m_coreFrame);
//   }
//     m_coreFrame->tree()->setName(data_->name);
//     m_coreFrame->init();
// }

// BWebFrame::BWebFrame(BWebPage* webPage, BWebFrame* parentFrame, WebFramePrivate* data)
//     : fZoomFactor(1.0)
//     , fIsEditable(false)
//     , fTitle(0)
//     , fData(data)
// {
//  fData->loaderClient = new WebCore::FrameLoaderClientMona(webPage, this);
//     RefPtr<WebCore::Frame> frame = WebCore::Frame::create(fData->page, fData->ownerElement,
//         fData->loaderClient);
//     // We don't keep the reference to the Frame, see WebFramePrivate.h.
//     fData->frame = frame.get();

//     if (parentFrame)
//         parentFrame->Frame()->tree()->appendChild(fData->frame);

//     fData->frame->tree()->setName(fData->name);
//     fData->frame->init();
// }

// BWebFrame::~BWebFrame()
// {
//     delete fData->loaderClient;
//     delete fData;
// }

// void
// BWebFrame::Shutdown()
// {
//  // The private method is only invoked from the FrameLoaderClient, as
//  // no one else keeps track of a BWebFrame object's lifetime, we tie
//  // to the WebCore::Frame/FrameLoader lifetime and shutdown via
//  // the FrameLoaderClient::frameLoaderDestroyed() hook.
//  delete this;
// }

// void BWebFrame::SetListener(const BMessenger& listener)
// {
//     fData->loaderClient->setDispatchTarget(listener);
// }

// void BWebFrame::LoadURL(BString urlString)
// {
//  KURL url;
//     if (BEntry(urlString.String()).Exists()) {
//         url.setProtocol("file");
//         url.setPath(urlString);
//     } else
//      url = KURL(KURL(), urlString.Trim().String());

//  if (!url.protocolInHTTPFamily() && !url.isLocalFile()) {
//      url = KURL();
//      url.setProtocol("http");
//      url.setHostAndPort(urlString);
//  }
//     LoadURL(url);
// }

void WebFrame::LoadURL(const char* url)
{
  ASSERT(url);

  if (!m_coreFrame || !m_coreFrame->loader())
    return;

  data_->requestedURL = url;
  String u(url);
  m_coreFrame->loader()->load(u, false);
}

// void BWebFrame::StopLoading()
// {
//     if (fData->frame && fData->frame->loader())
//         fData->frame->loader()->stop();
// }

// void BWebFrame::Reload()
// {
//     if (fData->frame && fData->frame->loader())
//         fData->frame->loader()->reload();
// }

// BString BWebFrame::URL() const
// {
//     return fData->frame->loader()->url().string();
// }

// BString BWebFrame::RequestedURL() const
// {
//     return fData->requestedURL;
// }

// bool BWebFrame::CanCopy() const
// {
//     if (fData->frame && fData->frame->view())
//         return fData->frame->editor()->canCopy() || fData->frame->editor()->canDHTMLCopy();

//     return false;
// }

// bool BWebFrame::CanCut() const
// {
//     if (fData->frame && fData->frame->view())
//         return fData->frame->editor()->canCut() || fData->frame->editor()->canDHTMLCut();

//     return false;
// }

// bool BWebFrame::CanPaste() const
// {
//     if (fData->frame && fData->frame->view())
//         return fData->frame->editor()->canPaste() || fData->frame->editor()->canDHTMLPaste();

//     return false;
// }

// void BWebFrame::Copy()
// {
//     if (CanCopy())
//         fData->frame->editor()->copy();
// }

// void BWebFrame::Cut()
// {
//     if (CanCut())
//         fData->frame->editor()->cut();
// }

// void BWebFrame::Paste()
// {
//     if (CanPaste())
//         fData->frame->editor()->paste();
// }

// bool BWebFrame::CanUndo() const
// {
//     if (fData->frame && fData->frame->editor())
//         return fData->frame->editor()->canUndo();

//     return false;
// }

// bool BWebFrame::CanRedo() const
// {
//     if (fData->frame && fData->frame->editor())
//         return fData->frame->editor()->canRedo();

//     return false;
// }

// void BWebFrame::Undo()
// {
//     if (CanUndo())
//         return fData->frame->editor()->undo();
// }

// void BWebFrame::Redo()
// {
//     if (CanRedo())
//         return fData->frame->editor()->redo();
// }

// bool BWebFrame::AllowsScrolling() const
// {
//     if (fData->frame && fData->frame->view())
//         return fData->frame->view()->canHaveScrollbars();

//     return false;
// }

// void BWebFrame::SetAllowsScrolling(bool flag)
// {
//     if (fData->frame && fData->frame->view())
//         fData->frame->view()->setCanHaveScrollbars(flag);
// }

// BString BWebFrame::FrameSource() const
// {
//     if (fData->frame) {
//         if (fData->frame->view() && fData->frame->view()->layoutPending())
//             fData->frame->view()->layout();

//         WebCore::Document* document = fData->frame->document();

//         if (document)
//             return BString(createMarkup(document));
//     }

//     return BString();
// }

// void BWebFrame::SetFrameSource(const BString& source)
// {
//     if (fData->frame && fData->frame->loader()) {
//         WebCore::FrameLoader* loader = fData->frame->loader();
//         loader->begin();
//         loader->write(String(source));
//         loader->end();
//     }
// }

// void BWebFrame::SetTransparent(bool transparent)
// {
//     if (fData->frame && fData->frame->view())
//         fData->frame->view()->setTransparent(transparent);
// }

bool WebFrame::IsTransparent() const
{
  if (m_coreFrame && m_coreFrame->view()) {
    return m_coreFrame->view()->isTransparent();
  }
  return false;
}

// BString BWebFrame::InnerText() const
// {
//     FrameView* view = fData->frame->view();

//     if (view && view->layoutPending())
//         view->layout();

//     WebCore::Element *documentElement = fData->frame->document()->documentElement();
//     return documentElement->innerText();
// }

// BString BWebFrame::AsMarkup() const
// {
//     if (!fData->frame->document())
//         return BString();

//     return createMarkup(fData->frame->document());
// }

// BString BWebFrame::ExternalRepresentation() const
// {
//     FrameView* view = fData->frame->view();

//     if (view && view->layoutPending())
//         view->layout();

//     return externalRepresentation(fData->frame);
// }

// bool BWebFrame::FindString(const char* string, bool forward, bool caseSensitive, bool wrapSelection, bool startInSelection)
// {
//     if (fData->frame)
//         return fData->frame->findString(string, forward, caseSensitive, wrapSelection, startInSelection);

//     return false;
// }

// bool BWebFrame::CanIncreaseZoomFactor() const
// {
//     if (fData->frame)
//         if (fZoomFactor * kZoomFactorMultiplierRatio <= kMaximumZoomFactorMultiplier)
//             return true;

//     return false;
// }

// bool BWebFrame::CanDecreaseZoomFactor() const
// {
//     if (fData->frame)
//         return fZoomFactor / kZoomFactorMultiplierRatio >= kMinimumZoomFactorMultiplier;

//     return false;
// }

// void BWebFrame::IncreaseZoomFactor(bool textOnly)
// {
//     if (CanIncreaseZoomFactor()) {
//         fZoomFactor = fZoomFactor * kZoomFactorMultiplierRatio;
//         fData->frame->setZoomFactor(fZoomFactor, textOnly ? ZoomTextOnly : ZoomPage);
//     }
// }

// void BWebFrame::DecreaseZoomFactor(bool textOnly)
// {
//     if (CanDecreaseZoomFactor()) {
//         fZoomFactor = fZoomFactor / kZoomFactorMultiplierRatio;
//         fData->frame->setZoomFactor(fZoomFactor, textOnly ? ZoomTextOnly : ZoomPage);
//     }
// }

// void BWebFrame::ResetZoomFactor()
// {
//     if (fZoomFactor == 1)
//         return;

//     fZoomFactor = 1;

//     if (fData->frame)
//         fData->frame->setZoomFactor(fZoomFactor, ZoomPage);
// }

// void BWebFrame::SetEditable(bool editable)
// {
//     fIsEditable = editable;
// }

// bool BWebFrame::IsEditable() const
// {
//     return fIsEditable;
// }

// void BWebFrame::SetTitle(const BString& title)
// {
//  if (fTitle == title)
//      return;

//     fTitle = title;
// }

// const BString& BWebFrame::Title() const
// {
//     return fTitle;
// }

// // #pragma mark - private

WebCore::Frame* WebFrame::Frame() const
{
    return m_coreFrame;
}
