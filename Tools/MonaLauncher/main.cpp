/*
 *   Copyright (c) 2011  Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>r
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT2
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <assert.h>
#include <config.h>
#include <Page.h>
#include <Frame.h>
#include "FrameLoaderClientMona.h"
#include "ChromeClientMona.h"
#include "ContextMenuClientMona.h"
#include "EditorClientMona.h"
#include "DragClientMona.h"
#include "InspectorClientMona.h"
#include "InitializeThreading.h"
#include "WebView.h"

extern void (*SharedTimerFiredFunction)();


int main(int argc, char* argv[]) {
  _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  intptr_t ret = monapi_enable_stacktrace("/APPS/MLAUNCH.map");
  _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  if (ret != M_OK) {
    monapi_fatal("syscall_stack_trace_enable failed%d\n", ret);
  }
  _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  JSC::initializeThreading();
  WTF::initializeMainThread();

  _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  // MonaLauncher app("http://10.0.2.2/");
  // app.run();
  WebCore::WebView web_view;
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //web_view.LoadURL("https://mail.google.com/");
        web_view.LoadURL("http://www.google.com/");
  //  web_view.LoadURL("http://www.bing.com/");
  //     web_view.LoadURL("http://www.facebook.com/");
  //   web_view.LoadURL("http://youtube.com/");
  ///////////web_view.LoadURL("http://www.monaos.org/");
  //web_view.LoadURL("http://10.0.2.2/f.html");
  //web_view.LoadURL("http://10.0.2.2/");

  //  web_view.LoadURL("http://10.0.2.2/~taro/f.html");
      web_view.LoadURL("http://10.0.2.2/input.html");
  //  web_view.LoadURL("http://twitter.com/");
  // //  web_view.LoadURL("file://hige.txt/");
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
}
