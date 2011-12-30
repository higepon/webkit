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

bool EditorClientMona::shouldInsertText(const String&, Range*, EditorInsertAction)
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

void EditorClientMona::handleKeyboardEvent(KeyboardEvent* event)
{
	_logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
	_logprintf("%s %s:%d %d\n", __func__, __FILE__, __LINE__, m_page);
	_logprintf("%s %s:%d %d\n", __func__, __FILE__, __LINE__, m_page->focusController());
	_logprintf("%s %s:%d %d\n", __func__, __FILE__, __LINE__, m_page->focusController()->focusedOrMainFrame());
    Frame* frame = m_page->focusController()->focusedOrMainFrame();
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    if (!frame || !frame->document()->focusedNode())
        return;
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    const PlatformKeyboardEvent* kevent = event->keyEvent();
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    if (!kevent || kevent->type() == PlatformKeyboardEvent::KeyUp)
        return;
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    Node* start = frame->selection()->start().containerNode();
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    if (!start)
        return;
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    frame->editor()->insertText("abc", event);
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    // if (start->isContentEditable()) {
    //     switch (kevent->windowsVirtualKeyCode()) {
    //     case VK_BACK:
    //         frame->editor()->deleteWithDirection(DirectionBackward,
    //                                              kevent->ctrlKey() ? WordGranularity : CharacterGranularity,
    //                                              false, true);
    //         break;
    //     case VK_DELETE:
    //         frame->editor()->deleteWithDirection(DirectionForward,
    //                                              kevent->ctrlKey() ? WordGranularity : CharacterGranularity,
    //                                              false, true);
    //         break;
    //     case VK_LEFT:
    //         frame->selection()->modify(kevent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
    //                                    DirectionLeft,
    //                                    kevent->ctrlKey() ? WordGranularity : CharacterGranularity,
    //                                    true);
    //         break;
    //     case VK_RIGHT:
    //         frame->selection()->modify(kevent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
    //                                    DirectionRight,
    //                                    kevent->ctrlKey() ? WordGranularity : CharacterGranularity,
    //                                    true);
    //         break;
    //     case VK_UP:
    //         frame->selection()->modify(kevent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
    //                                    DirectionBackward,
    //                                    kevent->ctrlKey() ? ParagraphGranularity : LineGranularity,
    //                                    true);
    //         break;
    //     case VK_DOWN:
    //         frame->selection()->modify(kevent->shiftKey() ? FrameSelection::AlterationExtend : FrameSelection::AlterationMove,
    //                                    DirectionForward,
    //                                    kevent->ctrlKey() ? ParagraphGranularity : LineGranularity,
    //                                    true);
    //         break;
    //     case VK_PRIOR: // PageUp
    //         frame->editor()->command("MoveUpByPageAndModifyCaret");
    //         break;
    //     case VK_NEXT: // PageDown
    //         frame->editor()->command("MoveDownByPageAndModifyCaret");
    //         break;
    //     case VK_RETURN:
    //         frame->editor()->command("InsertLineBreak");
    //         break;
    //     case VK_TAB:
    //         return;
    //     default:
    //         if (!kevent->ctrlKey() && !kevent->altKey() && !kevent->text().isEmpty()) {
    //             if (kevent->text().length() == 1) {
    //                 UChar ch = kevent->text()[0];
    //                 // Don't insert null or control characters as they can result in unexpected behaviour
    //                 if (ch < ' ')
    //                     break;
    //             }
    //             frame->editor()->insertText(kevent->text(), event);
    //         } else if (kevent->ctrlKey()) {
    //             switch (kevent->windowsVirtualKeyCode()) {
    //             case VK_A:
    //                 frame->editor()->command("SelectAll");
    //                 break;
    //             case VK_B:
    //                 frame->editor()->command("ToggleBold");
    //                 break;
    //             case VK_C:
    //                 frame->editor()->command("Copy");
    //                 break;
    //             case VK_I:
    //                 frame->editor()->command("ToggleItalic");
    //                 break;
    //             case VK_V:
    //                 frame->editor()->command("Paste");
    //                 break;
    //             case VK_X:
    //                 frame->editor()->command("Cut");
    //                 break;
    //             case VK_Y:
    //                 frame->editor()->command("Redo");
    //                 break;
    //             case VK_Z:
    //                 frame->editor()->command("Undo");
    //                 break;
    //             default:
    //                 return;
    //             }
    //         } else
    //             return;
    //     }
    // } else {
    //     switch (kevent->windowsVirtualKeyCode()) {
    //     case VK_UP:
    //         frame->editor()->command("MoveUp");
    //         break;
    //     case VK_DOWN:
    //         frame->editor()->command("MoveDown");
    //         break;
    //     case VK_PRIOR: // PageUp
    //         frame->editor()->command("MoveUpByPageAndModifyCaret");
    //         break;
    //     case VK_NEXT: // PageDown
    //         frame->editor()->command("MoveDownByPageAndModifyCaret");
    //         break;
    //     case VK_HOME:
    //         if (kevent->ctrlKey())
    //             frame->editor()->command("MoveToBeginningOfDocument");
    //         break;
    //     case VK_END:
    //         if (kevent->ctrlKey())
    //             frame->editor()->command("MoveToEndOfDocument");
    //         break;
    //     default:
    //         if (kevent->ctrlKey()) {
    //             switch (kevent->windowsVirtualKeyCode()) {
    //             case VK_A:
    //                 frame->editor()->command("SelectAll");
    //                 break;
    //             case VK_C: case VK_X:
    //                 frame->editor()->command("Copy");
    //                 break;
    //             default:
    //                 return;
    //             }
    //         } else
    //             return;
    //     }
    // }
    event->setDefaultHandled();
  notImplemented();
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

void EditorClientMona::ignoreWordInSpellDocument(const String&)
{
    notImplemented();
}

void EditorClientMona::learnWord(const String&)
{
    notImplemented();
}

void EditorClientMona::checkSpellingOfString(const UChar*, int, int*, int*)
{
    notImplemented();
}

String EditorClientMona::getAutoCorrectSuggestionForMisspelledWord(const String& misspelledWord)
{
    notImplemented();
    return String();
}

void EditorClientMona::checkGrammarOfString(const UChar*, int, Vector<GrammarDetail>&, int*, int*)
{
    notImplemented();
}

void EditorClientMona::updateSpellingUIWithGrammarString(const String&, const GrammarDetail&)
{
    notImplemented();
}

void EditorClientMona::updateSpellingUIWithMisspelledWord(const String&)
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

void EditorClientMona::getGuessesForWord(const String& word, const String& context, Vector<String>& guesses)
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

} // namespace WebCore
