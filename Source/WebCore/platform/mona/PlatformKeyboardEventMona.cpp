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
#include "WindowsKeyboardCodes.h"
#define assert(x) /* */
#include <monagui.h>

namespace WebCore {

PlatformKeyboardEvent::PlatformKeyboardEvent(monagui::KeyEvent* evt) :
    m_monaKeyEvent(evt),
    m_type(evt->getType() == monagui::Event::KEY_PRESSED ? KeyDown : KeyUp), // FIXME Char should be here?
    m_text(singleCharacterString(evt->getKeycode())),
    m_unmodifiedText(m_text), // FIXME
    m_autoRepeat(false), // FIXME
    m_windowsVirtualKeyCode(windowsKeyCodeForMonaGuiKeyCode(evt->getKeycode())),
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

int PlatformKeyboardEvent::windowsKeyCodeForMonaGuiKeyCode(unsigned keycode)
{
    switch (keycode) {
        // case GDK_KP_0:
        //     return VK_NUMPAD0;// (60) Numeric keypad 0 key
        // case GDK_KP_1:
        //     return VK_NUMPAD1;// (61) Numeric keypad 1 key
        // case GDK_KP_2:
        //     return  VK_NUMPAD2; // (62) Numeric keypad 2 key
        // case GDK_KP_3:
        //     return VK_NUMPAD3; // (63) Numeric keypad 3 key
        // case GDK_KP_4:
        //     return VK_NUMPAD4; // (64) Numeric keypad 4 key
        // case GDK_KP_5:
        //     return VK_NUMPAD5; //(65) Numeric keypad 5 key
        // case GDK_KP_6:
        //     return VK_NUMPAD6; // (66) Numeric keypad 6 key
        // case GDK_KP_7:
        //     return VK_NUMPAD7; // (67) Numeric keypad 7 key
        // case GDK_KP_8:
        //     return VK_NUMPAD8; // (68) Numeric keypad 8 key
        // case GDK_KP_9:
        //     return VK_NUMPAD9; // (69) Numeric keypad 9 key
        // case GDK_KP_Multiply:
        //     return VK_MULTIPLY; // (6A) Multiply key
        // case GDK_KP_Add:
        //     return VK_ADD; // (6B) Add key
        // case GDK_KP_Subtract:
        //     return VK_SUBTRACT; // (6D) Subtract key
        // case GDK_KP_Decimal:
        //     return VK_DECIMAL; // (6E) Decimal key
        // case GDK_KP_Divide:
        //     return VK_DIVIDE; // (6F) Divide key

        // case GDK_KP_Page_Up:
        //     return VK_PRIOR; // (21) PAGE UP key
        // case GDK_KP_Page_Down:
        //     return VK_NEXT; // (22) PAGE DOWN key
        // case GDK_KP_End:
        //     return VK_END; // (23) END key
        // case GDK_KP_Home:
        //     return VK_HOME; // (24) HOME key
        // case GDK_KP_Left:
        //     return VK_LEFT; // (25) LEFT ARROW key
        // case GDK_KP_Up:
        //     return VK_UP; // (26) UP ARROW key
        // case GDK_KP_Right:
        //     return VK_RIGHT; // (27) RIGHT ARROW key
        // case GDK_KP_Down:
        //     return VK_DOWN; // (28) DOWN ARROW key

        case monagui::KeyEvent::VKEY_BACKSPACE:
            return VK_BACK; // (08) BACKSPACE key
        // case monagui::KeyEvent::VKEY_ISO_Left_Tab:
        // case monagui::KeyEvent::VKEY_3270_BackTab:
        case monagui::KeyEvent::VKEY_TAB:
            return VK_TAB; // (09) TAB key
        // case monagui::KeyEvent::VKEY_Clear:
        //     return VK_CLEAR; // (0C) CLEAR key
        // case monagui::KeyEvent::VKEY_ISO_Enter:
        // case monagui::KeyEvent::VKEY_KP_Enter:
        case monagui::KeyEvent::VKEY_ENTER:
            return VK_RETURN; //(0D) Return key
        case monagui::KeyEvent::VKEY_LSHIFT:
        case monagui::KeyEvent::VKEY_RSHIFT:
            return VK_SHIFT; // (10) SHIFT key
        case monagui::KeyEvent::VKEY_CTRL:
          //        case monagui::KeyEvent::VKEY_Control_R:
            return VK_CONTROL; // (11) CTRL key
        // case monagui::KeyEvent::VKEY_Menu:
        //     return VK_APPS;  // (5D) Applications key (Natural keyboard)
        case monagui::KeyEvent::VKEY_ALT:
        // case monagui::KeyEvent::VKEY_Alt_R:
            return VK_MENU; // (12) ALT key

        // case monagui::KeyEvent::VKEY_Pause:
        //     return VK_PAUSE; // (13) PAUSE key
        // case monagui::KeyEvent::VKEY_Caps_Lock:
        //     return VK_CAPITAL; // (14) CAPS LOCK key
        // case monagui::KeyEvent::VKEY_Kana_Lock:
        // case monagui::KeyEvent::VKEY_Kana_Shift:
        //     return VK_KANA; // (15) Input Method Editor (IME) Kana mode
        // case monagui::KeyEvent::VKEY_Hangul:
        //     return VK_HANGUL; // VK_HANGUL (15) IME Hangul mode
        //     // VK_JUNJA (17) IME Junja mode
        //     // VK_FINAL (18) IME final mode
        // case monagui::KeyEvent::VKEY_Hangul_Hanja:
        //     return VK_HANJA; // (19) IME Hanja mode
        // case monagui::KeyEvent::VKEY_Kanji:
        //     return VK_KANJI; // (19) IME Kanji mode
        case monagui::KeyEvent::VKEY_ESC:
            return VK_ESCAPE; // (1B) ESC key
            // VK_CONVERT (1C) IME convert
            // VK_NONCONVERT (1D) IME nonconvert
            // VK_ACCEPT (1E) IME accept
            // VK_MODECHANGE (1F) IME mode change request
        case ' ':
            return VK_SPACE; // (20) SPACEBAR
        case monagui::KeyEvent::VKEY_PGUP:
            return VK_PRIOR; // (21) PAGE UP key
        case monagui::KeyEvent::VKEY_PGDOWN:
            return VK_NEXT; // (22) PAGE DOWN key
        case monagui::KeyEvent::VKEY_END:
            return VK_END; // (23) END key
        case monagui::KeyEvent::VKEY_HOME:
            return VK_HOME; // (24) HOME key
        case monagui::KeyEvent::VKEY_LEFT:
            return VK_LEFT; // (25) LEFT ARROW key
        case monagui::KeyEvent::VKEY_UP:
            return VK_UP; // (26) UP ARROW key
        case monagui::KeyEvent::VKEY_RIGHT:
            return VK_RIGHT; // (27) RIGHT ARROW key
        case monagui::KeyEvent::VKEY_DOWN:
            return VK_DOWN; // (28) DOWN ARROW key
        // case monagui::KeyEvent::VKEY_Select:
        //     return VK_SELECT; // (29) SELECT key
        // case monagui::KeyEvent::VKEY_Print:
        //     return VK_SNAPSHOT; // (2C) PRINT SCREEN key
        // case monagui::KeyEvent::VKEY_Execute:
        //     return VK_EXECUTE;// (2B) EXECUTE key
        case monagui::KeyEvent::VKEY_INSERT:
          //        case monagui::KeyEvent::VKEY_KP_Insert:
            return VK_INSERT; // (2D) INS key
        // case monagui::KeyEvent::VKEY_BACKSPACE:
        //   //        case monagui::KeyEvent::VKEY_KP_Delete:
        //     return VK_DELETE; // (2E) DEL key
        // case monagui::KeyEvent::VKEY_Help:
        //     return VK_HELP; // (2F) HELP key
        case '0':
        case ')':
            return VK_0;    //  (30) 0) key
        case '1':
        case '!':
            return VK_1; //  (31) 1 ! key
        case '2':
        case '@':
            return VK_2; //  (32) 2 & key
        case '3':
        case '#':
            return VK_3; //case '3'': case '#';
        case '4':
        case '$': //  (34) 4 key '$';
            return VK_4;
        case '5':
        case '%':
            return VK_5; //  (35) 5 key  '%'
        case '6':
        case '^':
            return VK_6; //  (36) 6 key  '^'
        case '7':
        case '&':
            return VK_7; //  (37) 7 key  case '&'
        case '8':
        case '*':
            return VK_8; //  (38) 8 key  '*'
        case '9':
        case '(':
            return VK_9; //  (39) 9 key '('
        case 'a':
        case 'A':
            return VK_A; //  (41) A key case 'a'': case 'A'': return 0x41;
        case 'b':
        case 'B':
            return VK_B; //  (42) B key case 'b'': case 'B'': return 0x42;
        case 'c':
        case 'C':
            return VK_C; //  (43) C key case 'c'': case 'C'': return 0x43;
        case 'd':
        case 'D':
            return VK_D; //  (44) D key case 'd'': case 'D'': return 0x44;
        case 'e':
        case 'E':
            return VK_E; //  (45) E key case 'e'': case 'E'': return 0x45;
        case 'f':
        case 'F':
            return VK_F; //  (46) F key case 'f'': case 'F'': return 0x46;
        case 'g':
        case 'G':
            return VK_G; //  (47) G key case 'g'': case 'G'': return 0x47;
        case 'h':
        case 'H':
            return VK_H; //  (48) H key case 'h'': case 'H'': return 0x48;
        case 'i':
        case 'I':
            return VK_I; //  (49) I key case 'i'': case 'I'': return 0x49;
        case 'j':
        case 'J':
            return VK_J; //  (4A) J key case 'j'': case 'J'': return 0x4A;
        case 'k':
        case 'K':
            return VK_K; //  (4B) K key case 'k'': case 'K'': return 0x4B;
        case 'l':
        case 'L':
            return VK_L; //  (4C) L key case 'l'': case 'L'': return 0x4C;
        case 'm':
        case 'M':
            return VK_M; //  (4D) M key case 'm'': case 'M'': return 0x4D;
        case 'n':
        case 'N':
            return VK_N; //  (4E) N key case 'n'': case 'N'': return 0x4E;
        case 'o':
        case 'O':
            return VK_O; //  (4F) O key case 'o'': case 'O'': return 0x4F;
        case 'p':
        case 'P':
            return VK_P; //  (50) P key case 'p'': case 'P'': return 0x50;
        case 'q':
        case 'Q':
            return VK_Q; //  (51) Q key case 'q'': case 'Q'': return 0x51;
        case 'r':
        case 'R':
            return VK_R; //  (52) R key case 'r'': case 'R'': return 0x52;
        case 's':
        case 'S':
            return VK_S; //  (53) S key case 's'': case 'S'': return 0x53;
        case 't':
        case 'T':
            return VK_T; //  (54) T key case 't'': case 'T'': return 0x54;
        case 'u':
        case 'U':
            return VK_U; //  (55) U key case 'u'': case 'U'': return 0x55;
        case 'v':
        case 'V':
            return VK_V; //  (56) V key case 'v'': case 'V'': return 0x56;
        case 'w':
        case 'W':
            return VK_W; //  (57) W key case 'w'': case 'W'': return 0x57;
        case 'x':
        case 'X':
            return VK_X; //  (58) X key case 'x'': case 'X'': return 0x58;
        case 'y':
        case 'Y':
            return VK_Y; //  (59) Y key case 'y'': case 'Y'': return 0x59;
        case 'z':
        case 'Z':
            return VK_Z; //  (5A) Z key case 'z': case 'Z': return 0x5A;
        // case monagui::KeyEvent::VKEY_Meta_L:
        //     return VK_LWIN; // (5B) Left Windows key (Microsoft Natural keyboard)
        // case monagui::KeyEvent::VKEY_Meta_R:
        //     return VK_RWIN; // (5C) Right Windows key (Natural keyboard)
        //     // VK_SLEEP (5F) Computer Sleep key
        //     // VK_SEPARATOR (6C) Separator key
        //     // VK_SUBTRACT (6D) Subtract key
        //     // VK_DECIMAL (6E) Decimal key
        //     // VK_DIVIDE (6F) Divide key
        //     // handled by key code above

        // case monagui::KeyEvent::VKEY_Num_Lock:
        //     return VK_NUMLOCK; // (90) NUM LOCK key

        // case monagui::KeyEvent::VKEY_Scroll_Lock:
        //     return VK_SCROLL; // (91) SCROLL LOCK key

            // VK_LSHIFT (A0) Left SHIFT key
            // VK_RSHIFT (A1) Right SHIFT key
            // VK_LCONTROL (A2) Left CONTROL key
            // VK_RCONTROL (A3) Right CONTROL key
            // VK_LMENU (A4) Left MENU key
            // VK_RMENU (A5) Right MENU key
            // VK_BROWSER_BACK (A6) Windows 2000/XP: Browser Back key
            // VK_BROWSER_FORWARD (A7) Windows 2000/XP: Browser Forward key
            // VK_BROWSER_REFRESH (A8) Windows 2000/XP: Browser Refresh key
            // VK_BROWSER_STOP (A9) Windows 2000/XP: Browser Stop key
            // VK_BROWSER_SEARCH (AA) Windows 2000/XP: Browser Search key
            // VK_BROWSER_FAVORITES (AB) Windows 2000/XP: Browser Favorites key
            // VK_BROWSER_HOME (AC) Windows 2000/XP: Browser Start and Home key
            // VK_VOLUME_MUTE (AD) Windows 2000/XP: Volume Mute key
            // VK_VOLUME_DOWN (AE) Windows 2000/XP: Volume Down key
            // VK_VOLUME_UP (AF) Windows 2000/XP: Volume Up key
            // VK_MEDIA_NEXT_TRACK (B0) Windows 2000/XP: Next Track key
            // VK_MEDIA_PREV_TRACK (B1) Windows 2000/XP: Previous Track key
            // VK_MEDIA_STOP (B2) Windows 2000/XP: Stop Media key
            // VK_MEDIA_PLAY_PAUSE (B3) Windows 2000/XP: Play/Pause Media key
            // VK_LAUNCH_MAIL (B4) Windows 2000/XP: Start Mail key
            // VK_LAUNCH_MEDIA_SELECT (B5) Windows 2000/XP: Select Media key
            // VK_LAUNCH_APP1 (B6) Windows 2000/XP: Start Application 1 key
            // VK_LAUNCH_APP2 (B7) Windows 2000/XP: Start Application 2 key

        //     // VK_OEM_1 (BA) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ';:' key
        // case monagui::KeyEvent::VKEY_semicolon:
        // case monagui::KeyEvent::VKEY_colon:
        //     return VK_OEM_1; //case ';': case ':': return 0xBA;
        //     // VK_OEM_PLUS (BB) Windows 2000/XP: For any country/region, the '+' key
        // case monagui::KeyEvent::VKEY_plus:
        // case monagui::KeyEvent::VKEY_equal:
        //     return VK_OEM_PLUS; //case '=': case '+': return 0xBB;
        //     // VK_OEM_COMMA (BC) Windows 2000/XP: For any country/region, the ',' key
        // case monagui::KeyEvent::VKEY_comma:
        // case monagui::KeyEvent::VKEY_less:
        //     return VK_OEM_COMMA; //case ',': case '<': return 0xBC;
        //     // VK_OEM_MINUS (BD) Windows 2000/XP: For any country/region, the '-' key
        // case monagui::KeyEvent::VKEY_minus:
        // case monagui::KeyEvent::VKEY_underscore:
        //     return VK_OEM_MINUS; //case '-': case '_': return 0xBD;
        //     // VK_OEM_PERIOD (BE) Windows 2000/XP: For any country/region, the '.' key
        // case monagui::KeyEvent::VKEY_period:
        // case monagui::KeyEvent::VKEY_greater:
        //     return VK_OEM_PERIOD; //case '.': case '>': return 0xBE;
            // VK_OEM_2 (BF) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '/?' key
        // case monagui::KeyEvent::VKEY_slash:
        // case monagui::KeyEvent::VKEY_question:
        //     return VK_OEM_2; //case '/': case '?': return 0xBF;
        //     // VK_OEM_3 (C0) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '`~' key
        // case monagui::KeyEvent::VKEY_asciitilde:
        // case monagui::KeyEvent::VKEY_quoteleft:
        //     return VK_OEM_3; //case '`': case '~': return 0xC0;
        //     // VK_OEM_4 (DB) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '[{' key
        // case monagui::KeyEvent::VKEY_bracketleft:
        // case monagui::KeyEvent::VKEY_braceleft:
        //     return VK_OEM_4; //case '[': case '{': return 0xDB;
        //     // VK_OEM_5 (DC) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the '\|' key
        // case monagui::KeyEvent::VKEY_backslash:
        // case monagui::KeyEvent::VKEY_bar:
        //     return VK_OEM_5; //case '\\': case '|': return 0xDC;
        //     // VK_OEM_6 (DD) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the ']}' key
        // case monagui::KeyEvent::VKEY_bracketright:
        // case monagui::KeyEvent::VKEY_braceright:
        //     return VK_OEM_6; // case ']': case '}': return 0xDD;
        //     // VK_OEM_7 (DE) Used for miscellaneous characters; it can vary by keyboard. Windows 2000/XP: For the US standard keyboard, the 'single-quote/double-quote' key
        // case monagui::KeyEvent::VKEY_quoteright:
        // case monagui::KeyEvent::VKEY_quotedbl:
        //     return VK_OEM_7; // case '\'': case '"': return 0xDE;
            // VK_OEM_8 (DF) Used for miscellaneous characters; it can vary by keyboard.
            // VK_OEM_102 (E2) Windows 2000/XP: Either the angle bracket key or the backslash key on the RT 102-key keyboard
            // VK_PROCESSKEY (E5) Windows 95/98/Me, Windows NT 4.0, Windows 2000/XP: IME PROCESS key
            // VK_PACKET (E7) Windows 2000/XP: Used to pass Unicode characters as if they were keystrokes. The VK_PACKET key is the low word of a 32-bit Virtual Key value used for non-keyboard input methods. For more information, see Remark in KEYBDINPUT,SendInput, WM_KEYDOWN, and WM_KEYUP
            // VK_ATTN (F6) Attn key
            // VK_CRSEL (F7) CrSel key
            // VK_EXSEL (F8) ExSel key
            // VK_EREOF (F9) Erase EOF key
            // VK_PLAY (FA) Play key
            // VK_ZOOM (FB) Zoom key
            // VK_NONAME (FC) Reserved for future use
            // VK_PA1 (FD) PA1 key
            // VK_OEM_CLEAR (FE) Clear key
        case monagui::KeyEvent::VKEY_F1:
        case monagui::KeyEvent::VKEY_F2:
        case monagui::KeyEvent::VKEY_F3:
        case monagui::KeyEvent::VKEY_F4:
        case monagui::KeyEvent::VKEY_F5:
        case monagui::KeyEvent::VKEY_F6:
        case monagui::KeyEvent::VKEY_F7:
        case monagui::KeyEvent::VKEY_F8:
        case monagui::KeyEvent::VKEY_F9:
        case monagui::KeyEvent::VKEY_F10:
        case monagui::KeyEvent::VKEY_F11:
        case monagui::KeyEvent::VKEY_F12:
        // case monagui::KeyEvent::VKEY_F13:
        // case monagui::KeyEvent::VKEY_F14:
        // case monagui::KeyEvent::VKEY_F15:
        // case monagui::KeyEvent::VKEY_F16:
        // case monagui::KeyEvent::VKEY_F17:
        // case monagui::KeyEvent::VKEY_F18:
        // case monagui::KeyEvent::VKEY_F19:
        // case monagui::KeyEvent::VKEY_F20:
        // case monagui::KeyEvent::VKEY_F21:
        // case monagui::KeyEvent::VKEY_F22:
        // case monagui::KeyEvent::VKEY_F23:
        // case monagui::KeyEvent::VKEY_F24:
            return VK_F1 + (keycode - monagui::KeyEvent::VKEY_F1);

        default:
            return 0;
    }

}

void PlatformKeyboardEvent::disambiguateKeyDownEvent(Type type, bool backwardCompatibilityMode)
{
    // Can only change type from KeyDown to RawKeyDown or Char, as we lack information for other conversions.
    ASSERT(m_type == KeyDown);
    m_type = type;

    if (backwardCompatibilityMode)
        return;

    if (type == RawKeyDown) {
        m_text = WTF::String();
        m_unmodifiedText = WTF::String();
    } else {
        m_keyIdentifier = WTF::String();
        m_windowsVirtualKeyCode = 0;
    }
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

