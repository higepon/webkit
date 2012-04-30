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

bool WebFrame::IsTransparent() const
{
  if (m_coreFrame && m_coreFrame->view()) {
    return m_coreFrame->view()->isTransparent();
  }
  return false;
}
