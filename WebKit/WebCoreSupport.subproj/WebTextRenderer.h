//
//  IFTextRenderer.h
//  WebKit
//
//  Created by Darin Adler on Thu May 02 2002.
//  Copyright (c) 2002 Apple Computer, Inc. All rights reserved.
//

#import <WebCoreTextRenderer.h>
#import <QD/ATSUnicodePriv.h>

typedef float IFGlyphWidth;


typedef struct _WidthMap {
    ATSGlyphRef startRange;
    ATSGlyphRef endRange;
    struct _WidthMap *next;
    IFGlyphWidth *widths;
} WidthMap;

typedef struct _GlyphMap {
    UniChar startRange;
    UniChar endRange;
    struct _GlyphMap *next;
    ATSGlyphRef *glyphs;
} GlyphMap;

@interface IFTextRenderer : NSObject <WebCoreTextRenderer>
{
@public
    NSFont *font;
    int ascent;
    int descent;
    int lineSpacing;
    
    ATSStyleGroupPtr styleGroup;
    unsigned int widthCacheSize;
    IFGlyphWidth *widthCache;
    GlyphMap *characterToGlyphMap;
    WidthMap *glyphToWidthMap;
    
    NSArray *substituteFontRenderers;
}

- initWithFont:(NSFont *)font;
- (void)convertCharacters: (const unichar *)characters length: (int)numCharacters glyphs: (ATSGlyphVector *)glyphs;
- (ATSGlyphRef)extendCharacterToGlyphMapToInclude:(UniChar) c;
- (WidthMap *)extendGlyphToWidthMapToInclude:(ATSGlyphRef)glyphID;


@end
