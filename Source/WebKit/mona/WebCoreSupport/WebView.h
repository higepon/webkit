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
#ifndef _WEB_VIEW_H_
#define _WEB_VIEW_H_

#define assert(...) /* */
//#include <assert.h>
#include <monagui.h>
#include <IntRect.h>
#include <KURL.h>

namespace WebCore {

class WebPage;

#define WEBVIEW_WIDTH 900
#define WEBVIEW_HEIGHT 480

class WebCanvas : public Canvas {
 public:
  WebCanvas(WebPage* web_page) : web_page_(web_page), image_buffer_(NULL) {
  }

  virtual ~WebCanvas() {
  }

  void paint(Graphics* g) {
    if (image_buffer_ == NULL) {
      return;
    }
    const Rectangle rect = g->getClipBound();
    int xmax = rect.x + rect.width;
    int ymax = rect.y + rect.height;

    for (int j = rect.y; j < ymax; j++) {
      for (int i = rect.x; i < xmax; i++) {
        g->drawPixel(i, j, ((uint32_t*)(image_buffer_))[i + j * getWidth()]);
      }
    }
  }

  void processEvent(monagui::Event* event);

  void SetImageBuffer(unsigned char* p) {
    image_buffer_ = p;
  }
 private:
  WebPage* web_page_;
  unsigned char* image_buffer_;
};

class WebView : public monagui::Frame {
 public:
  WebView();
  virtual ~WebView();
  void processEvent(monagui::Event* event);
  void SetStatus(const std::string& text);
  WebPage* webPage() {
      return web_page_;
  }

  void LoadURL(const char* urlString, bool aquireFocus = true);

  void Repaint(const IntRect& rect);
  
  void SetImageBuffer(unsigned char* p) {
    canvas_->SetImageBuffer(p);
  }

 private:
  IntRect MergeRepaintRequest(int x, int y, int w, int h);
  WebPage* web_page_;

  MonAPI::scoped_ptr<Label> status_;
  IntRect currentRect_;
  MonAPI::scoped_ptr<WebCanvas> canvas_;
};
};

#endif // _WEB_VIEW_H_
