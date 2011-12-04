/*
 * This file is part of the WebKit project.
 *
 * Copyright (C) 2006 Dirk Mueller <mueller@kde.org>
 *               2006 Nikolas Zimmermann <zimmermann@kde.org>
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

#include "config.h"

#include "GraphicsContext.h"
#include "RenderTheme.h"
#include "NotImplemented.h"

namespace WebCore {

    class RenderThemeMona : public RenderTheme {
    private:
        RenderThemeMona();
        virtual ~RenderThemeMona();

    public:
        static PassRefPtr<RenderTheme> create();

        // A method asking if the theme's controls actually care about redrawing when hovered.
        virtual bool supportsHover(const RenderStyle* style) const { return false; }

        // A method asking if the theme is able to draw the focus ring.
        virtual bool supportsFocusRing(const RenderStyle*) const;

        // The platform selection color.
        virtual Color platformActiveSelectionBackgroundColor() const;
        virtual Color platformInactiveSelectionBackgroundColor() const;
        virtual Color platformActiveSelectionForegroundColor() const;
        virtual Color platformInactiveSelectionForegroundColor() const;

        virtual Color platformTextSearchHighlightColor() const;

        // System fonts.
        virtual void systemFont(int propId, FontDescription&) const;

    protected:
        virtual bool paintCheckbox(RenderObject*, const PaintInfo&, const IntRect&);
        virtual void setCheckboxSize(RenderStyle*) const;

        virtual bool paintRadio(RenderObject*, const PaintInfo&, const IntRect&);
        virtual void setRadioSize(RenderStyle*) const;

        virtual void adjustMenuListStyle(CSSStyleSelector*, RenderStyle*, Element*) const;
        virtual bool paintMenuList(RenderObject*, const PaintInfo&, const IntRect&);
    };

PassRefPtr<RenderTheme> RenderThemeMona::create()
{
    return adoptRef(new RenderThemeMona());
}

PassRefPtr<RenderTheme> RenderTheme::themeForPage(Page*)
{
    static RenderTheme* renderTheme = RenderThemeMona::create().releaseRef();
    return renderTheme;
}

RenderThemeMona::RenderThemeMona()
{
}

RenderThemeMona::~RenderThemeMona()
{
}

static bool supportsFocus(ControlPart appearance)
{
    switch (appearance) {
    case PushButtonPart:
    case ButtonPart:
    case TextFieldPart:
    case TextAreaPart:
    case SearchFieldPart:
    case MenulistPart:
    case RadioPart:
    case CheckboxPart:
        return true;
    default:
        return false;
    }
}

bool RenderThemeMona::supportsFocusRing(const RenderStyle* style) const
{
    return supportsFocus(style->appearance());
}

Color RenderThemeMona::platformActiveSelectionBackgroundColor() const
{
    return Color::black;
}

Color RenderThemeMona::platformInactiveSelectionBackgroundColor() const
{
    return Color::black;
}

Color RenderThemeMona::platformActiveSelectionForegroundColor() const
{
    return Color::white;
}

Color RenderThemeMona::platformInactiveSelectionForegroundColor() const
{
    return Color::white;
}

Color RenderThemeMona::platformTextSearchHighlightColor() const
{
    return Color::gray;
}

void RenderThemeMona::systemFont(int propId, FontDescription&) const
{
    notImplemented();
}

bool RenderThemeMona::paintCheckbox(RenderObject*, const PaintInfo& info, const IntRect& intRect)
{
    notImplemented();
    return false;
    // if (info.context->paintingDisabled())
    //     return false;

    // rgb_color base = ui_color(B_PANEL_BACKGROUND_COLOR);
    // BRect rect = intRect;
    // BView* view = info.context->platformContext();

    // if (!be_control_look)
    //     return false;

    // be_control_look->DrawCheckBox(view, rect, rect, base);
    // return true;
}

void RenderThemeMona::setCheckboxSize(RenderStyle* style) const
{
    notImplemented();
    int size = 10;

    // // If the width and height are both specified, then we have nothing to do.
    // if (!style->width().isIntrinsicOrAuto() && !style->height().isAuto())
    //     return;

    // // FIXME: A hard-coded size of 'size' is used. This is wrong but necessary for now.
    // if (style->width().isIntrinsicOrAuto())
    //     style->setWidth(Length(size, Fixed));

    // if (style->height().isAuto())
    //     style->setHeight(Length(size, Fixed));
}

bool RenderThemeMona::paintRadio(RenderObject*, const PaintInfo& info, const IntRect& intRect)
{
    notImplemented();
    return false;
    // if (info.context->paintingDisabled())
    //     return false;

    // rgb_color base = ui_color(B_PANEL_BACKGROUND_COLOR);
    // BRect rect = intRect;
    // BView* view = info.context->platformContext();

    // if (!be_control_look)
    //     return false;

    // be_control_look->DrawRadioButton(view, rect, rect, base);
    // return true;
}

void RenderThemeMona::setRadioSize(RenderStyle* style) const
{
    // This is the same as checkboxes.
    setCheckboxSize(style);
}

void RenderThemeMona::adjustMenuListStyle(CSSStyleSelector*, RenderStyle* style, Element*) const
{
    // Leave some space for the arrow.
    style->setPaddingRight(Length(22, Fixed));
    const int minHeight = 20;
    style->setMinHeight(Length(minHeight, Fixed));
}

bool RenderThemeMona::paintMenuList(RenderObject*, const PaintInfo&, const IntRect&)
{
    notImplemented();
    return false;
}


// PassRefPtr<RenderTheme> RenderTheme::themeForPage(Page*)
// {
//   return adoptRef(new RenderThemeMona());
// }

} // namespace WebCore
