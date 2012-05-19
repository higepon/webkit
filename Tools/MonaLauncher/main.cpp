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
  intptr_t ret = monapi_enable_stacktrace("/APPS/MLAUNCH.map");
  if (ret != M_OK) {
    monapi_fatal("syscall_stack_trace_enable failed%d\n", ret);
  }
  JSC::initializeThreading();
  WTF::initializeMainThread();

  WebCore::WebView web_view;
#if 1
  const char* url = "http://myhost/hoge.html";
#elif 0
  const char* url = "https://mail.google.com/";
#elif 0
  const char* url = "http://www.google.com/";
#elif 0
  const char* url = "http://www.facebook.com/";
#elif 0
  const char* url = "http://www.flickr.com/search/?q=animals&f=hp";
#elif 0
  const char* url = "http://www.monaos.org/";
#elif 0
  const char* url = "http://localhost.twitter.com:3000/";
#elif 0
  const char* url = "https://twitter.com/";
#endif
  web_view.LoadURL(url);
}
