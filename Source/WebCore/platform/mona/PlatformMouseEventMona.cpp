/*
 * Copyright (c) 2012 Higepon(Taro Minowa) <higepon@users.sourceforge.jp>
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
#include "PlatformMouseEvent.h"
#include <monagui.h>

namespace WebCore {

PlatformMouseEvent::PlatformMouseEvent(monagui::MouseEvent* e)
    : m_position(LayoutPoint(e->getX(), e->getY())),
    // , m_globalPosition(message->FindPoint("screen_where"))
      m_clickCount(1),
      m_timestamp(0), // FIXME
      m_shiftKey(false),
      m_ctrlKey(false),
      m_altKey(false),
      m_metaKey(false)
{
  switch(e->getButton()) {
    case MouseEvent::BUTTON_LEFT:
      m_button = LeftButton;
      break;
    case MouseEvent::BUTTON_RIGHT:
      m_button = RightButton;
      break;
    default:
      m_button = MiddleButton;
      break;
  }

  switch(e->getType()) {
    case MouseEvent::MOUSE_PRESSED:
      m_eventType = MouseEventPressed;
      break;
    case MouseEvent::MOUSE_RELEASED:
      m_eventType = MouseEventReleased;
      break;
    case MouseEvent::MOUSE_MOVED:
      m_eventType = MouseEventMoved;
      break;
    default:
      _logprintf("MouseEvent=%d not handled %s %s:%d\n", e->getType(), __func__, __FILE__, __LINE__);
      m_eventType = MouseEventPressed;
      break;
  }
}

} // namespace WebCore
