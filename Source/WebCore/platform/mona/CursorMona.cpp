/*
 * Copyright (C) 2011 Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
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
#include "Cursor.h"

#include "NotImplemented.h"

namespace WebCore {

Cursor::Cursor(PlatformCursor cursor)
    : m_platformCursor(cursor)
{
}

Cursor::Cursor(const Cursor& other)
    : m_platformCursor(0)
{
    *this = other;
}

Cursor::~Cursor()
{
    delete m_platformCursor;
}

Cursor::Cursor(Image*, const IntPoint&)
    : m_platformCursor(0)
{
    notImplemented();
}

Cursor& Cursor::operator=(const Cursor& other)
{
    delete m_platformCursor;
    //    m_platformCursor = other.m_platformCursor ? new BCursor(*other.m_platformCursor) : 0;
    notImplemented();
    return *this;
}

// static Cursor createCursorByID(BCursorID id)
// {
//   //    return Cursor(new BCursor(id));
//   notImplemented();
// }

const Cursor& pointerCursor()
{
    static Cursor cursorSystemDefault(0);
    return cursorSystemDefault;
}

const Cursor& moveCursor()
{
  //    static Cursor cursorMove = createCursorByID(B_CURSOR_ID_MOVE);
  notImplemented();
  //    return cursorMove;
}

const Cursor& crossCursor()
{
    // static Cursor cursorCrossHair = createCursorByID(B_CURSOR_ID_CROSS_HAIR);
    // return cursorCrossHair;
  notImplemented();
}

const Cursor& handCursor()
{
    // static Cursor cursorFollowLink = createCursorByID(B_CURSOR_ID_FOLLOW_LINK);
    // return cursorFollowLink;
  notImplemented();
}

const Cursor& iBeamCursor()
{
    // static Cursor cursorIBeam = createCursorByID(B_CURSOR_ID_I_BEAM);
    // return cursorIBeam;
  notImplemented();
}

const Cursor& waitCursor()
{
    // static Cursor cursorProgress = createCursorByID(B_CURSOR_ID_PROGRESS);
    // return cursorProgress;
  notImplemented();
}

const Cursor& helpCursor()
{
    // static Cursor cursorHelp = createCursorByID(B_CURSOR_ID_HELP);
    // return cursorHelp;
  notImplemented();
}

const Cursor& eastResizeCursor()
{
    // static Cursor cursorResizeEast = createCursorByID(B_CURSOR_ID_RESIZE_EAST);
    // return cursorResizeEast;
  notImplemented();
}

const Cursor& northResizeCursor()
{
    // static Cursor cursorResizeNorth = createCursorByID(B_CURSOR_ID_RESIZE_NORTH);
    // return cursorResizeNorth;
  notImplemented();
}

const Cursor& northEastResizeCursor()
{
    // static Cursor cursorResizeNorthEast = createCursorByID(B_CURSOR_ID_RESIZE_NORTH_EAST);
    // return cursorResizeNorthEast;
  notImplemented();
}

const Cursor& northWestResizeCursor()
{
    // static Cursor cursorResizeNorthWest = createCursorByID(B_CURSOR_ID_RESIZE_NORTH_WEST);
    // return cursorResizeNorthWest;
  notImplemented();
}

const Cursor& southResizeCursor()
{
    // static Cursor cursorResizeSouth = createCursorByID(B_CURSOR_ID_RESIZE_SOUTH);
    // return cursorResizeSouth;
  notImplemented();
}

const Cursor& southEastResizeCursor()
{
    // static Cursor cursorResizeSouthEast = createCursorByID(B_CURSOR_ID_RESIZE_SOUTH_EAST);
    // return cursorResizeSouthEast;
  notImplemented();
}

const Cursor& southWestResizeCursor()
{
    // static Cursor cursorResizeSouthWest = createCursorByID(B_CURSOR_ID_RESIZE_SOUTH_WEST);
    // return cursorResizeSouthWest;
  notImplemented();
}

const Cursor& westResizeCursor()
{
    // static Cursor cursorResizeWest = createCursorByID(B_CURSOR_ID_RESIZE_WEST);
    // return cursorResizeWest;
  notImplemented();
}

const Cursor& northSouthResizeCursor()
{
    // static Cursor cursorResizeNorthSouth = createCursorByID(B_CURSOR_ID_RESIZE_NORTH_SOUTH);
    // return cursorResizeNorthSouth;
  notImplemented();
}

const Cursor& eastWestResizeCursor()
{
    // static Cursor cursorResizeEastWest = createCursorByID(B_CURSOR_ID_RESIZE_EAST_WEST);
    // return cursorResizeEastWest;
  notImplemented();
}

const Cursor& northEastSouthWestResizeCursor()
{
    // static Cursor cursorResizeNorthEastSouthWest = createCursorByID(B_CURSOR_ID_RESIZE_NORTH_EAST_SOUTH_WEST);
    // return cursorResizeNorthEastSouthWest;
}

const Cursor& northWestSouthEastResizeCursor()
{
    // static Cursor cursorResizeNorthWestSouthEast = createCursorByID(B_CURSOR_ID_RESIZE_NORTH_WEST_SOUTH_EAST);
    // return cursorResizeNorthWestSouthEast;
  notImplemented();
}

const Cursor& columnResizeCursor()
{
    return eastWestResizeCursor();
}

const Cursor& rowResizeCursor()
{
    return northSouthResizeCursor();
}

const Cursor& verticalTextCursor()
{
    // static Cursor cursorIBeamHorizontal = createCursorByID(B_CURSOR_ID_I_BEAM_HORIZONTAL);
    // return cursorIBeamHorizontal;
  notImplemented();
}

const Cursor& cellCursor()
{
    return pointerCursor();
}

const Cursor& contextMenuCursor()
{
    // static Cursor cursorContextMenu = createCursorByID(B_CURSOR_ID_CONTEXT_MENU);
    // return cursorContextMenu;
  notImplemented();
}

const Cursor& noDropCursor()
{
    // static Cursor cursorNotAllowed = createCursorByID(B_CURSOR_ID_NOT_ALLOWED);
    // return cursorNotAllowed;
  notImplemented();
}

const Cursor& copyCursor()
{
    // static Cursor cursorCopy = createCursorByID(B_CURSOR_ID_COPY);
    // return cursorCopy;
  notImplemented();
}

const Cursor& progressCursor()
{
    // static Cursor cursorProgress = createCursorByID(B_CURSOR_ID_PROGRESS);
    // return cursorProgress;
  notImplemented();
}

const Cursor& aliasCursor()
{
    return handCursor();
}

const Cursor& noneCursor()
{
    // static Cursor cursorNoCursor = createCursorByID(B_CURSOR_ID_NO_CURSOR);
    // return cursorNoCursor;
  notImplemented();
}

const Cursor& notAllowedCursor()
{
    // static Cursor cursorNotAllowed = createCursorByID(B_CURSOR_ID_NOT_ALLOWED);
    // return cursorNotAllowed;
  notImplemented();
}

const Cursor& zoomInCursor()
{
    // static Cursor cursorZoomIn = createCursorByID(B_CURSOR_ID_ZOOM_IN);
    // return cursorZoomIn;
  notImplemented();
}

const Cursor& zoomOutCursor()
{
    // static Cursor cursorZoomOut = createCursorByID(B_CURSOR_ID_ZOOM_OUT);
    // return cursorZoomOut;
  notImplemented();
}

const Cursor& grabCursor()
{
    // static Cursor cursorGrab = createCursorByID(B_CURSOR_ID_GRAB);
    // return cursorGrab;
  notImplemented();
}

const Cursor& grabbingCursor()
{
    // static Cursor cursorGrabbing = createCursorByID(B_CURSOR_ID_GRABBING);
    // return cursorGrabbing;
  notImplemented();
}

} // namespace WebCore

