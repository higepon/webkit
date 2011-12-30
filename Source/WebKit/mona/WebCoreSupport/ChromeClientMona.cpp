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


namespace WebCore {

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
    notImplemented();
  //    printf("MESSAGE %s:%i %s\n", BString(sourceID).String(), lineNumber, BString(message).String());
}

void ChromeClientMona::addMessageToConsole(MessageSource, MessageLevel, const WTF::String& message,
                                            unsigned int lineNumber, const WTF::String& sourceID)
{
    notImplemented();
  //    printf("MESSAGE %s:%i %s\n", BString(sourceID).String(), lineNumber, BString(message).String());
}

void ChromeClientMona::addMessageToConsole(MessageSource, MessageType, MessageLevel, const WTF::String& message,
                                            unsigned int lineNumber, const WTF::String& sourceID)
{
    notImplemented();
  //    printf("MESSAGE %s:%i %s\n", BString(sourceID).String(), lineNumber, BString(message).String());
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
    notImplemented();
    // BAlert* alert = new BAlert("JavaScript", BString(msg).String(), "OK");
    // alert->Go();
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
    _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    ASSERT(webpage_);
    webpage_->paint(rect, immediate);

//	cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,
//	                                                        WEBVIEW_WIDTH, WEBVIEW_HEIGHT);
//	  if (cairo_surface_status(surface) != CAIRO_STATUS_SUCCESS) {
//	    _logprintf("CAIRO failure : %s %s:%d\n", __func__, __FILE__, __LINE__);
//	    return;  // create will notice we didn't set m_initialized and fail.
//	  }
//
//	  GraphicsContext context(cairo_create(surface));
//
//	  unsigned char* p = cairo_image_surface_get_data(surface);
//	  for (int i = 0; i < 10; i++) {
//	    _logprintf("before %x ", p[i]);
//	  }
//
//	  _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
//	  ASSERT(webView()->webPage()->page()->mainFrame());
//	  webView()->webPage()->page()->mainFrame()->view()->forceLayout(true); // correct place?
//	  webView()->webPage()->page()->mainFrame()->view()->paint(&context, IntRect(0, 0, WEBVIEW_WIDTH, WEBVIEW_HEIGHT));
//	 p = cairo_image_surface_get_data(surface);
//	  for (int i = 0; i < 10; i++) {
//	    _logprintf("after %x ", p[i]);
//	  }
//	  ASSERT(webView());
//	  webView()->SetImageBuffer(p);
   // webView()->repaint();
    //    notImplemented();
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

void ChromeClientMona::mouseDidMoveOverElement(const HitTestResult& hit, unsigned /*modifierFlags*/)
{
    // Some extra info
    notImplemented();
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

