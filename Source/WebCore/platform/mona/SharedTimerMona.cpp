/*
 * Copyright (C) 2009 Maxime Simon <simon.maxime@gmail.com>
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
#include "SharedTimer.h"
#include "notImplemented.h"
#include <wtf/CurrentTime.h>
#include <monapi.h>

enum {
  MSG_WEBKIT_SET_TIMER_FUNC = 0x4000,
  MSG_WEBKIT_SET_TIMER_INTERVAL,
  MSG_WEBKIT_STOP_TIMER
};

void (*SharedTimerFiredFunction)() = NULL;

namespace WebCore {

static const uint32_t UNUSED_TIMER = 0xffffffff;
static uint32_t timerId = UNUSED_TIMER;


void setSharedTimerFiredFunction(void (*f)()) {
  SharedTimerFiredFunction = f;
}

void setSharedTimerFireInterval(double interval) {
  uint32_t intervalMsec = interval * 1000;
  if (timerId != UNUSED_TIMER) {
    stopSharedTimer();
  }
  intervalMsec = intervalMsec < 10 ? 10 : intervalMsec;
  timerId = set_timer(intervalMsec);
}

void stopSharedTimer() {
  if (timerId != UNUSED_TIMER) {
    kill_timer(timerId);
    //    SharedTimerFiredFunction = NULL;
    timerId = UNUSED_TIMER;
  }
}


// static void (*f)() = NULL;
// static uint32_t timerId = 0xffffffff;

// static void setInterval(uint32_t msec) {
//   timerId = set_timer(msec);
// }

// static void stopTimer() {
//   if (timerId != 0xffffffff) {
//     kill_timer(timerId);
//     timerId = 0xffffffff;
//   }
// }

// static void setFunc(void (*func)()) {
//   f = func;
// }

// static void __fastcall timerLoop(void* arg) {
//   if (monapi_name_add("/servers/webkit_timer") != M_OK) {
//     monapi_fatal("monapi_name_add failed");
//   }
//   for (;;) {
//     MessageInfo msg;
//     if (MonAPI::Message::receive(&msg) != M_OK) {
//       continue;
//     }
//     switch (msg.header) {
//       case MSG_WEBKIT_SET_TIMER_FUNC:
//         setFunc((void (*)())msg.arg1);
//         MonAPI::Message::reply(&msg, M_OK);
//         break;
//       case MSG_WEBKIT_SET_TIMER_INTERVAL:
//       {

//   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//         uint32_t interval = msg.arg1;
//         setInterval(interval);
//         _logprintf("%s %s:%d interval=%d\n", __func__, __FILE__, __LINE__, interval);
//         MonAPI::Message::reply(&msg, M_OK);
//         break;
//       }
//       case MSG_WEBKIT_STOP_TIMER:
//         stopTimer();
//         MonAPI::Message::reply(&msg, M_OK);
//   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//         break;
//       case MSG_TIMER:
//         //        ASSERT(timerId != 0xffffffff);
//         if (f) {
//           _logprintf("before call timer %s %s:%d\n", __func__, __FILE__, __LINE__);
//           f();
//           _logprintf("after call timer %s %s:%d\n", __func__, __FILE__, __LINE__);
//         }
//         break;
//       default:
//         break;
//     }
//   }
// }

// static uint32_t createOrFindTimerThread() {
//   uint32_t tid;
//   if (monapi_name_whereis("/servers/webkit_timer", tid) == M_OK) {
//     return tid;
//   } else {
//     monapi_thread_create_with_arg(timerLoop, NULL);
//     while (monapi_name_whereis("/servers/webkit_timer", tid) != M_OK) {
//       sleep(100);
//     }
//     return tid;
//   }
// }


// // WebCore functions
// void setSharedTimerFiredFunction(void (*f)())
// {
//   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//   uint32_t tid = createOrFindTimerThread();
//   // recursive call
//   if (MonAPI::System::getThreadID() == tid) {
//     setFunc(f);
//   } else {
//     MessageInfo dest;
//     if (MonAPI::Message::sendReceive(&dest, tid, MSG_WEBKIT_SET_TIMER_FUNC, (uint32_t)f) != M_OK) {
//       monapi_fatal("");
//     }
//     if (dest.arg2 != M_OK) {
//       monapi_fatal("");
//     }
//   }
// }

// void setSharedTimerFireInterval(double interval)
// {
//   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//   uint32_t tid = createOrFindTimerThread();
//   _logprintf("%s %s:%d tid=%x\n", __func__, __FILE__, __LINE__, tid);
//   // recursive call
//   if (MonAPI::System::getThreadID() == tid) {
//     setInterval(interval * 1000);
//   } else {
//     MessageInfo dest;
//     _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//     if (MonAPI::Message::sendReceive(&dest, tid, MSG_WEBKIT_SET_TIMER_INTERVAL, (uint32_t)(interval * 1000)) != M_OK) {
//       _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//       monapi_fatal("");
//     }
//     _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//     if (dest.arg2 != M_OK) {
//       monapi_fatal("");
//     }
//   }
//   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
// }

// void stopSharedTimer()
// {
//   uint32_t tid = createOrFindTimerThread();
//   if (MonAPI::System::getThreadID() == tid) {
//     stopTimer();
//   } else {
//     _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//     MessageInfo dest;
//     if (MonAPI::Message::sendReceive(&dest, tid, MSG_WEBKIT_STOP_TIMER) != M_OK) {
//       monapi_fatal("");
//     }
//     if (dest.arg2 != M_OK) {
//       monapi_fatal("");
//     }
//   }
// }

} // namespace WebCore
