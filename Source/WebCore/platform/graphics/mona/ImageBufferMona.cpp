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
#include "ImageBuffer.h"

#include "Base64.h"
#include "GraphicsContext.h"
#include "ImageData.h"
#include "MIMETypeRegistry.h"
#include "StillImageMona.h"
#include "NotImplemented.h"
#include <wtf/text/CString.h>
#include <wtf/text/WTFString.h>
#include "IntSize.h"

namespace WebCore {

ImageBufferData::ImageBufferData(const IntSize& size)
{
    notImplemented();
}

ImageBufferData::~ImageBufferData()
{
    notImplemented();
}

// ImageBuffer::ImageBuffer(const IntSize& size, ImageColorSpace imageColorSpace, RenderingMode, bool& success)
// {
//     notImplemented();
// }
ImageBuffer::~ImageBuffer()
{
    notImplemented();
}

size_t ImageBuffer::dataSize() const
{
    notImplemented();
}

GraphicsContext* ImageBuffer::context() const
{
    notImplemented();
}

// Image* ImageBuffer::image() const
// {
//     notImplemented();
// }

void ImageBuffer::platformTransformColorSpace(const Vector<int>& lookUpTable)
{
    notImplemented();
}

static inline void convertFromData(const uint8_t* sourceRows, unsigned sourceBytesPerRow,
                                   uint8_t* destRows, unsigned destBytesPerRow,
                                   unsigned rows, unsigned columns)
{
    notImplemented();
}

static inline void convertFromInternalData(const uint8_t* sourceRows, unsigned sourceBytesPerRow,
                                           uint8_t* destRows, unsigned destBytesPerRow,
                                           unsigned rows, unsigned columns,
                                           bool premultiplied)
{
    notImplemented();
}

static inline void convertToInternalData(const uint8_t* sourceRows, unsigned sourceBytesPerRow,
                                         uint8_t* destRows, unsigned destBytesPerRow,
                                         unsigned rows, unsigned columns,
                                         bool premultiplied)
{
    notImplemented();
}

static PassRefPtr<ImageData> getImageData(const IntRect& rect, const ImageBufferData& imageData, const IntSize& size, bool premultiplied)
{
    notImplemented();
}

PassRefPtr<WTF::ByteArray> ImageBuffer::getUnmultipliedImageData(const WebCore::IntRect&) const
{
    notImplemented();
}

WTF::PassRefPtr<WTF::ByteArray> ImageBuffer::getPremultipliedImageData(const IntRect&) const
{
    notImplemented();
}

static void putImageData(ImageData* source, const IntRect& sourceRect, const IntPoint& destPoint, ImageBufferData& imageData, const IntSize& size, bool premultiplied)
{
    notImplemented();
}

void ImageBuffer::putUnmultipliedImageData(WTF::ByteArray*, const WebCore::IntSize&, const WebCore::IntRect&, const WebCore::IntPoint&)
{
    notImplemented();
}

void ImageBuffer::putPremultipliedImageData(WTF::ByteArray*, const WebCore::IntSize&, const WebCore::IntRect&, const WebCore::IntPoint&)
{
    notImplemented();
}

String ImageBuffer::toDataURL(const String& mimeType, const double*) const
{
    notImplemented();
}

} // namespace WebCore

