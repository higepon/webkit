/*
 * Copyright (C) 2006 Don Gibson <dgibson77@gmail.com>
 * Copyright (C) 2006 Zack Rusin <zack@kde.org>
 * Copyright (C) 2006, 2011 Apple Inc. All rights reserved.
 * Copyright (C) 2007 Trolltech ASA
 * Copyright (C) 2007 Ryan Leavengood <leavengood@gmail.com> All rights reserved.
 * Copyright (C) 2009 Maxime Simon <simon.maxime@gmail.com> All rights reserved.
 * Copyright (C) 2011 Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
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

#include <assert.h>
#include "config.h"
#include "FrameLoaderClientMona.h"

#include "DocumentLoader.h"
#include "Frame.h"
#include "FrameLoader.h"
#include "FrameTree.h"
#include "FrameView.h"
#include "HTMLFrameOwnerElement.h"
#include "NotImplemented.h"
#include "Page.h"
#include "PlatformString.h"
#include "ResourceRequest.h"
#include "ScriptController.h"
#include "WebFrame.h"
#include "FrameNetworkingContextMona.h"
#include "GraphicsContext.h"
#include "WebView.h"
// #define assert(...) /* */
// #include <monagui.h>




namespace WebCore {

FrameLoaderClientMona::FrameLoaderClientMona(WebPage* web_page, WebFrame* web_frame)
    : web_page_(web_page),
      web_frame_(web_frame),
      frame_(0)
{
}


void FrameLoaderClientMona::dispatchDidChangeIcons(WebCore::IconType)
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidReceiveTitle(const StringWithDirection& title)
{
    notImplemented();
}

void FrameLoaderClient::didRunInsecureContent(SecurityOrigin*, const KURL&)
{
    notImplemented();
}

PassRefPtr<FrameNetworkingContext> FrameLoaderClientMona::createNetworkingContext()
{
    return WebKit::FrameNetworkingContextMona::create(frame_);
}

void FrameLoaderClientMona::didDisplayInsecureContent()
{
    notImplemented();
}

void FrameLoaderClientMona::didRunInsecureContent(SecurityOrigin*, const KURL&)
{
    notImplemented();
}


void FrameLoaderClientMona::setFrame(Frame* frame)
{
    frame_ = frame;
}

void FrameLoaderClientMona::setWebView(WebView* webview)
{
    web_view_ = webview;
}

void FrameLoaderClientMona::detachFrameLoader()
{
    frame_ = 0;
}

bool FrameLoaderClientMona::hasWebView() const
{
    return web_view_;
}

bool FrameLoaderClientMona::hasBackForwardList() const
{
    notImplemented();
    return true;
}

void FrameLoaderClientMona::resetBackForwardList()
{
    notImplemented();
}

bool FrameLoaderClientMona::provisionalItemIsTarget() const
{
    notImplemented();
    return false;
}

void FrameLoaderClientMona::makeRepresentation(DocumentLoader*)
{
    notImplemented();
}

void FrameLoaderClientMona::forceLayout()
{
    notImplemented();
}

void FrameLoaderClientMona::forceLayoutForNonHTML()
{
    notImplemented();
}

void FrameLoaderClientMona::updateHistoryForCommit()
{
    notImplemented();
}

void FrameLoaderClientMona::updateHistoryForBackForwardNavigation()
{
    notImplemented();
}

void FrameLoaderClientMona::updateHistoryForReload()
{
    notImplemented();
}

void FrameLoaderClientMona::updateHistoryForStandardLoad()
{
    notImplemented();
}

void FrameLoaderClientMona::updateHistoryForInternalLoad()
{
    notImplemented();
}

void FrameLoaderClientMona::updateHistoryAfterClientRedirect()
{
    notImplemented();
}

void FrameLoaderClientMona::setCopiesOnScroll()
{
    // apparently mac specific
    notImplemented();
}

LoadErrorResetToken* FrameLoaderClientMona::tokenForLoadErrorReset()
{
    notImplemented();
    return 0;
}

void FrameLoaderClientMona::resetAfterLoadError(LoadErrorResetToken*)
{
    notImplemented();
}

void FrameLoaderClientMona::doNotResetAfterLoadError(LoadErrorResetToken*)
{
    notImplemented();
}

void FrameLoaderClientMona::willCloseDocument()
{
    notImplemented();
}

void FrameLoaderClientMona::detachedFromParent2()
{
    notImplemented();
}

void FrameLoaderClientMona::detachedFromParent3()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidHandleOnloadEvents()
{
    // if (web_view_) {
    //     BMessage message(LOAD_ONLOAD_HANDLE);
    //     message.AddString("url", frame_->loader()->documentLoader()->request().url().string());
    //     m_messenger->SendMessage(&message);
    // }
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidReceiveServerRedirectForProvisionalLoad()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidCancelClientRedirect()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchWillPerformClientRedirect(const KURL&, double interval, double fireDate)
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidChangeLocationWithinPage()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidPushStateWithinPage()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidReplaceStateWithinPage()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidPopStateWithinPage()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchWillClose()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidStartProvisionalLoad()
{
    // if (web_view_) {
    //     BMessage message(LOAD_NEGOCIATING);
    //     message.AddString("url", frame_->loader()->provisionalDocumentLoader()->request().url().string());
    //     m_messenger->SendMessage(&message);
    // }
    notImplemented();
}

// void FrameLoaderClientMona::dispatchDidReceiveTitle(const StringWithTitle& title)
// {
//     // if (web_view_) {
//     //     // FIXME: use direction of title.
//     //     web_view_->SetPageTitle(title.m_string());
//     //     BMessage message(TITLE_CHANGED);
//     //     message.AddString("title", title.string());
//     //     m_messenger->SendMessage(&message);
//     // }
//     notImplemented();
// }

void FrameLoaderClientMona::dispatchDidCommitLoad()
{
    // if (web_view_) {
    //     BMessage message(LOAD_TRANSFERRING);
    //     message.AddString("url", frame_->loader()->documentLoader()->request().url().string());
    //     m_messenger->SendMessage(&message);
    // }
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidFinishDocumentLoad()
{
    // if (web_view_) {
    //     BMessage message(LOAD_DOC_COMPLETED);
    //     message.AddString("url", frame_->document()->url().string());
    //     m_messenger->SendMessage(&message);
    // }
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidFinishLoad()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidFirstLayout()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidFirstVisuallyNonEmptyLayout()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchShow()
{
    notImplemented();
}

void FrameLoaderClientMona::cancelPolicyCheck()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchWillSubmitForm(FramePolicyFunction function, PassRefPtr<FormState>)
{
    // FIXME: Send an event to allow for alerts and cancellation.
    if (!frame_)
        return;
    (frame_->loader()->policyChecker()->*function)(PolicyUse);
}

void FrameLoaderClientMona::dispatchDidLoadMainResource(DocumentLoader*)
{
    notImplemented();
}

void FrameLoaderClientMona::revertToProvisionalState(DocumentLoader*)
{
    notImplemented();
}

void FrameLoaderClientMona::postProgressStartedNotification()
{
    notImplemented();
}

void FrameLoaderClientMona::postProgressEstimateChangedNotification()
{
    notImplemented();
}

void FrameLoaderClientMona::postProgressFinishedNotification()
{
    // if (web_view_) {
    //     BMessage message(LOAD_DL_COMPLETED);
    //     message.AddString("url", frame_->document()->url().string());
    //     m_messenger->SendMessage(&message);
    // }
    notImplemented();
}

void FrameLoaderClientMona::progressStarted()
{
    notImplemented();
}


void FrameLoaderClientMona::progressCompleted()
{
    notImplemented();
}


void FrameLoaderClientMona::setMainFrameDocumentReady(bool)
{
    notImplemented();
    // this is only interesting once we provide an external API for the DOM
}

void FrameLoaderClientMona::willChangeTitle(DocumentLoader*)
{
    notImplemented();
}

void FrameLoaderClientMona::didChangeTitle(DocumentLoader* docLoader)
{
    setTitle(docLoader->title(), docLoader->url());
}

void FrameLoaderClientMona::finishedLoading(DocumentLoader*)
{
    notImplemented();
}

bool FrameLoaderClientMona::canShowMIMETypeAsHTML(const WTF::String& MIMEType) const
{
    notImplemented();
    return false;
}
    
bool FrameLoaderClientMona::canShowMIMEType(const WTF::String& MIMEType) const
{
    notImplemented();
    return true;
}

bool FrameLoaderClientMona::representationExistsForURLScheme(const WTF::String& URLScheme) const
{
    notImplemented();
    return false;
}

WTF::String FrameLoaderClientMona::generatedMIMETypeForURLScheme(const WTF::String& URLScheme) const
{
    notImplemented();
    return WTF::String();
}

void FrameLoaderClientMona::frameLoadCompleted()
{
    // if (web_view_->LockLooper()) {
    //     web_view_->Draw(web_view_->Bounds());
    //     web_view_->UnlockLooper();
    // }
    notImplemented();
}

void FrameLoaderClientMona::saveViewStateToItem(HistoryItem*)
{
    notImplemented();
}

void FrameLoaderClientMona::restoreViewState()
{
    notImplemented();
}

void FrameLoaderClientMona::restoreScrollPositionAndViewState()
{
    notImplemented();
}

void FrameLoaderClientMona::provisionalLoadStarted()
{
    notImplemented();
}

bool FrameLoaderClientMona::shouldTreatURLAsSameAsCurrent(const KURL&) const
{
    notImplemented();
    return false;
}

void FrameLoaderClientMona::addHistoryItemForFragmentScroll()
{
    notImplemented();
}

void FrameLoaderClientMona::didFinishLoad()
{
    notImplemented();
}

void FrameLoaderClientMona::prepareForDataSourceReplacement()
{
    notImplemented();
}

void FrameLoaderClientMona::setTitle(const StringWithDirection& title, const KURL&)
{
  _logprintf("TTITLE%s %s:%d\n", __func__, __FILE__, __LINE__);
  _logprintf("title=%s", title.string().ascii().data());
  if (web_view_) {
    web_view_->setTitle(title.string().ascii().data());
  }
  notImplemented();
}

WTF::String FrameLoaderClientMona::userAgent(const KURL&)
{
    return WTF::String("Mozilla/5.0 (compatible; U; InfiNet 0.1; Mona) AppleWebKit/420+ (KHTML, like Gecko)");
}

void FrameLoaderClientMona::dispatchDidReceiveIcon()
{
    notImplemented();
}

void FrameLoaderClientMona::frameLoaderDestroyed()
{
    frame_ = 0;
    // m_messenger = 0;
    delete this;
}

bool FrameLoaderClientMona::canHandleRequest(const WebCore::ResourceRequest&) const
{
    notImplemented();
    return true;
}

void FrameLoaderClientMona::partClearedInBegin()
{
    notImplemented();
}

void FrameLoaderClientMona::updateGlobalHistory()
{
    notImplemented();
}

void FrameLoaderClientMona::updateGlobalHistoryRedirectLinks()
{
    notImplemented();
}

bool FrameLoaderClientMona::shouldGoToHistoryItem(WebCore::HistoryItem*) const
{
    notImplemented();
    return true;
}

bool FrameLoaderClientMona::shouldStopLoadingForHistoryItem(WebCore::HistoryItem*) const
{
    notImplemented();
    return true;
}

void FrameLoaderClientMona::dispatchDidAddBackForwardItem(WebCore::HistoryItem*) const
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidRemoveBackForwardItem(WebCore::HistoryItem*) const
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidChangeBackForwardIndex() const
{
    notImplemented();
}


void FrameLoaderClientMona::saveScrollPositionAndViewStateToItem(WebCore::HistoryItem*)
{
    notImplemented();
}

bool FrameLoaderClientMona::canCachePage() const
{
    return false;
}

void FrameLoaderClientMona::setMainDocumentError(WebCore::DocumentLoader*, const WebCore::ResourceError&)
{
    notImplemented();
}

void FrameLoaderClientMona::committedLoad(WebCore::DocumentLoader* loader, const char* data, int length)
{
    _logprintf("committedLoad called %s %s:%d\n", __func__, __FILE__, __LINE__);
    loader->commitData(data, length);
}

WebCore::ResourceError FrameLoaderClientMona::cancelledError(const WebCore::ResourceRequest& request)
{
    notImplemented();
    //    return ResourceError(String(), WebKitErrorCannotShowURL, request.url().string(), String());
}

WebCore::ResourceError FrameLoaderClientMona::blockedError(const ResourceRequest& request)
{
    notImplemented();
    //    return ResourceError(String(), WebKitErrorCannotShowURL, request.url().string(), String());
}

WebCore::ResourceError FrameLoaderClientMona::cannotShowURLError(const WebCore::ResourceRequest& request)
{

    notImplemented();
  //    return ResourceError(String(), WebKitErrorCannotShowURL, request.url().string(), String());
}

WebCore::ResourceError FrameLoaderClientMona::interruptedForPolicyChangeError(const WebCore::ResourceRequest& request)
{
    notImplemented();
    //    return ResourceError(String(), WebKitErrorFrameLoadInterruptedByPolicyChange, request.url().string(), String());
}

WebCore::ResourceError FrameLoaderClientMona::cannotShowMIMETypeError(const WebCore::ResourceResponse& response)
{
    notImplemented();
    //    return ResourceError(String(), WebKitErrorCannotShowMIMEType, response.url().string(), String());
}

WebCore::ResourceError FrameLoaderClientMona::fileDoesNotExistError(const WebCore::ResourceResponse& response)
{
    notImplemented();
    //    return ResourceError(String(), WebKitErrorCannotShowURL, response.url().string(), String());
}

bool FrameLoaderClientMona::shouldFallBack(const WebCore::ResourceError& error)
{
    notImplemented();
    return false;
}

WTF::PassRefPtr<DocumentLoader> FrameLoaderClientMona::createDocumentLoader(const ResourceRequest& request,
                                                                             const SubstituteData& substituteData)
{
    return DocumentLoader::create(request, substituteData);
}

void FrameLoaderClientMona::download(ResourceHandle*, const ResourceRequest&,
                                      const ResourceRequest&, const ResourceResponse&)
{
    notImplemented();
}

void FrameLoaderClientMona::assignIdentifierToInitialRequest(unsigned long identifier, DocumentLoader*,
                                                              const ResourceRequest&)
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchWillSendRequest(DocumentLoader*, unsigned long, ResourceRequest& request,
                                                     const ResourceResponse& response)
{
    notImplemented();
}

bool FrameLoaderClientMona::shouldUseCredentialStorage(DocumentLoader*, unsigned long)
{
    notImplemented();
    return false;
}

void FrameLoaderClientMona::dispatchDidReceiveAuthenticationChallenge(DocumentLoader*,
                                                                       unsigned long, const AuthenticationChallenge&)
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidCancelAuthenticationChallenge(DocumentLoader*,
                                                                      unsigned long, const AuthenticationChallenge&)
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidReceiveResponse(DocumentLoader* loader, unsigned long id,
                                                        const ResourceResponse& response)
{
    notImplemented();
    m_response = response;
    m_firstData = true;
}

void FrameLoaderClientMona::dispatchDidReceiveContentLength(DocumentLoader* loader,
                                                             unsigned long id, int length)
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidFinishLoading(DocumentLoader*, unsigned long)
{
  cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32,
                                                        WEBVIEW_WIDTH, WEBVIEW_HEIGHT);
  if (cairo_surface_status(surface) != CAIRO_STATUS_SUCCESS) {
    _logprintf("CAIRO failure : %s %s:%d\n", __func__, __FILE__, __LINE__);
    return;  // create will notice we didn't set m_initialized and fail.
  }

  GraphicsContext context(cairo_create(surface));
  ASSERT(frame_);
  unsigned char* p = cairo_image_surface_get_data(surface);
  for (int i = 0; i < 10; i++) {
    _logprintf("before %x ", p[i]);
  }

  _logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
  frame_->view()->forceLayout(true); // correct place? 
  frame_->view()->paint(&context, IntRect(0, 0, WEBVIEW_WIDTH, WEBVIEW_HEIGHT));
 p = cairo_image_surface_get_data(surface);
  for (int i = 0; i < 10; i++) {
    _logprintf("after %x ", p[i]);
  }
  ASSERT(web_view_);
  web_view_->SetImageBuffer(p);
  web_view_->repaint();
    // MonaLauncher r;
  // r.SetData(p);
  // r.run();
  notImplemented();
}

void FrameLoaderClientMona::dispatchDidFailLoading(DocumentLoader* loader,
                                                    unsigned long, const ResourceError&)
{
    // if (web_view_) {
    //     BMessage message(LOAD_FAILED);
    //     message.AddString("url", frame_->loader()->documentLoader()->request().url().string());
    //     m_messenger->SendMessage(&message);
    // }
    notImplemented();
}

bool FrameLoaderClientMona::dispatchDidLoadResourceFromMemoryCache(DocumentLoader*,
                                                                    const ResourceRequest&,
                                                                    const ResourceResponse&, int)
{
    notImplemented();
    return false;
}

void FrameLoaderClientMona::dispatchDidFailProvisionalLoad(const ResourceError&)
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidFailLoad(const ResourceError&)
{
    notImplemented();
}

Frame* FrameLoaderClientMona::dispatchCreatePage(const WebCore::NavigationAction&)
{
    notImplemented();
    return false;
}

void FrameLoaderClientMona::dispatchDecidePolicyForResponse(FramePolicyFunction function,
                                                             const ResourceResponse& response,
                                                             const ResourceRequest& request)
{
    if (!frame_)
        return;

    notImplemented();
    (frame_->loader()->policyChecker()->*function)(PolicyUse);
}

void FrameLoaderClientMona::dispatchDecidePolicyForNewWindowAction(FramePolicyFunction function,
                                                                    const NavigationAction&,
                                                                    const ResourceRequest& request,
                                                                    PassRefPtr<FormState>, const WTF::String& targetName)
{
    // if (!frame_)
    //     return;

    // if (web_view_) {
    //     BMessage message(NEW_WINDOW_REQUESTED);
    //     message.AddString("url", request.url().string());
    //     if (m_messenger->SendMessage(&message)) {
    //         (frame_->loader()->policyChecker()->*function)(PolicyIgnore);
    //         return;
    //     }
    // }

    // (frame_->loader()->policyChecker()->*function)(PolicyUse);
    notImplemented();
}

void FrameLoaderClientMona::dispatchDecidePolicyForNavigationAction(FramePolicyFunction function,
                                                                     const NavigationAction& action,
                                                                     const ResourceRequest& request,
                                                                     PassRefPtr<FormState>)
{
  //    notImplemented();
_logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
if (!frame_ || !function)
    return;
_logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
if (web_view_) {
_logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
    // BMessage message(NAVIGATION_REQUESTED);
    // message.AddString("url", request.url().string());
    // m_messenger->SendMessage(&message);
_logprintf("%s %s:%d loader %x checker %x\n", __func__, __FILE__, __LINE__, frame_->loader(), frame_->loader()->policyChecker());
    (frame_->loader()->policyChecker()->*function)(PolicyUse);
_logprintf("%s %s:%d\n", __func__, __FILE__, __LINE__);
}
}

void FrameLoaderClientMona::dispatchUnableToImplementPolicy(const ResourceError&)
{
    notImplemented();
}

void FrameLoaderClientMona::startDownload(const ResourceRequest&, const WTF::String& /* suggestedName */)
{
    notImplemented();
}

PassRefPtr<Frame> FrameLoaderClientMona::createFrame(const KURL& url, const WTF::String& name,
                                                      HTMLFrameOwnerElement* ownerElement,
                                                      const WTF::String& referrer, bool allowsScrolling,
                                                      int marginWidth, int marginHeight)
{
    // // FIXME: We should apply the right property to the frameView. (scrollbar,margins)

    // RefPtr<Frame> childFrame = Frame::create(frame_->page(), ownerElement, this);
    // setFrame(childFrame.get());

    // RefPtr<FrameView> frameView = FrameView::create(childFrame.get());

    // frameView->setAllowsScrolling(allowsScrolling);
    // frameView->deref();
    // childFrame->setView(frameView.get());
    // childFrame->init();

    // childFrame->tree()->setName(name);
    // frame_->tree()->appendChild(childFrame);

    // frame_->loader()->loadURLIntoChildFrame(url, referrer, childFrame.get());

    // // The frame's onload handler may have removed it from the document.
    // if (!childFrame->tree()->parent())
    //     return 0;

    // return childFrame.release();

    notImplemented();
    return 0;
}

void FrameLoaderClientMona::didTransferChildFrameToNewDocument(Page*)
{
    notImplemented();
}

void FrameLoaderClientMona::transferLoadingResourceFromPage(ResourceLoader*, const ResourceRequest&, Page*)
{
    notImplemented();
}

ObjectContentType FrameLoaderClientMona::objectContentType(const KURL& url, const WTF::String& mimeType, bool shouldPreferPlugInsForImages)
{
    notImplemented();
    return ObjectContentType();
}

PassRefPtr<Widget> FrameLoaderClientMona::createPlugin(const IntSize&, HTMLPlugInElement*,
                                                       const KURL&, const WTF::Vector<WTF::String>&,
                                                       const WTF::Vector<WTF::String>&, const WTF::String&,
                                                        bool loadManually)
{
    notImplemented();
    return 0;
}

void FrameLoaderClientMona::redirectDataToPlugin(Widget* pluginWidget)
{
    notImplemented();
    return;
}

ResourceError FrameLoaderClientMona::pluginWillHandleLoadError(const ResourceResponse& response)
{
    notImplemented();
    //    return ResourceError(String(), WebKitErrorCannotLoadPlugIn, response.url().string(), String());
}

PassRefPtr<Widget> FrameLoaderClientMona::createJavaAppletWidget(const IntSize&, HTMLAppletElement*,
                                                       const KURL& baseURL,
                                                                 const WTF::Vector<WTF::String>& paramNames,
                                                                 const WTF::Vector<WTF::String>& paramValues)
{
    notImplemented();
    return 0;
}

WTF::String FrameLoaderClientMona::overrideMediaType() const
{
    notImplemented();
    return WTF::String();
}

void FrameLoaderClientMona::dispatchDidClearWindowObjectInWorld(DOMWrapperWorld* world)
{
    notImplemented();
    // if (world != mainThreadNormalWorld())
    //     return;

    // if (web_view_) {
    //     BMessage message(JAVASCRIPT_WINDOW_OBJECT_CLEARED);
    //     m_messenger->SendMessage(&message);
    // }
}

void FrameLoaderClientMona::documentElementAvailable()
{
}

void FrameLoaderClientMona::didPerformFirstNavigation() const
{
    notImplemented();
}

void FrameLoaderClientMona::registerForIconNotification(bool listen)
{
    notImplemented();
}

void FrameLoaderClientMona::savePlatformDataToCachedFrame(CachedFrame*)
{
    notImplemented();
}

void FrameLoaderClientMona::transitionToCommittedFromCachedFrame(CachedFrame*)
{
    notImplemented();
}

void FrameLoaderClientMona::transitionToCommittedForNewPage()
{
  ASSERT(web_frame_);
  Frame* frame = web_frame_->Frame();
  IntSize size = IntSize(WEBVIEW_WIDTH, WEBVIEW_HEIGHT);
  bool transparent = web_frame_->IsTransparent();
  Color backgroundColor = transparent ? WebCore::Color::transparent : WebCore::Color::gray;

  frame->createView(size, backgroundColor, transparent, IntSize(), false);

  ASSERT(web_page_);
  // todo ???
  //  frame->view()->setTopLevelPlatformWidget(web_page_->WebView());
}

void FrameLoaderClientMona::didSaveToPageCache()
{
    notImplemented();
}

void FrameLoaderClientMona::didRestoreFromPageCache()
{
    notImplemented();
}

void FrameLoaderClientMona::dispatchDidBecomeFrameset(bool)
{
    notImplemented();
}

} // namespace WebCore
