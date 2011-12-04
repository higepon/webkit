/*
 * Copyright (C) 2011 Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
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
#include "ContextMenuItem.h"

#include "ContextMenu.h"
#include "NotImplemented.h"


using namespace WebCore;

ContextMenuItem::ContextMenuItem(PlatformMenuItemDescription item)
{
    m_platformDescription = item;
}

ContextMenuItem::ContextMenuItem(ContextMenu* subMenu)
{
  notImplemented();
}

ContextMenuItem::ContextMenuItem(ContextMenuItemType type, ContextMenuAction action,
                                 const String& title, ContextMenu* subMenu)
{
  notImplemented();
}

ContextMenuItem::~ContextMenuItem()
{
    delete m_platformDescription;
}

PlatformMenuItemDescription ContextMenuItem::releasePlatformDescription()
{
  notImplemented();
}

ContextMenuItemType ContextMenuItem::type() const
{
  notImplemented();
}

void ContextMenuItem::setType(ContextMenuItemType type)
{
  notImplemented();
}

ContextMenuAction ContextMenuItem::action() const
{
  notImplemented();
}

void ContextMenuItem::setAction(ContextMenuAction action)
{
  notImplemented();
}

String ContextMenuItem::title() const
{
  notImplemented();
}

void ContextMenuItem::setTitle(const String& title)
{
  notImplemented();
}

PlatformMenuDescription ContextMenuItem::platformSubMenu() const
{
  notImplemented();
}

void ContextMenuItem::setSubMenu(ContextMenu* menu)
{
  notImplemented();
}

void ContextMenuItem::setChecked(bool checked)
{
  notImplemented();
}

void ContextMenuItem::setEnabled(bool enable)
{
  notImplemented();
}

bool ContextMenuItem::enabled() const
{
  notImplemented();
}

