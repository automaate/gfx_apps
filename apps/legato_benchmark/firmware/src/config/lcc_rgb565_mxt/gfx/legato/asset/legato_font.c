#include "gfx/legato/asset/legato_font.h"

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/common/legato_rect.h"
#include "gfx/legato/renderer/legato_renderer.h"

int32_t getGlyphRowDataSize1bpp(int32_t width)
{
    int32_t offset;
    
    offset = width >> 3;
    offset += (width % 8) > 0 ? 1 : 0;
    
    return offset;
}
                            
int32_t getGlyphRowDataSize8bpp(int32_t width)
{
    return width;
} 

typedef int32_t (*getGlyphRowDataSize_FnPtr)(int32_t);
                                         
getGlyphRowDataSize_FnPtr glyphRowDataSizeFn[] =
{
    &getGlyphRowDataSize1bpp,
    &getGlyphRowDataSize8bpp
};

/*static int32_t getGlyphRowDataSize(leFontBPP bpp,
                                   int32_t width)
{
    return glyphRowDataSizeFn[bpp](width);
}*/

/*static leResult getLookupTableEntry(uint8_t* table,
                                    uint32_t index,
                                    uint32_t max,
                                    uint32_t* offset,
                                    uint32_t* width)
{
    uint32_t dataSize = table[0];
    uint32_t widthSize = table[1];
    uint32_t offs, wdth;
    uint32_t i;
    
    table += 2; // advance past table header data
    
    if(index >= max)
        return LE_FAILURE;
    
    table += index * (dataSize + 1);
    
    offs = 0;
    
    for(i = 0; i < dataSize; i++)
    {
        offs |= (table[i] << (8 * i)); 
    }
    
    *offset = offs;
    
    table += dataSize;
    
    wdth = 0;
    
    for(i = 0; i < widthSize; i++)
    {
        wdth |= (table[i] << (8 * i)); 
    }
    
    *width = wdth;
    
    return LE_SUCCESS;
}*/

typedef void (*drawGlyphRow_FnPtr)(uint8_t*,
                                   //int32_t,
                                   int32_t,
                                   int32_t,
                                   int32_t,
                                   int32_t,
                                   leColor,
                                   uint32_t a);

void drawGlyphRow1bpp(uint8_t* data, 
                      //int32_t width,
                      int32_t x,
                      int32_t y,
                      int32_t colStart,
                      int32_t colEnd,
                      leColor clr,
                      uint32_t a)
{
    int32_t i;
    uint32_t offs;
    uint8_t val;
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        for(i = colStart; i < colEnd; i++)
        {
            offs = (i % 8);
            
            val = data[i >> 3] & (0x80 >> offs);
            
            if(val > 0)
            {
                leRenderer_BlendPixel(x + i, y, clr, a);
            }
        }
    }
    else
    {
        for(i = colStart; i < colEnd; i++)
        {
            offs = (i % 8);
            
            val = data[i >> 3] & (0x80 >> offs);
            
            if(val > 0)
            {
                leRenderer_PutPixel(x + i, y, clr);
            }
        }
    }
}
                            
void drawGlyphRow8bpp(uint8_t* data,
                      //int32_t width,
                      int32_t x,
                      int32_t y,
                      int32_t colStart,
                      int32_t colEnd,
                      leColor clr,
                      uint32_t a)
{
    int32_t i;
    uint32_t valPercent;
    uint32_t aPercent;
    
    a = leClampi(0, 255, a);
    
    if(a < 255)
    {
        aPercent = lePercentWholeRounded(a, 255);
        
        for(i = colStart; i < colEnd; i++)
        {
            if(data[i] > 0)
            {
                valPercent = lePercentWholeRounded(data[i], 255);
                valPercent = lePercentOf(aPercent, valPercent);
                valPercent = lePercentOf(valPercent, 255);
            
                leRenderer_BlendPixel(x + i, y, clr, valPercent);
            }
        }
    }
    else
    {
        for(i = colStart; i < colEnd; i++)
        {
            if(data[i] > 0)
            {
                leRenderer_BlendPixel(x + i, y, clr, data[i]);
            }
        }
    }
} 
                                         
drawGlyphRow_FnPtr drawGlyphRowFn[] =
{
    &drawGlyphRow1bpp,
    &drawGlyphRow8bpp
};

void leFont_DrawGlyphRow(leFontBPP bpp,
                         uint8_t* data,
                         int32_t x,
                         int32_t y,
                         int32_t colStart,
                         int32_t colEnd,
                         leColor clr,
                         uint32_t a)
{
    drawGlyphRowFn[bpp](data, x, y, colStart, colEnd, clr, a);
}

leResult leFont_GetGlyphInfo(leFont* fnt,
                             uint32_t codepoint,
                             leFontGlyph* glyph)
{
    uint32_t idx = 0;
    uint32_t glyphCount;
    leFontGlyph* glyphTable;
    
    LE_ASSERT(fnt != NULL && fnt->glyphTable != NULL);
        
    glyphCount = ((uint32_t*)fnt->glyphTable)[0];
    glyphTable = (leFontGlyph*)(fnt->glyphTable + sizeof(uint32_t));
    
    // attempt to find the glyph in the range lookup tables
    for(idx = 0; idx < glyphCount; idx++)
    {
        
        /* O1 linear search, faster searches could be implemented but would require more 
           memory */
        if(codepoint == glyphTable[idx].codePoint)
        {
            *glyph = glyphTable[idx];
            
            return LE_SUCCESS;
        }
    }
    
    if(codepoint == 0x20)
    {
        // return space glyph
        glyph->codePoint = 0x20;
        glyph->width = glyph->width;
        glyph->height = 0; 
        glyph->advance = glyph->width;
        glyph->bearingX = 0;
        glyph->bearingY = 0;
        glyph->dataOffset = 0;
        glyph->dataRowWidth = 0;
    }
    else
    {
        // return unknown glyph
        glyph->codePoint = -1;
        glyph->width = fnt->height >> 1;
        glyph->height = fnt->height; 
        glyph->advance = glyph->width;
        glyph->bearingX = 0;
        glyph->bearingY = 0;
        glyph->dataOffset = 0;
        glyph->dataRowWidth = 0;
    }
    
    return LE_FAILURE;
}

leResult leFont_GetGlyphRect(leFont* fnt,
                             uint32_t codepoint,
                             leFontGlyph* glyph,
                             leRect* rect)
{   
    LE_ASSERT(fnt != NULL && fnt->glyphTable != NULL);
    
    leFont_GetGlyphInfo(fnt, codepoint, glyph);
    
    rect->x = 0;
    rect->y = 0;
    rect->width = glyph->width;
    rect->height = glyph->height;
    
    return LE_SUCCESS;
}

static void drawUnknownGlyph(int32_t x,
                             int32_t y,
                             leFontGlyph* glyph,
                             leColor clr,
                             uint32_t a)
{
    leRect glyphRect;
    
    glyphRect.x = x;
    glyphRect.y = y;
    glyphRect.width = glyph->width - 1;
    glyphRect.height = glyph->height - 1;
    
    /*leRenderer_RectFill(&glyphRect,
                        leColorValue(LE_COLOR_MODE_RGB_565, LE_COLOR_RED),
                        255);*/
    
    if(leRenderer_CullDrawRect(&glyphRect) == LE_TRUE)
        return;
    
    // left line
    leRenderer_VertLine(x,
                        y,
                        glyph->height - 1,
                        clr,
                        a);
    
    // right line
    leRenderer_VertLine(x + glyph->width - 1,
                        y,
                        glyph->height - 1,
                        clr,
                        a);     
    
    // top line
    leRenderer_HorzLine(x,
                        y,
                        glyph->width - 1,
                        clr,
                        a);     
    
    // bottom line
    leRenderer_HorzLine(x,
                        y + glyph->height - 1,
                        glyph->width - 1,
                        clr,
                        a);     
}

void drawGlyph(leFont* fnt,
               leFontGlyph* glyph,
               int32_t x,
               int32_t y,
               leColor clr,
               uint32_t a)
{
    int32_t row;
    uint8_t* data;
    leRect glyphRect;
    leRect clippedGlyph;
    int32_t colStart, colEnd;
    
    //x += glyph->bearingX;
    //y += (fnt->baseline - glyph->bearingY);
    
    glyphRect.x = x;
    glyphRect.y = y;
    glyphRect.width = glyph->width;
    glyphRect.height = glyph->height;
    
    if(leRenderer_CullDrawRect(&glyphRect) == LE_TRUE)
        return;
    
    leRenderer_ClipDrawRect(&glyphRect, &clippedGlyph);
    
    data = ((uint8_t*)fnt->header.dataAddress);
    data += glyph->dataOffset;
    
    if(x >= clippedGlyph.x)
    {
        colStart = 0;
    }
    else
    {
        colStart = clippedGlyph.x - x;
    }
        
    if(x + (int32_t)glyph->width <= clippedGlyph.x + clippedGlyph.width)
    {
        colEnd = glyph->width;
    }
    else
    {
        colEnd = glyph->width + ((clippedGlyph.x + clippedGlyph.width) - (x + (int32_t)glyph->width));
    }
    
    for(row = clippedGlyph.y - glyphRect.y; row < (clippedGlyph.y - glyphRect.y) + (clippedGlyph.height); row++)
    {
        drawGlyphRowFn[fnt->bpp](data + (row * glyph->dataRowWidth),
                                 x,
                                 y + row,
                                 colStart,
                                 colEnd,
                                 clr,
                                 a);
    }
}

void leFont_DrawGlyph(leFont* fnt,
                      leFontGlyph* glyph,
                      int32_t x,
                      int32_t y,
                      leColor clr,
                      uint32_t a)
{
    
    
    // attempt to find the glyph raster data
    // if no data found then draw empty rectangle
    if(glyph->codePoint == -1)
    {
        drawUnknownGlyph(x, y, glyph, clr, a);
    }
    else
    {    
        drawGlyph(fnt, glyph, x, y, clr, a);
    }
}



       




