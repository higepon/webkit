/*
 * Copyright (C) 2010 Stephan Aßmus <superstippi@gmx.de>
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
#include "CookieJarClientHaiku.h"

#include "Cookie.h"
#include "KURL.h"
#include "NetworkCookieJar.h"
#include "NotImplemented.h"
#include "PlatformString.h"


namespace WebCore {

CookieJarClientHaiku::CookieJarClientHaiku(BNetworkCookieJar* cookieJar)
    : m_cookieJar(cookieJar)
{
}

String CookieJarClientHaiku::cookies(const Document*, const KURL& url)
{
	return m_cookieJar->CookiesFor(url.string());
}

String CookieJarClientHaiku::cookieRequestHeaderFieldValue(const Document*,
    const KURL& url)
{
    return m_cookieJar->CookieRequestHeaderFieldValue(url.string());
}

void CookieJarClientHaiku::setCookies(Document*, const KURL& url,
    const String& value)
{
    m_cookieJar->SetCookiesFor(url.string(), value);
}

bool CookieJarClientHaiku::cookiesEnabled(const Document*)
{
    return m_cookieJar->CookiesEnabled();
}

bool CookieJarClientHaiku::getRawCookies(const Document*, const KURL& url,
    Vector<Cookie>& rawCookies)
{
	notImplemented();

    rawCookies.clear();
    return false;
}

void CookieJarClientHaiku::deleteCookie(const Document*, const KURL& url,
    const String& name)
{
	notImplemented();
}

} // namespace WebCore

