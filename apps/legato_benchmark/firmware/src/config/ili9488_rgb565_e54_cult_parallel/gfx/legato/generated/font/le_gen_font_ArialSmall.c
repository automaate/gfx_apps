#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         ArialSmall
 * Height:       36
 * Baseline:     35
 * Style:        Plain
 * Glyph Count:  10
 * Range Count:  1
 * Glyph Ranges: 0x30-0x39
 *********************************/
/*********************************
 * font glyph kerning table description
 *
 * unsigned int - number of glyphs
 * for each glyph:
 *     unsigned short - codepoint         * the glyph's codepoint
 *     short          - width             * the glyph's width in pixels
 *     short          - height            * the glyph's height in pixels
 *     short          - advance           * the glyph's advance value in pixels
 *     short          - bearingX          * the glyph's bearing value in pixels on the X axis
 *     short          - bearingY          * the glyph's bearing value in pixels on the Y axis
 *     unsigned short - flags             * status flags for this glyph
 *     unsigned short - data row width    * the size of a row of glyph data in bytes
 *     unsigned int   - data table offset * the offset into the corresponding font data table
 ********************************/
const uint8_t ArialSmall_glyphs[204] =
{
    0x0A,0x00,0x00,0x00,0x30,0x00,0x18,0x00,0x23,0x00,0x1B,0x00,0x02,0x00,0x23,0x00,
    0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x0E,0x00,0x22,0x00,0x1B,0x00,
    0x04,0x00,0x22,0x00,0x00,0x00,0x02,0x00,0x69,0x00,0x00,0x00,0x32,0x00,0x17,0x00,
    0x23,0x00,0x1B,0x00,0x02,0x00,0x23,0x00,0x00,0x00,0x03,0x00,0xAD,0x00,0x00,0x00,
    0x33,0x00,0x17,0x00,0x23,0x00,0x1B,0x00,0x02,0x00,0x23,0x00,0x00,0x00,0x03,0x00,
    0x16,0x01,0x00,0x00,0x34,0x00,0x1A,0x00,0x22,0x00,0x1B,0x00,0x01,0x00,0x22,0x00,
    0x00,0x00,0x04,0x00,0x7F,0x01,0x00,0x00,0x35,0x00,0x16,0x00,0x22,0x00,0x1B,0x00,
    0x03,0x00,0x22,0x00,0x00,0x00,0x03,0x00,0x07,0x02,0x00,0x00,0x36,0x00,0x18,0x00,
    0x23,0x00,0x1B,0x00,0x02,0x00,0x23,0x00,0x00,0x00,0x03,0x00,0x6D,0x02,0x00,0x00,
    0x37,0x00,0x18,0x00,0x22,0x00,0x1B,0x00,0x02,0x00,0x22,0x00,0x00,0x00,0x03,0x00,
    0xD6,0x02,0x00,0x00,0x38,0x00,0x18,0x00,0x23,0x00,0x1B,0x00,0x02,0x00,0x23,0x00,
    0x00,0x00,0x03,0x00,0x3C,0x03,0x00,0x00,0x39,0x00,0x17,0x00,0x23,0x00,0x1B,0x00,
    0x02,0x00,0x23,0x00,0x00,0x00,0x03,0x00,0xA5,0x03,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t ArialSmall_data[1038] =
{
    0x00,0x00,0x00,0x01,0xFF,0x00,0x07,0xFF,0xC0,0x0F,0xFF,0xE0,0x1F,0x83,0xF0,0x1F,
    0x00,0xF8,0x3E,0x00,0x78,0x3C,0x00,0x78,0x7C,0x00,0x3C,0x78,0x00,0x3C,0x78,0x00,
    0x3C,0x78,0x00,0x3E,0x78,0x00,0x3E,0x78,0x00,0x1E,0xF8,0x00,0x1E,0xF8,0x00,0x1E,
    0xF8,0x00,0x1E,0xF8,0x00,0x1E,0xF8,0x00,0x1E,0xF8,0x00,0x1E,0xF8,0x00,0x1E,0x78,
    0x00,0x1E,0x78,0x00,0x1E,0x78,0x00,0x3E,0x78,0x00,0x3E,0x78,0x00,0x3C,0x7C,0x00,
    0x3C,0x3C,0x00,0x7C,0x3C,0x00,0x78,0x1E,0x00,0xF8,0x1F,0x01,0xF0,0x0F,0xFF,0xF0,
    0x07,0xFF,0xE0,0x03,0xFF,0x80,0x00,0xFE,0x00,0x00,0x78,0x00,0xF8,0x03,0xF8,0x07,
    0xF8,0x0F,0xF8,0x1F,0x78,0x3E,0x78,0x7C,0x78,0x78,0x78,0x30,0x78,0x00,0x78,0x00,
    0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,
    0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,
    0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x00,0x00,
    0x03,0xFF,0x00,0x0F,0xFF,0xC0,0x3F,0xFF,0xE0,0x7F,0x03,0xF0,0x7C,0x00,0xF8,0x30,
    0x00,0xF8,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,
    0x78,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0xF8,0x00,0x00,0xF0,0x00,0x01,0xF0,
    0x00,0x03,0xE0,0x00,0x07,0xC0,0x00,0x0F,0x80,0x00,0x1F,0x00,0x00,0x3F,0x00,0x00,
    0x3E,0x00,0x00,0x7C,0x00,0x00,0xF8,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00,0x07,0xC0,
    0x00,0x0F,0x80,0x00,0x1F,0x00,0x00,0x3E,0x00,0x00,0x7C,0x00,0x00,0xFF,0xFF,0xFE,
    0xFF,0xFF,0xFE,0xFF,0xFF,0xFE,0x00,0x00,0x00,0x07,0xFF,0x80,0x1F,0xFF,0xE0,0x7F,
    0xFF,0xF0,0x7E,0x03,0xF0,0x78,0x00,0xF8,0x20,0x00,0x78,0x00,0x00,0x7C,0x00,0x00,
    0x7C,0x00,0x00,0x7C,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0xF8,0x00,0x01,0xF0,
    0x00,0x07,0xE0,0x07,0xFF,0x80,0x07,0xFE,0x00,0x07,0xFF,0xC0,0x00,0x7F,0xF0,0x00,
    0x01,0xF8,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x3C,0x00,0x00,0x3E,0x00,0x00,
    0x3E,0x00,0x00,0x3E,0x00,0x00,0x3E,0x00,0x00,0x3C,0x00,0x00,0x7C,0x00,0x00,0xFC,
    0xE0,0x01,0xF8,0xFF,0xFF,0xF0,0xFF,0xFF,0xE0,0x7F,0xFF,0x80,0x0F,0xFE,0x00,0x00,
    0x00,0xF8,0x00,0x00,0x01,0xF8,0x00,0x00,0x03,0xF8,0x00,0x00,0x03,0xF8,0x00,0x00,
    0x07,0xF8,0x00,0x00,0x0F,0x78,0x00,0x00,0x0E,0x78,0x00,0x00,0x1E,0xF8,0x00,0x00,
    0x3C,0xF8,0x00,0x00,0x78,0xF8,0x00,0x00,0x78,0xF8,0x00,0x00,0xF0,0xF8,0x00,0x01,
    0xE0,0xF8,0x00,0x01,0xE0,0xF8,0x00,0x03,0xC0,0xF8,0x00,0x07,0x80,0xF8,0x00,0x0F,
    0x00,0xF8,0x00,0x0F,0x00,0xF8,0x00,0x1E,0x00,0xF8,0x00,0x3C,0x00,0xF8,0x00,0x3C,
    0x00,0xF8,0x00,0x78,0x00,0xF8,0x00,0xF8,0x00,0xF8,0x00,0xFF,0xFF,0xFF,0xC0,0xFF,
    0xFF,0xFF,0xC0,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0xF8,0x00,0x00,0x00,0xF8,0x00,0x00,
    0x00,0xF8,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0xF8,0x00,0x00,
    0x00,0xF8,0x00,0x00,0x00,0xF8,0x00,0x3F,0xFF,0xE0,0x3F,0xFF,0xE0,0x3F,0xFF,0xE0,
    0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x38,0x00,0x00,0x38,0x00,0x00,0x78,
    0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0x7F,0xFF,
    0x00,0x7F,0xFF,0xC0,0x7F,0xFF,0xE0,0x10,0x07,0xF0,0x00,0x01,0xF0,0x00,0x00,0xF8,
    0x00,0x00,0x78,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,
    0x00,0x7C,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0xF8,0x00,0x01,0xF0,0xE0,0x03,
    0xF0,0xFF,0xFF,0xE0,0xFF,0xFF,0xC0,0x7F,0xFF,0x00,0x0F,0xF8,0x00,0x00,0x00,0x00,
    0x00,0x3F,0xF8,0x00,0xFF,0xF8,0x03,0xFF,0xF8,0x07,0xF0,0x00,0x07,0xC0,0x00,0x0F,
    0x80,0x00,0x1F,0x00,0x00,0x1E,0x00,0x00,0x3E,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,
    0x00,0x7C,0x00,0x00,0x78,0x3F,0x80,0x78,0xFF,0xE0,0x79,0xFF,0xF0,0x7B,0xFF,0xF8,
    0x7F,0x00,0xFC,0x7E,0x00,0x7C,0x7C,0x00,0x3E,0x7C,0x00,0x1E,0x78,0x00,0x1E,0x78,
    0x00,0x1E,0x78,0x00,0x1E,0x78,0x00,0x1E,0x78,0x00,0x1E,0x7C,0x00,0x1E,0x3C,0x00,
    0x3E,0x3E,0x00,0x3C,0x1F,0x00,0x7C,0x1F,0x80,0xF8,0x0F,0xFF,0xF8,0x07,0xFF,0xF0,
    0x01,0xFF,0xC0,0x00,0x7F,0x00,0xFF,0xFF,0xFE,0xFF,0xFF,0xFE,0xFF,0xFF,0xFE,0x00,
    0x00,0x3E,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x7C,0x00,0x00,0x78,0x00,0x00,
    0xF8,0x00,0x00,0xF0,0x00,0x01,0xF0,0x00,0x01,0xE0,0x00,0x03,0xE0,0x00,0x03,0xC0,
    0x00,0x03,0xC0,0x00,0x07,0x80,0x00,0x07,0x80,0x00,0x0F,0x80,0x00,0x0F,0x00,0x00,
    0x1F,0x00,0x00,0x1E,0x00,0x00,0x3E,0x00,0x00,0x3C,0x00,0x00,0x7C,0x00,0x00,0x78,
    0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0xF0,0x00,0x01,0xF0,0x00,0x01,0xE0,0x00,
    0x03,0xE0,0x00,0x03,0xC0,0x00,0x07,0xC0,0x00,0x07,0x80,0x00,0x00,0x00,0x00,0x03,
    0xFF,0x80,0x07,0xFF,0xE0,0x1F,0xFF,0xF0,0x1F,0x81,0xF8,0x3E,0x00,0xF8,0x3C,0x00,
    0x7C,0x3C,0x00,0x3C,0x7C,0x00,0x3C,0x3C,0x00,0x3C,0x3C,0x00,0x3C,0x3C,0x00,0x78,
    0x3E,0x00,0xF8,0x1F,0x01,0xF0,0x0F,0xC7,0xE0,0x07,0xFF,0xC0,0x01,0xFF,0x00,0x01,
    0xFF,0x80,0x07,0xFF,0xC0,0x0F,0x87,0xF0,0x3F,0x01,0xF8,0x3C,0x00,0x7C,0x7C,0x00,
    0x3C,0x78,0x00,0x3E,0x78,0x00,0x1E,0xF8,0x00,0x1E,0xF8,0x00,0x1E,0xF8,0x00,0x1E,
    0x78,0x00,0x3E,0x7C,0x00,0x7C,0x3E,0x00,0xFC,0x3F,0xFF,0xF8,0x1F,0xFF,0xF0,0x07,
    0xFF,0xC0,0x01,0xFF,0x00,0x00,0x00,0x00,0x03,0xFF,0x00,0x07,0xFF,0xC0,0x1F,0xFF,
    0xE0,0x1F,0x83,0xF0,0x3E,0x00,0xF8,0x7C,0x00,0x78,0x78,0x00,0x7C,0x78,0x00,0x3C,
    0x78,0x00,0x3C,0xF8,0x00,0x3E,0xF8,0x00,0x1E,0xF8,0x00,0x1E,0x78,0x00,0x1E,0x78,
    0x00,0x3E,0x78,0x00,0x3E,0x7C,0x00,0x7E,0x3E,0x01,0xFE,0x3F,0xFF,0xDE,0x1F,0xFF,
    0x9E,0x07,0xFF,0x3E,0x01,0xFC,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,
    0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0xF8,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00,
    0x0F,0xE0,0x1F,0xFF,0xC0,0x1F,0xFF,0x00,0x1F,0xFE,0x00,0x1F,0xF0,0x00,
};

leRasterFont ArialSmall =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)ArialSmall_data, // data address pointer
            1038, // data size
        },
        LE_RASTER_FONT,
    },
    36,
    35,
    LE_FONT_BPP_1, // bits per pixel
    ArialSmall_glyphs, // glyph table
};
