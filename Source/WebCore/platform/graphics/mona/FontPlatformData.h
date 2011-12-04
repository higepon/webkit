/*
 * Copyright (C) 2006 Apple Computer, Inc.
 * Copyright (C) 2006 Zack Rusin <zack@kde.org>
 * Copyright (C) 2006 Dirk Mueller <mueller@kde.org>
 * Copyright (C) 2006 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2007 Ryan Leavengood <leavengood@gmail.com>
 * Copyright (C) 2009 Maxime Simon <simon.maxime@gmail.com>
 *
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef FontPlatformData_h
#define FontPlatformData_h

#include "FontDescription.h"
#include "GlyphBuffer.h"
#include "notImplemented.h"
#include "wtf/PassOwnPtr.h"

namespace WebCore {

    class FontPlatformData {
    public:
      FontPlatformData(WTF::HashTableDeletedValueType) : m_data(-1), m_isEmptyValue(false), m_isDeleted(true)
      {
        notImplemented();
      }

        FontPlatformData() :  m_isEmptyValue(false), m_isDeleted(false)
      {
                notImplemented();
      }

      FontPlatformData(const FontDescription&, const AtomicString& family) :  m_data(1), m_isEmptyValue(false), m_isDeleted(true) {
        notImplemented();
      }

      // temporary for Mona. FontPlatformData::emptyValue()
      // FontPlatformData::emptyValue() should be distinguished from other FontPlatformData instance.
      FontPlatformData(float size, bool bold, bool oblique) : m_data(0), m_isEmptyValue(true) , m_isDeleted(true){
        notImplemented();
        if (!(!bold && !oblique && size == 0)) {
          m_data = 3;
        }
      }
      FontPlatformData(const FontPlatformData& x) : m_data(x.m_data) { m_isEmptyValue = x.m_isEmptyValue; m_isDeleted = x.m_isDeleted;notImplemented();}

      ~FontPlatformData() {
      }

//         BFont* font() const { return m_font; }

//         bool isFixedPitch(
      void setOrientation(FontOrientation) { notImplemented();} // FIXME: Implement.);
      String description() const { notImplemented(); return "hige"; }
        float size() const { return m_size; }
        bool bold() const { return m_bold; }
        bool oblique() const { return m_oblique; }
      FontOrientation orientation() const { notImplemented(); }
      unsigned hash() const { 
        notImplemented();
        if (!m_data)
          return 0;
        if (isHashTableDeletedValue())
          return 1;
        return m_data;
      }
      bool isHashTableDeletedValue() const { notImplemented(); return m_data == -1; }

      PassOwnPtr<SimpleFontData> createScaledFontData(const FontDescription&, float scaleFactor) const {
        notImplemented();
      }

      bool syntheticOblique() const { notImplemented(); }
      bool operator==(const FontPlatformData& y) const {
        notImplemented();
        if (m_data == y.m_data)
          return true;

        if (!m_data || !y.m_data
            || isHashTableDeletedValue() || y.isHashTableDeletedValue()) {
          return false;
        }
        return false;
      }
      cairo_scaled_font_t* scaledFont() const { notImplemented();; }

// #ifndef NDEBUG
//         String description() const;
// #endif

//         BFont* m_font;
      // temporary
      int8_t m_data;
        bool m_isEmptyValue;
        bool m_isDeleted;
        float m_size;
        bool m_bold;
        bool m_oblique;

//     private:
//         static BFont* hashTableDeletedFontValue() { return reinterpret_cast<BFont*>(-1); }
    };

} // namespace WebCore

#endif
