/*
 * Copyright (c) 2011 Higepon(Taro Minowa) <higepon@users.sourceforge.jp>
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
#ifndef _WEB_PAGE_H_
#define _WEB_PAGE_H_

#include <cairo.h>
#include <PassRefPtr.h>
#include <KURL.h>
#include <IntSize.h>

namespace WebCore {

class Page;
class WebFrame;
class WebView;
class IntRect;
class Frame;
class HTMLFrameOwnerElement;
class FrameLoaderClientMona;

class WebPage {
 public:
  WebPage(WebView* web_view, const IntSize& viewSize);
  virtual ~WebPage();
  void Init();
  void LoadURL(const char* urlString);
  void SetStatus(const char* text);
  void paint(const IntRect& rect, bool immediate);
  void paintWithoutLayout(const IntRect& rect, bool immediate);

  WebCore::Page* corePage() const {
    return m_page.get();
  }

  const IntSize& size() const {
    return m_viewSize;
  }

  WebFrame* mainFrame() const {
    return m_mainFrame.get();
  }

  // todo
  bool drawsBackground() const {
    return true;
  }

  // todo
  bool drawsTransparentBackground() const {
    return false;
  }

  WebView* webView() const {
    return web_view_;
  }

 private:
  OwnPtr<WebCore::Page> m_page;
  RefPtr<WebFrame> m_mainFrame;
  WebView* web_view_;
  cairo_surface_t* surface_;
  cairo_t* cairo_;
  IntSize m_viewSize;
};

};

#endif // _WEB_PAGE_H_
