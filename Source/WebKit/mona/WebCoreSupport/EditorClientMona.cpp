/*
 * Copyright (C) 2006 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2006 Zack Rusin <zack@kde.org>
 * Copyright (C) 2006 Apple Computer, Inc.
 * Copyright (C) 2007 Ryan Leavengood <leavengood@gmail.com>
 * Copyright (C) 2007 Andrea Anzani <andrea.anzani@gmail.com>
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

#include "config.h"
#include "EditorClientMona.h"

#include "Document.h"
#include "Editor.h"
#include "FocusController.h"
#include "Frame.h"
#include "KeyboardEvent.h"
#include "NotImplemented.h"
#include "Page.h"
#include "PlatformKeyboardEvent.h"
#include "WindowsKeyboardCodes.h"
#include "Settings.h"
#define assert(x) /* */
#include <monagui.h>

namespace WebCore {

EditorClientMona::EditorClientMona()
    : m_editing(false)
    , m_inUndoRedo(false)
{
}

void EditorClientMona::setPage(Page* page)
{
    _logprintf("SET_PAGE!!! %s %s:%d\n", __func__, __FILE__, __LINE__);
    m_page = page;
}

void EditorClientMona::pageDestroyed()
{
    notImplemented();
}

bool EditorClientMona::shouldDeleteRange(Range*)
{
    notImplemented();
    return true;
}

bool EditorClientMona::shouldShowDeleteInterface(HTMLElement*)
{
    notImplemented();
    return false;
}

bool EditorClientMona::smartInsertDeleteEnabled()
{
    notImplemented();
    return false;
}

bool EditorClientMona::isSelectTrailingWhitespaceEnabled()
{
    notImplemented();
    return false;
}

bool EditorClientMona::isContinuousSpellCheckingEnabled()
{
    notImplemented();
    return false;
}

void EditorClientMona::toggleContinuousSpellChecking()
{
    notImplemented();
}

bool EditorClientMona::isGrammarCheckingEnabled()
{
    notImplemented();
    return false;
}

void EditorClientMona::toggleGrammarChecking()
{
    notImplemented();
}

int EditorClientMona::spellCheckerDocumentTag()
{
    notImplemented();
    return 0;
}

bool EditorClientMona::shouldBeginEditing(WebCore::Range*)
{
    notImplemented();
    return true;
}

bool EditorClientMona::shouldEndEditing(WebCore::Range*)
{
    notImplemented();
    return true;
}

bool EditorClientMona::shouldInsertNode(Node*, Range*, EditorInsertAction)
{
    notImplemented();
    return true;
}

bool EditorClientMona::shouldInsertText(const WTF::String&, Range*, EditorInsertAction)
{
    notImplemented();
    return true;
}

bool EditorClientMona::shouldChangeSelectedRange(Range* fromRange, Range* toRange,
                                                  EAffinity, bool stillSelecting)
{
    notImplemented();
    return true;
}

bool EditorClientMona::shouldApplyStyle(WebCore::CSSStyleDeclaration*,
                                      WebCore::Range*)
{
    notImplemented();
    return true;
}

bool EditorClientMona::shouldMoveRangeAfterDelete(Range*, Range*)
{
    notImplemented();
    return true;
}

void EditorClientMona::didBeginEditing()
{
    notImplemented();
    m_editing = true;
}

void EditorClientMona::respondToChangedContents()
{
    notImplemented();
}

void EditorClientMona::respondToChangedSelection()
{
    notImplemented();
}

void EditorClientMona::didEndEditing()
{
    notImplemented();
    m_editing = false;
}

void EditorClientMona::didWriteSelectionToPasteboard()
{
    notImplemented();
}

void EditorClientMona::didSetSelectionTypesForPasteboard()
{
    notImplemented();
}

void EditorClientMona::registerCommandForUndo(WTF::PassRefPtr<WebCore::EditCommand> cmd)
{
    notImplemented();
}

void EditorClientMona::registerCommandForRedo(WTF::PassRefPtr<WebCore::EditCommand>)
{
    notImplemented();
}

void EditorClientMona::clearUndoRedoOperations()
{
    notImplemented();
}

bool EditorClientMona::canCopyCut(WebCore::Frame*, bool defaultValue) const
{
    return defaultValue;
}

bool EditorClientMona::canPaste(WebCore::Frame*, bool defaultValue) const
{
    return defaultValue;
}

bool EditorClientMona::canUndo() const
{
    notImplemented();
    return false;
}

bool EditorClientMona::canRedo() const
{
    notImplemented();
    return false;
}

void EditorClientMona::undo()
{
    notImplemented();
    m_inUndoRedo = true;
    m_inUndoRedo = false;
}

void EditorClientMona::redo()
{
    notImplemented();
    m_inUndoRedo = true;
    m_inUndoRedo = false;
}

bool EditorClientMona::handleEditingKeyboardEvent(KeyboardEvent* event)
{
    Node* node = event->target()->toNode();
    ASSERT(node);
    Frame* frame = node->document()->frame();
    ASSERT(frame);

    const PlatformKeyboardEvent* keyEvent = event->keyEvent();
    if (!keyEvent)
        return false;

    bool caretBrowsing = frame->settings()->caretBrowsingEnabled();
    if (caretBrowsing) {
        switch (keyEvent->getKeyEvent()->getKeycode()) {
        case monagui::KeyEvent::VKEY_LEFT:
            frame->selection()->modify(keyEvent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
                    DirectionLeft,
                    keyEvent->ctrlKey() ? WordGranularity : CharacterGranularity,
                    UserTriggered);
            return true;
        case monagui::KeyEvent::VKEY_RIGHT:
            frame->selection()->modify(keyEvent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
                    DirectionRight,
                    keyEvent->ctrlKey() ? WordGranularity : CharacterGranularity,
                    UserTriggered);
            return true;
        case monagui::KeyEvent::VKEY_UP:
            frame->selection()->modify(keyEvent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
                    DirectionBackward,
                    keyEvent->ctrlKey() ? ParagraphGranularity : LineGranularity,
                    UserTriggered);
            return true;
        case monagui::KeyEvent::VKEY_DOWN:
            frame->selection()->modify(keyEvent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
                    DirectionForward,
                    keyEvent->ctrlKey() ? ParagraphGranularity : LineGranularity,
                    UserTriggered);
            return true;
        }
    }

    Editor::Command command = frame->editor()->command(interpretKeyEvent(event));

    if (keyEvent->type() == PlatformKeyboardEvent::RawKeyDown) {
        // WebKit doesn't have enough information about mode to decide how commands that just insert text if executed via Editor should be treated,
        // so we leave it upon WebCore to either handle them immediately (e.g. Tab that changes focus) or let a keypress event be generated
        // (e.g. Tab that inserts a Tab character, or Enter).
        return !command.isTextInsertion() && command.execute(event);
    }

    if (command.execute(event))
        return true;

    // Don't insert null or control characters as they can result in unexpected behaviour
    if (event->charCode() < ' ')
        return false;

    // Don't insert anything if a modifier is pressed
    if (keyEvent->ctrlKey() || keyEvent->altKey())
        return false;

    return frame->editor()->insertText(event->keyEvent()->text(), event);
}
void EditorClientMona::handleKeyboardEvent(KeyboardEvent* event)
{
    if (handleEditingKeyboardEvent(event)) {
        event->setDefaultHandled();
    }
  //   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   _logprintf("%s %s:%d %d\n", __func__, __FILE__, __LINE__, m_page);
  //   _logprintf("%s %s:%d %d\n", __func__, __FILE__, __LINE__, m_page->focusController());
  //   _logprintf("%s %s:%d %d\n", __func__, __FILE__, __LINE__, m_page->focusController()->focusedOrMainFrame());
  //   Frame* frame = m_page->focusController()->focusedOrMainFrame();
  //   _logprintf("frame=%x %x %s %s:%d\n", frame, frame->document()->focusedNode(), __func__, __FILE__, __LINE__);
  //   if (!frame || !frame->document()->focusedNode())
  //       return;
  //   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   const PlatformKeyboardEvent* kevent = event->keyEvent();
  //   if (!kevent || kevent->type() == PlatformKeyboardEvent::KeyUp)
  //       return;
  //   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   Node* start = frame->selection()->start().containerNode();
  //   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   if (!start)
  //       return;
  //   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   _logprintf("delete?=%d\n", kevent->getKeyEvent()->getKeycode() == monagui::KeyEvent::VKEY_BACKSPACE);
  //   _logprintf("tab?=%d\n", kevent->getKeyEvent()->getKeycode() == monagui::KeyEvent::VKEY_TAB);
  //   _logprintf("key=%c %s %s:%d\n", kevent->getKeyEvent()->getKeycode(), __func__, __FILE__, __LINE__);
  //   switch (kevent->getKeyEvent()->getKeycode()) {
  //     case monagui::KeyEvent::VKEY_BACKSPACE:
  //     {
  //       Editor::Command command = frame->editor()->command("DeleteBackward");
  //       command.execute();
  //       return;
  //       break;

  //     }
  //   }
  //   char buf[2];
  //   buf[0] = kevent->getKeyEvent()->getKeycode();
  //   buf[1] = '\0';
  //   frame->editor()->insertText(buf, event);
  //   _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  //   event->setDefaultHandled();
  // notImplemented();
}

void EditorClientMona::handleInputMethodKeydown(KeyboardEvent*)
{
    notImplemented();
}

void EditorClientMona::textFieldDidBeginEditing(Element*)
{
    m_editing = true;
}

void EditorClientMona::textFieldDidEndEditing(Element*)
{
    m_editing = false;
}

void EditorClientMona::textDidChangeInTextField(Element*)
{
    notImplemented();
}

bool EditorClientMona::doTextFieldCommandFromEvent(Element*, KeyboardEvent*)
{
    return false;
}

void EditorClientMona::textWillBeDeletedInTextField(Element*)
{
    notImplemented();
}

void EditorClientMona::textDidChangeInTextArea(Element*)
{
    notImplemented();
}

void EditorClientMona::ignoreWordInSpellDocument(const WTF::String&)
{
    notImplemented();
}

void EditorClientMona::learnWord(const WTF::String&)
{
    notImplemented();
}

void EditorClientMona::checkSpellingOfString(const UChar*, int, int*, int*)
{
    notImplemented();
}

WTF::String EditorClientMona::getAutoCorrectSuggestionForMisspelledWord(const WTF::String& misspelledWord)
{
    notImplemented();
    return WTF::String();
}

void EditorClientMona::checkGrammarOfString(const UChar*, int, WTF::Vector<GrammarDetail>&, int*, int*)
{
    notImplemented();
}

void EditorClientMona::updateSpellingUIWithGrammarString(const WTF::String&, const GrammarDetail&)
{
    notImplemented();
}

void EditorClientMona::updateSpellingUIWithMisspelledWord(const WTF::String&)
{
    notImplemented();
}

void EditorClientMona::showSpellingUI(bool)
{
    notImplemented();
}

bool EditorClientMona::spellingUIIsShowing()
{
    notImplemented();
    return false;
}

void EditorClientMona::getGuessesForWord(const WTF::String& word, const WTF::String& context, WTF::Vector<WTF::String>& guesses)
{
    notImplemented();
}

void EditorClientMona::willSetInputMethodState()
{
    notImplemented();
}

void EditorClientMona::setInputMethodState(bool enabled)
{
    notImplemented();
}

bool EditorClientMona::isEditing() const
{
    return m_editing;
}

struct KeyPressEntry {
    unsigned charCode;
    unsigned modifiers;
    const char* name;
};

static const unsigned CtrlKey  = 1 << 0;
static const unsigned AltKey   = 1 << 1;
static const unsigned ShiftKey = 1 << 2;

struct KeyDownEntry {
    unsigned virtualKey;
    unsigned modifiers;
    const char* name;
};

static const KeyDownEntry keyDownEntries[] = {
    { monagui::KeyEvent::VKEY_LEFT,   0,                  "MoveLeft"                                    },
    { monagui::KeyEvent::VKEY_LEFT,   ShiftKey,           "MoveLeftAndModifySelection"                  },
    { monagui::KeyEvent::VKEY_LEFT,   CtrlKey,            "MoveWordLeft"                                },
    { monagui::KeyEvent::VKEY_LEFT,   CtrlKey | ShiftKey, "MoveWordLeftAndModifySelection"              },
    { monagui::KeyEvent::VKEY_RIGHT,  0,                  "MoveRight"                                   },
    { monagui::KeyEvent::VKEY_RIGHT,  ShiftKey,           "MoveRightAndModifySelection"                 },
    { monagui::KeyEvent::VKEY_RIGHT,  CtrlKey,            "MoveWordRight"                               },
    { monagui::KeyEvent::VKEY_RIGHT,  CtrlKey | ShiftKey, "MoveWordRightAndModifySelection"             },
    { monagui::KeyEvent::VKEY_UP,     0,                  "MoveUp"                                      },
    { monagui::KeyEvent::VKEY_UP,     ShiftKey,           "MoveUpAndModifySelection"                    },
    { monagui::KeyEvent::VKEY_PGUP,   ShiftKey,           "MovePageUpAndModifySelection"                },
    { monagui::KeyEvent::VKEY_DOWN,   0,                  "MoveDown"                                    },
    { monagui::KeyEvent::VKEY_DOWN,   ShiftKey,           "MoveDownAndModifySelection"                  },
    { monagui::KeyEvent::VKEY_PGDOWN, ShiftKey,           "MovePageDownAndModifySelection"              },
    { monagui::KeyEvent::VKEY_PGUP,   0,                  "MovePageUp"                                  },
    { monagui::KeyEvent::VKEY_PGDOWN, 0,                  "MovePageDown"                                },
    { monagui::KeyEvent::VKEY_HOME,   0,                  "MoveToBeginningOfLine"                       },
    { monagui::KeyEvent::VKEY_HOME,   ShiftKey,           "MoveToBeginningOfLineAndModifySelection"     },
    { monagui::KeyEvent::VKEY_HOME,   CtrlKey,            "MoveToBeginningOfDocument"                   },
    { monagui::KeyEvent::VKEY_HOME,   CtrlKey | ShiftKey, "MoveToBeginningOfDocumentAndModifySelection" },
    { monagui::KeyEvent::VKEY_END,    0,                  "MoveToEndOfLine"                             },
    { monagui::KeyEvent::VKEY_END,    ShiftKey,           "MoveToEndOfLineAndModifySelection"           },
    { monagui::KeyEvent::VKEY_END,    CtrlKey,            "MoveToEndOfDocument"                         },
    { monagui::KeyEvent::VKEY_END,    CtrlKey | ShiftKey, "MoveToEndOfDocumentAndModifySelection"       },
    { monagui::KeyEvent::VKEY_ESC,    0,                  "DeleteBackward"                              },
    { monagui::KeyEvent::VKEY_ESC,    ShiftKey,           "DeleteBackward"                              },
    { monagui::KeyEvent::VKEY_DELETE, 0,                  "DeleteForward"                               },
    { monagui::KeyEvent::VKEY_ESC,    CtrlKey,            "DeleteWordBackward"                          },
    { monagui::KeyEvent::VKEY_DELETE, CtrlKey,            "DeleteWordForward"                           },
    { 'B',                            CtrlKey,            "ToggleBold"                                  },
    { 'I',                            CtrlKey,            "ToggleItalic"                                },
    { monagui::KeyEvent::VKEY_ESC,    0,                  "Cancel"                                      },
    { monagui::KeyEvent::VKEY_TAB,    0,                  "InsertTab"                                   },
    { monagui::KeyEvent::VKEY_TAB,    ShiftKey,           "InsertBacktab"                               },
    { monagui::KeyEvent::VKEY_ENTER,  0,                  "InsertNewline"                               },
    { monagui::KeyEvent::VKEY_ENTER,  CtrlKey,            "InsertNewline"                               },
    { monagui::KeyEvent::VKEY_ENTER,  AltKey,             "InsertNewline"                               },
    { monagui::KeyEvent::VKEY_ENTER,  AltKey | ShiftKey,  "InsertNewline"                               },
    // It's not quite clear whether clipboard shortcuts and Undo/Redo should be handled
    // in the application or in WebKit. We chose WebKit for now.
    { 'C',                            CtrlKey,            "Copy"                                        },
    { 'V',                            CtrlKey,            "Paste"                                       },
    { 'X',                            CtrlKey,            "Cut"                                         },
    { 'A',                            CtrlKey,            "SelectAll"                                   },
    { monagui::KeyEvent::VKEY_INSERT, CtrlKey,            "Copy"                                        },
    { monagui::KeyEvent::VKEY_DELETE, ShiftKey,           "Cut"                                         },
    { monagui::KeyEvent::VKEY_INSERT, ShiftKey,           "Paste"                                       },
    { 'Z',                            CtrlKey,            "Undo"                                        },
    { 'Z',                            CtrlKey | ShiftKey, "Redo"                                        }
};

static const KeyPressEntry keyPressEntries[] = {
    { '\t',   0,                  "InsertTab"                                   },
    { '\t',   ShiftKey,           "InsertBacktab"                               },
    { '\r',   0,                  "InsertNewline"                               },
    { '\r',   CtrlKey,            "InsertNewline"                               },
    { '\r',   AltKey,             "InsertNewline"                               },
    { '\r',   AltKey | ShiftKey,  "InsertNewline"                               }
};

const char* EditorClientMona::interpretKeyEvent(const KeyboardEvent* event)
{
    ASSERT(event->type() == eventNames().keydownEvent || event->type() == eventNames().keypressEvent);

    static HashMap<int, const char*>* keyDownCommandsMap = 0;
    static HashMap<int, const char*>* keyPressCommandsMap = 0;

    if (!keyDownCommandsMap) {
        keyDownCommandsMap = new HashMap<int, const char*>;
        keyPressCommandsMap = new HashMap<int, const char*>;
        for (size_t i = 0; i < WTF_ARRAY_LENGTH(keyDownEntries); ++i)
            keyDownCommandsMap->set(keyDownEntries[i].modifiers << 16 | keyDownEntries[i].virtualKey, keyDownEntries[i].name);

        for (size_t i = 0; i < WTF_ARRAY_LENGTH(keyPressEntries); ++i)
            keyPressCommandsMap->set(keyPressEntries[i].modifiers << 16 | keyPressEntries[i].charCode, keyPressEntries[i].name);
    }

    unsigned modifiers = 0;
    if (event->shiftKey())
        modifiers |= ShiftKey;
    if (event->altKey())
        modifiers |= AltKey;
    if (event->ctrlKey())
        modifiers |= CtrlKey;

    if (event->type() == eventNames().keydownEvent) {
        int mapKey = modifiers << 16 | event->keyCode();
        return mapKey ? keyDownCommandsMap->get(mapKey) : 0;
    }

    int mapKey = modifiers << 16 | event->charCode();
    return mapKey ? keyPressCommandsMap->get(mapKey) : 0;
}

} // namespace WebCore
