/*
 * Copyright (C) 2011 Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
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
#include "PlatformKeyboardEvent.h"
#include "NotImplemented.h"
#define assert(x) /* */
#include <monagui.h>

namespace WebCore {

PlatformKeyboardEvent::PlatformKeyboardEvent(monagui::KeyEvent* evt) :
    m_monaKeyEvent(evt),
    m_type(evt->getType() == monagui::Event::KEY_PRESSED ? RawKeyDown : KeyUp), // FIXME Char should be here?
    m_text(singleCharacterString(evt->getKeycode())),
    m_unmodifiedText(m_text), // FIXME
    m_autoRepeat(false), // FIXME
    m_windowsVirtualKeyCode(3),
    m_nativeVirtualKeyCode(evt->getKeycode()),
    m_isKeypad(false),   // FIXME
    m_shiftKey((evt->getModifiers() & monagui::KeyEvent::VKEY_LSHIFT) ||
               (evt->getModifiers() & monagui::KeyEvent::VKEY_RSHIFT)),
    m_ctrlKey(evt->getModifiers() & monagui::KeyEvent::VKEY_CTRL),
    m_altKey(evt->getModifiers() & monagui::KeyEvent::VKEY_ALT),
    m_metaKey(evt->getModifiers() & monagui::KeyEvent::VKEY_ALT) // FIXME
{
}

WTF::String PlatformKeyboardEvent::singleCharacterString(unsigned val)
{
    switch (val) {
      case monagui::KeyEvent::VKEY_ENTER:
        return WTF::String("\r");
      case monagui::KeyEvent::VKEY_BACKSPACE:
        return WTF::String("\x8");
      case monagui::KeyEvent::VKEY_TAB:
        return WTF::String("\t");
      default:
      {
        char buf[2];
        buf[0] = val;
        buf[1] = '\0';
        return WTF::String(buf);
      }
    }
}

void PlatformKeyboardEvent::disambiguateKeyDownEvent(Type type, bool backwardCompatibilityMode)
{
  notImplemented();
}

bool PlatformKeyboardEvent::currentCapsLockState()
{
  notImplemented();
}

void PlatformKeyboardEvent::getCurrentModifierState(bool& shiftKey, bool& ctrlKey, bool& altKey, bool& metaKey)
{
  notImplemented();
}

} // namespace WebCore

