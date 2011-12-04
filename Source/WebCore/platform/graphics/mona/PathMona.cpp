/*
 * Copyright (C) 2011 Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
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
#include "Path.h"

#include "AffineTransform.h"
#include "FloatRect.h"
#include "NotImplemented.h"
#include "PlatformString.h"
#include <Region.h>


namespace WebCore {

Path::Path()
{
    notImplemented();
}

Path::~Path()
{
}

Path::Path(const Path& other)
{
    notImplemented();
}

Path& Path::operator=(const Path& other)
{
    notImplemented();
}

bool Path::hasCurrentPoint() const
{
}

FloatPoint Path::currentPoint() const 
{
    notImplemented();
}

bool Path::contains(const FloatPoint& point, WindRule rule) const
{
    notImplemented();
}

void Path::translate(const FloatSize& size)
{
    notImplemented();
}

FloatRect Path::boundingRect() const
{
    notImplemented();
}

void Path::moveTo(const FloatPoint& point)
{
    // FIXME: Use OffsetBy?
    notImplemented();
}

void Path::addLineTo(const FloatPoint& p)
{
    notImplemented();
}

void Path::addQuadCurveTo(const FloatPoint& cp, const FloatPoint& p)
{
    notImplemented();
}

void Path::addBezierCurveTo(const FloatPoint& cp1, const FloatPoint& cp2, const FloatPoint& p)
{
    notImplemented();
}

void Path::addArcTo(const FloatPoint& p1, const FloatPoint& p2, float radius)
{
    notImplemented();
}

void Path::closeSubpath()
{
    notImplemented();
}

void Path::addArc(const FloatPoint& p, float r, float sar, float ear, bool anticlockwise)
{
    notImplemented();
}

void Path::addRect(const FloatRect& r)
{
    notImplemented();
}

void Path::addEllipse(const FloatRect& r)
{
    notImplemented();
}

void Path::clear()
{
    notImplemented();
}

bool Path::isEmpty() const
{
    notImplemented();
}

void Path::apply(void* info, PathApplierFunction function) const
{
    notImplemented();
}

void Path::transform(const AffineTransform& transform)
{
    notImplemented();
}

FloatRect Path::strokeBoundingRect(StrokeStyleApplier* applier) const
{
    notImplemented();
    //    return FloatRect();
}

} // namespace WebCore

