// -*- c-basic-offset: 4 -*-
/*
 *  Copyright (C) 2000 Harri Porten (porten@kde.org)
 *  Copyright (C) 2006 Jon Shier (jshier@iastate.edu)
 *  Copyright (C) 2003, 2004, 2005, 2006, 2007 Apple Inc. All rights reseved.
 *  Copyright (C) 2006 Alexey Proskuryakov (ap@webkit.org)
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 *  USA
 */

#include "config.h"
#include "JSLocation.h"

#include "DOMWindow.h"
#include "Frame.h"
#include "FrameLoader.h"
#include "PlatformString.h"
#include "kjs_proxy.h"
#include "kjs_window.h"

#include "JSLocation.lut.h"

using namespace KJS;

namespace WebCore {

const ClassInfo JSLocation::info = { "Location", 0, &JSLocationTable };

/*
@begin JSLocationTable 12
  assign        &WebCore::JSLocationProtoFuncAssign::create        DontDelete|Function 1
  hash          WebCore::JSLocation::Hash                          DontDelete
  host          WebCore::JSLocation::Host                          DontDelete
  hostname      WebCore::JSLocation::Hostname                      DontDelete
  href          WebCore::JSLocation::Href                          DontDelete
  pathname      WebCore::JSLocation::Pathname                      DontDelete
  port          WebCore::JSLocation::Port                          DontDelete
  protocol      WebCore::JSLocation::Protocol                      DontDelete
  search        WebCore::JSLocation::Search                        DontDelete
  toString      &WebCore::JSLocationProtoFuncToString::create      DontEnum|DontDelete|Function 0
  replace       &WebCore::JSLocationProtoFuncReplace::create       DontDelete|Function 1
  reload        &WebCore::JSLocationProtoFuncReload::create        DontDelete|Function 0
@end
*/

JSLocation::JSLocation(JSObject* /*prototype*/, Frame* frame)
    : DOMObject(jsNull()) // FIXME: this needs to take a real prototype
    , m_frame(frame)
{
}

JSValue* JSLocation::getValueProperty(ExecState* exec, int token) const
{
  const KURL& url = m_frame->loader()->url();
  switch (token) {
  case Hash:
    return jsString(url.ref().isNull() ? "" : "#" + url.ref());
  case Host: {
    // Note: this is the IE spec. The NS spec swaps the two, it says
    // "The hostname property is the concatenation of the host and port properties, separated by a colon."
    // Bleh.
    UString str = url.host();
    if (url.port())
        str += ":" + String::number((int)url.port());
    return jsString(str);
  }
  case Hostname:
    return jsString(url.host());
  case Href:
    if (!url.hasPath())
      return jsString(url.prettyURL() + "/");
    return jsString(url.prettyURL());
  case Pathname:
    return jsString(url.path().isEmpty() ? "/" : url.path());
  case Port:
    return jsString(url.port() ? String::number((int)url.port()) : "");
  case Protocol:
    return jsString(url.protocol() + ":");
  case Search:
    return jsString(url.query());
  default:
    ASSERT_NOT_REACHED();
    return jsUndefined();
  }
}

bool JSLocation::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
  if (!m_frame)
    return false;

  const Window* window = Window::retrieveWindow(m_frame);

  const HashEntry* entry = Lookup::findEntry(&JSLocationTable, propertyName);
  if (!entry || !(entry->attr & KJS::Function) || (entry->value.functionValue != &JSLocationProtoFuncReplace::create
                                                   && entry->value.functionValue != &JSLocationProtoFuncReload::create
                                                   && entry->value.functionValue != &JSLocationProtoFuncAssign::create))  {
    if (!window || !window->allowsAccessFrom(exec)) {
      slot.setUndefined(this);
      return true;
    }
  }

  return getStaticPropertySlot<JSLocation, JSObject>(exec, &JSLocationTable, this, propertyName, slot);
}

void JSLocation::put(ExecState* exec, const Identifier& propertyName, JSValue* value, int attr)
{
  if (!m_frame)
    return;

  DeprecatedString str = value->toString(exec);
  KURL url = m_frame->loader()->url();
  const Window* window = Window::retrieveWindow(m_frame);
  bool sameDomainAccess = window && window->allowsAccessFrom(exec);

  const HashEntry* entry = Lookup::findEntry(&JSLocationTable, propertyName);

  if (entry) {
      // cross-domain access to the location is allowed when assigning the whole location,
      // but not when assigning the individual pieces, since that might inadvertently
      // disclose other parts of the original location.
      if (entry->value.intValue != Href && !sameDomainAccess)
          return;

      switch (entry->value.intValue) {
      case Href: {
          Frame* frame = Window::retrieveActive(exec)->impl()->frame();
          if (!frame)
              return;
          if (!frame->loader()->shouldAllowNavigation(m_frame))
              return;
          url = frame->loader()->completeURL(str);
          break;
      }
      case Hash: {
          if (str.startsWith("#"))
              str = str.mid(1);
          if (url.ref() == str)
              return;
          url.setRef(str);
          break;
      }
      case Host: {
          url.setHostAndPort(str);
          break;
      }
      case Hostname:
          url.setHost(str);
          break;
      case Pathname:
          url.setPath(str);
          break;
      case Port:
          url.setPort(str.toUInt());
          break;
      case Protocol:
          url.setProtocol(str);
          break;
      case Search:
          url.setQuery(str);
          break;
      default:
          // Disallow changing other properties in JSLocationTable. e.g., "window.location.toString = ...".
          // <http://bugs.webkit.org/show_bug.cgi?id=12720>
          return;
      }
  } else {
      if (sameDomainAccess)
          JSObject::put(exec, propertyName, value, attr);
      return;
  }

  Frame* activeFrame = Window::retrieveActive(exec)->impl()->frame();
  if (!url.deprecatedString().startsWith("javascript:", false) || sameDomainAccess) {
    bool userGesture = activeFrame->scriptProxy()->processingUserGesture();
    m_frame->loader()->scheduleLocationChange(url.string(), activeFrame->loader()->outgoingReferrer(), false, userGesture);
  }
}

JSValue* JSLocationProtoFuncReplace::callAsFunction(ExecState* exec, JSObject* thisObj, const List& args)
{
    if (!thisObj->inherits(&JSLocation::info))
        return throwError(exec, TypeError);
    JSLocation* location = static_cast<JSLocation*>(thisObj);
    Frame* frame = location->frame();
    if (!frame)
        return jsUndefined();

    Frame* activeFrame = Window::retrieveActive(exec)->impl()->frame();
    if (activeFrame) {
        if (!activeFrame->loader()->shouldAllowNavigation(frame))
            return jsUndefined();
        DeprecatedString str = args[0]->toString(exec);
        const Window* window = Window::retrieveWindow(frame);
        if (!str.startsWith("javascript:", false) || (window && window->allowsAccessFrom(exec))) {
            bool userGesture = activeFrame->scriptProxy()->processingUserGesture();
            frame->loader()->scheduleLocationChange(activeFrame->loader()->completeURL(str).string(), activeFrame->loader()->outgoingReferrer(), true, userGesture);
        }
    }

    return jsUndefined();
}

JSValue* JSLocationProtoFuncReload::callAsFunction(ExecState* exec, JSObject* thisObj, const List& args)
{
    if (!thisObj->inherits(&JSLocation::info))
        return throwError(exec, TypeError);
    JSLocation* location = static_cast<JSLocation*>(thisObj);
    Frame* frame = location->frame();
    if (!frame)
        return jsUndefined();

    Window* window = Window::retrieveWindow(frame);
    if (!window->allowsAccessFrom(exec))
        return jsUndefined();

    if (!frame->loader()->url().deprecatedString().startsWith("javascript:", false) || (window && window->allowsAccessFrom(exec))) {
        bool userGesture = Window::retrieveActive(exec)->impl()->frame()->scriptProxy()->processingUserGesture();
        frame->loader()->scheduleRefresh(userGesture);
    }
    return jsUndefined();
}

JSValue* JSLocationProtoFuncAssign::callAsFunction(ExecState* exec, JSObject* thisObj, const List& args)
{
    if (!thisObj->inherits(&JSLocation::info))
        return throwError(exec, TypeError);
    JSLocation* location = static_cast<JSLocation*>(thisObj);
    Frame* frame = location->frame();
    if (!frame)
        return jsUndefined();

    Frame* activeFrame = Window::retrieveActive(exec)->impl()->frame();
    if (activeFrame) {
        if (!activeFrame->loader()->shouldAllowNavigation(frame))
            return jsUndefined();
        const Window* window = Window::retrieveWindow(frame);
        String dstUrl = activeFrame->loader()->completeURL(args[0]->toString(exec)).string();
        if (!dstUrl.startsWith("javascript:", false) || (window && window->allowsAccessFrom(exec))) {
            bool userGesture = activeFrame->scriptProxy()->processingUserGesture();
            // We want a new history item if this JS was called via a user gesture
            frame->loader()->scheduleLocationChange(dstUrl, activeFrame->loader()->outgoingReferrer(), false, userGesture);
        }
    }

    return jsUndefined();
}

JSValue* JSLocationProtoFuncToString::callAsFunction(ExecState* exec, JSObject* thisObj, const List& args)
{
    if (!thisObj->inherits(&JSLocation::info))
        return throwError(exec, TypeError);
    JSLocation* location = static_cast<JSLocation*>(thisObj);
    Frame* frame = location->frame();
    if (!frame)
        return jsUndefined();

    const KURL& url = frame->loader()->url();
    if (!url.hasPath())
        return jsString(url.prettyURL() + "/");
    return jsString(url.prettyURL());
}

} // namespace WebCore
