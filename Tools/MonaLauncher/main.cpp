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

#include <curl/curl.h>

#define SOCKET_LOG() { uint64_t x = syscall_now_in_nanosec() / 1000000; _logprintf("[socket] %s %s:%d %d\n", __func__, __FILE__, __LINE__, (unsigned int)x);}
#define SOCKET_LOGF(...) { uint64_t x = syscall_now_in_nanosec() / 1000000; _logprintf("[socket] %s %s:%d %d", __func__, __FILE__, __LINE__, (unsigned int)x), _logprintf(__VA_ARGS__); }

static size_t hoge(void* content, size_t size, size_t nmemb, void*hige) {
  return size * nmemb;
}


int main(int argc, char* argv[]) {
#if 0
  CURL* curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    SOCKET_LOG();
    curl_easy_setopt(curl, CURLOPT_URL, "http://myhost/hoge.html");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, hoge);
    SOCKET_LOG();
    res = curl_easy_perform(curl);
    SOCKET_LOG();
    curl_easy_cleanup(curl);
    SOCKET_LOG();
  }

  exit(-1);
#endif
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
  //web_view.LoadURL("https://twitter.com/#!/login/");
  //  web_view.LoadURL("https://mail.google.com/");
  //      web_view.LoadURL("http://www.google.com/");
  //  web_view.LoadURL("http://www.hatena.ne.jp/");
  //  web_view.LoadURL("http://www.bing.com/");
  //web_view.LoadURL("http://www.facebook.com/");
  //  web_view.LoadURL("http://www.flickr.com/search/?q=animals&f=hp");
  //   web_view.LoadURL("http://youtube.com/");
  //web_view.LoadURL("http://www.monaos.org/");
  //web_view.LoadURL("http://10.0.2.2/f.html");
  web_view.LoadURL("http://myhost/hoge.html");
  //  web_view.LoadURL("http://java.sun.com/j2se/1.5.0/ja/docs/ja/api/");
  //  web_view.LoadURL("http://localhost.twitter.com:3000/");

  //  web_view.LoadURL("http://10.0.2.2/~taro/f.html");
  //    web_view.LoadURL("http://10.0.2.2/input.html");
  //    web_view.LoadURL("http://10.0.2.2/twitter.html");
  //      web_view.LoadURL("https://twitter.com/");
  //web_view.LoadURL("http://acid3.acidtests.org/");

  // //  web_view.LoadURL("file://hige.txt/");
  // _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
}
