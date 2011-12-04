/*
 * Copyright (C) 2006 Zack Rusin <zack@kde.org>
 * Copyright (C) 2007 Ryan Leavengood <leavengood@gmail.com>
 * Copyright (c) 2011 Higepon(Taro Minowa) <higepon@users.sourceforge.jp>
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
#include "ContextMenuClientMona.h"

#include "ContextMenu.h"
#include "HitTestResult.h"
#include "KURL.h"

#include "NotImplemented.h"


namespace WebCore {

void ContextMenuClientMona::contextMenuDestroyed()
{
    notImplemented();
}

PlatformMenuDescription ContextMenuClientMona::getCustomMenuFromDefaultItems(ContextMenu* menu)
{
    return menu->platformDescription();
}

void ContextMenuClientMona::contextMenuItemSelected(ContextMenuItem*, const ContextMenu*)
{
    notImplemented();
}

void ContextMenuClientMona::downloadURL(const KURL& url)
{
    notImplemented();
}

void ContextMenuClientMona::lookUpInDictionary(Frame*)
{
    notImplemented();
}

void ContextMenuClientMona::speak(const String&)
{
    notImplemented();
}

bool ContextMenuClientMona::isSpeaking()
{
    notImplemented();
    return false;
}

void ContextMenuClientMona::stopSpeaking()
{
    notImplemented();
}

void ContextMenuClientMona::searchWithGoogle(const Frame*)
{
    notImplemented();
}

} // namespace WebCore

