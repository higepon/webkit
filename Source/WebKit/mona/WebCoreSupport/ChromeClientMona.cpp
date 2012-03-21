/*
 * Copyright (C) 2006 Zack Rusin <zack@kde.org>
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) 2007 Ryan Leavengood <leavengood@gmail.com> All rights reserved.
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 * Copyright (c) 2011 Higepon(Taro Minowa) <higepon@users.sourceforge.jp>
 *
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
#include "ChromeClientMona.h"

#include "FileIconLoader.h"
#include "Frame.h"
#include "FrameLoadRequest.h"
#include "FrameView.h"
#include "HitTestResult.h"
#include "Icon.h"
#include "NavigationAction.h"
#include "NotImplemented.h"
#include "PlatformString.h"
#include "SecurityOrigin.h"
#include "WebPage.h"
#include "Page.h"
#include "WebView.h"
//#include "PopupMenuHaiku.h"
//#include "SearchPopupMenuHaiku.h"

///#include <Alert.h>
//#include <String.h>

#ifdef notImplemented
#undef notImplemented
#define notImplemented() ((void)0)
#endif

namespace WebCore {

static std::string toStdString(const WTF::String& s)
{
    std::string text;
    size_t len = s.length();
    for (size_t i = 0; i < len; i++) {
        text += s[i];
    }
    return text;
}


ChromeClientMona::ChromeClientMona(WebPage* webpage) : webpage_(webpage)
{
}

ChromeClientMona::~ChromeClientMona()
{
}

void ChromeClientMona::chromeDestroyed()
{
    notImplemented();
}

void ChromeClientMona::setWindowRect(const FloatRect&)
{
    notImplemented();
}

FloatRect ChromeClientMona::windowRect()
{
    notImplemented();
    return FloatRect(0, 0, 200, 200);
}

FloatRect ChromeClientMona::pageRect()
{
    notImplemented();
    return FloatRect(0, 0, 200, 200);
}

void ChromeClientMona::focus()
{
    notImplemented();
}

void ChromeClientMona::unfocus()
{
    notImplemented();
}

bool ChromeClientMona::canTakeFocus(FocusDirection)
{
    notImplemented();
    return true;
}

void ChromeClientMona::takeFocus(FocusDirection)
{
    notImplemented();
}

void ChromeClientMona::focusedNodeChanged(Node*)
{
}

void ChromeClientMona::focusedFrameChanged(Frame*)
{
}

Page* ChromeClientMona::createWindow(Frame*, const FrameLoadRequest&, const WebCore::WindowFeatures&, const WebCore::NavigationAction&)
{
    notImplemented();
    return 0;
}

Page* ChromeClientMona::createModalDialog(Frame*, const FrameLoadRequest&)
{
    notImplemented();
    return 0;
}

void ChromeClientMona::show()
{
    notImplemented();
}

bool ChromeClientMona::canRunModal()
{
    notImplemented();
    return false;
}

void ChromeClientMona::runModal()
{
    notImplemented();
}

void ChromeClientMona::setToolbarsVisible(bool)
{
    notImplemented();
}

bool ChromeClientMona::toolbarsVisible()
{
    notImplemented();
    return false;
}

void ChromeClientMona::setStatusbarVisible(bool)
{
    notImplemented();
}

bool ChromeClientMona::statusbarVisible()
{
    notImplemented();
    return false;
}

void ChromeClientMona::setScrollbarsVisible(bool)
{
    notImplemented();
}

bool ChromeClientMona::scrollbarsVisible()
{
    notImplemented();
    return true;
}

void ChromeClientMona::setMenubarVisible(bool)
{
    notImplemented();
}

bool ChromeClientMona::menubarVisible()
{
    notImplemented();
    return false;
}

void ChromeClientMona::setResizable(bool)
{
    notImplemented();
}

void ChromeClientMona::addMessageToConsole(const WTF::String& message, unsigned int lineNumber,
                                            const WTF::String& sourceID)
{
    std::string m("console:");
    m += toStdString(message);
    m += " at ";
    char buf[16];
    snprintf(buf, 16, "%d", lineNumber);
    m += buf;
    m += " sourceID:";
    m += toStdString(sourceID);

    webpage_->SetStatus(m.c_str());
    _logprintf("console:");
    _logprintf(m.c_str());
}

void ChromeClientMona::addMessageToConsole(MessageSource, MessageLevel, const WTF::String& message,
                                            unsigned int lineNumber, const WTF::String& sourceID)
{
    std::string m("console:");
    m += toStdString(message);
    m += " at ";
    char buf[16];
    snprintf(buf, 16, "%d", lineNumber);
    m += buf;
    m += " sourceID:";
    m += toStdString(sourceID);

    webpage_->SetStatus(m.c_str());
    _logprintf("console:");
    _logprintf(m.c_str());
}

void ChromeClientMona::addMessageToConsole(MessageSource, MessageType, MessageLevel, const WTF::String& message,
                                            unsigned int lineNumber, const WTF::String& sourceID)
{
    std::string m("console:");
    m += toStdString(message);
    m += " at ";
    char buf[16];
    snprintf(buf, 16, "%d", lineNumber);
    m += buf;
    m += " sourceID:";
    m += toStdString(sourceID);

    webpage_->SetStatus(m.c_str());
    _logprintf("console:");
    _logprintf(m.c_str());
}

bool ChromeClientMona::canRunBeforeUnloadConfirmPanel()
{
    notImplemented();
    return false;
}

bool ChromeClientMona::runBeforeUnloadConfirmPanel(const WTF::String& message, Frame* frame)
{
    notImplemented();
    return false;
}

void ChromeClientMona::closeWindowSoon()
{
    notImplemented();
}

void ChromeClientMona::runJavaScriptAlert(Frame*, const WTF::String& msg)
{
    std::string m("alert:");
    m += toStdString(msg);
    webpage_->SetStatus(m.c_str());
    _logprintf("JavaScriptAlert:");
    _logprintf(m.c_str());
}

bool ChromeClientMona::runJavaScriptConfirm(Frame*, const WTF::String& msg)
{
    notImplemented();
    //    BAlert* alert = new BAlert("JavaScript", BString(msg).String(), "Yes", "No");
    //    return !alert->Go();
}

bool ChromeClientMona::runJavaScriptPrompt(Frame*, const WTF::String& message, const WTF::String& defaultValue, WTF::String& result)
{
    notImplemented();
    return false;
}

void ChromeClientMona::setStatusbarText(const WTF::String&)
{
    notImplemented();
}

bool ChromeClientMona::shouldInterruptJavaScript()
{
    notImplemented();
    return false;
}

KeyboardUIMode ChromeClientMona::keyboardUIMode()
{
    return KeyboardAccessDefault;
}

IntRect ChromeClientMona::windowResizerRect() const
{
    return IntRect();
}

void ChromeClientMona::invalidateWindow(const IntRect& rect, bool immediate)
{
    notImplemented();
}

void ChromeClientMona::invalidateContentsAndWindow(const IntRect& rect, bool immediate)
{
    // Old comment :
    //   Calling layout or paint from here causes bad recursive call.
    //   But without this call, text input is not painted. So we again enabled it.
    // Latest comment:
    //   Calling paint from here causes crash, I'm sure.
    //   void FrameView::doDeferredRepaints will be called recursive via ScrollView then ChoromeClient::invalidateContentsAndWindow
    //   it makes crash on doDeferredRepaints, which breaks Vecotr<IntRect>.
    //   Accessing http://google.com can reproduce the crash.
    //    ASSERT(webpage_);
    //    webpage_->paint(rect, immediate);

    // To prevent recursive call of doDeferredRepaints,
    // We use MSG_UPDATE for immediate repaint.
    // Borrowed from WinCE port.
    uint32_t xy =  (rect.y() << 16) | rect.x();
    uint32_t wh =  (rect.height() << 16) | rect.width();
    if (MonAPI::Message::send(MonAPI::System::getThreadID(), MSG_UPDATE, xy, wh) != M_OK) {
        monapi_warn("message send failure");
    }
}

void ChromeClientMona::invalidateContentsForSlowScroll(const IntRect&, bool)
{
    notImplemented();
}

void ChromeClientMona::scroll(const IntSize& scrollDelta, const IntRect& rectToScroll, const IntRect& clipRect)
{
    notImplemented();
}

IntPoint ChromeClientMona::screenToWindow(const IntPoint&) const
{
    notImplemented();
    return IntPoint();
}

IntRect ChromeClientMona::windowToScreen(const IntRect&) const
{
    notImplemented();
    return IntRect();
}

PlatformPageClient ChromeClientMona::platformPageClient() const
{
    notImplemented();
    return PlatformWidget();
}

void ChromeClientMona::contentsSizeChanged(Frame*, const IntSize&) const
{
    notImplemented();
}

void ChromeClientMona::scrollRectIntoView(const IntRect&,  const ScrollView*) const
{
    notImplemented();
}

void ChromeClientMona::addToDirtyRegion(const IntRect&)
{
}

void ChromeClientMona::scrollBackingStore(int, int, const IntRect&, const IntRect&)
{
}

void ChromeClientMona::updateBackingStore()
{
}

void ChromeClientMona::mouseDidMoveOverElement(const HitTestResult& result, unsigned modifierFlags)
{
    bool isHover = result.isLiveLink() && !result.absoluteLinkURL().string().isEmpty();
    if (!monapi_call_mouse_set_moved_over(isHover)) {
        monapi_warn("monapi_call_mouse_set_moved_over failed");
    }
    KURL url = result.absoluteLinkURL();
    webpage_->SetStatus(toStdString(url.string()).c_str());
}

void ChromeClientMona::setToolTip(const WTF::String& tip)
{
    notImplemented();
}

void ChromeClientMona::setToolTip(const WTF::String& tip, TextDirection)
{
    notImplemented();
}

void ChromeClientMona::print(Frame*)
{
    notImplemented();
}

// void ChromeClientMona::exceededDatabaseQuota(Frame*, const String& databaseName)
// {
//     notImplemented();
// }

#if ENABLE(OFFLINE_WEB_APPLICATIONS)
void ChromeClientWx::reachedMaxAppCacheSize(int64_t spaceNeeded)
{
    notImplemented();
}

void ChromeClientWx::reachedApplicationCacheOriginQuota(SecurityOrigin*, int64_t)
{
    notImplemented();
}
#endif

void ChromeClientMona::requestGeolocationPermissionForFrame(Frame*, Geolocation*)
{
    notImplemented();
}

void ChromeClientMona::runOpenPanel(Frame*, PassRefPtr<FileChooser>)
{
    notImplemented();
}

void ChromeClientMona::loadIconForFiles(const WTF::Vector<WTF::String>& filenames, FileIconLoader* loader)
{
    loader->notifyFinished(Icon::createIconForFiles(filenames));
}

void ChromeClientMona::setCursor(const Cursor&)
{
    notImplemented();
}

void ChromeClientMona::setCursorHiddenUntilMouseMoves(bool)
{
    notImplemented();
}

// Notification that the given form element has changed. This function
// will be called frequently, so handling should be very fast.
void ChromeClientMona::formStateDidChange(const Node*)
{
    notImplemented();
}

bool ChromeClientMona::selectItemWritingDirectionIsNatural()
{
    return false;
}

bool ChromeClientMona::selectItemAlignmentFollowsMenuWritingDirection()
{
    return false;
}

PassRefPtr<PopupMenu> ChromeClientMona::createPopupMenu(PopupMenuClient* client) const
{
  notImplemented();
  //    return adoptRef(new PopupMenuMona(client));
}

PassRefPtr<SearchPopupMenu> ChromeClientMona::createSearchPopupMenu(PopupMenuClient* client) const
{
  notImplemented();
  //   return adoptRef(new SearchPopupMenuMona(client));
}


} // namespace WebCore
