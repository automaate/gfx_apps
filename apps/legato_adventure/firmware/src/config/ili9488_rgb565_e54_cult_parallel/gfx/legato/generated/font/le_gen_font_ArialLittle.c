// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         ArialLittle
 * Height:       20
 * Baseline:     14
 * Style:        Plain
 * Glyph Count:  18
 * Range Count:  8
 * Glyph Ranges: 0x20
                 0x2D
                 0x30-0x39
                 0x61
                 0x63
                 0x67
                 0x72
                 0x75-0x76
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
const uint8_t ArialLittle_glyphs[364] =
{
    0x12,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2D,0x00,0x06,0x00,0x03,0x00,0x06,0x00,
    0x00,0x00,0x07,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x0B,0x00,
    0x0E,0x00,0x0B,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,0x03,0x00,0x00,0x00,
    0x31,0x00,0x07,0x00,0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x01,0x00,
    0x1F,0x00,0x00,0x00,0x32,0x00,0x0B,0x00,0x0E,0x00,0x0B,0x00,0x00,0x00,0x0E,0x00,
    0x00,0x00,0x02,0x00,0x2D,0x00,0x00,0x00,0x33,0x00,0x0B,0x00,0x0E,0x00,0x0B,0x00,
    0x00,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,0x49,0x00,0x00,0x00,0x34,0x00,0x0C,0x00,
    0x0E,0x00,0x0B,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,0x65,0x00,0x00,0x00,
    0x35,0x00,0x0A,0x00,0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,
    0x81,0x00,0x00,0x00,0x36,0x00,0x0A,0x00,0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x02,0x00,0x9D,0x00,0x00,0x00,0x37,0x00,0x0B,0x00,0x0E,0x00,0x0B,0x00,
    0x00,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,0xB9,0x00,0x00,0x00,0x38,0x00,0x0B,0x00,
    0x0E,0x00,0x0B,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,0xD5,0x00,0x00,0x00,
    0x39,0x00,0x0A,0x00,0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x02,0x00,
    0xF1,0x00,0x00,0x00,0x61,0x00,0x0A,0x00,0x0B,0x00,0x0B,0x00,0x00,0x00,0x0B,0x00,
    0x00,0x00,0x02,0x00,0x0D,0x01,0x00,0x00,0x63,0x00,0x08,0x00,0x0B,0x00,0x0A,0x00,
    0x01,0x00,0x0B,0x00,0x00,0x00,0x01,0x00,0x23,0x01,0x00,0x00,0x67,0x00,0x0A,0x00,
    0x10,0x00,0x0C,0x00,0x01,0x00,0x0B,0x00,0x00,0x00,0x02,0x00,0x2E,0x01,0x00,0x00,
    0x72,0x00,0x07,0x00,0x0B,0x00,0x08,0x00,0x01,0x00,0x0B,0x00,0x00,0x00,0x01,0x00,
    0x4E,0x01,0x00,0x00,0x75,0x00,0x0A,0x00,0x0B,0x00,0x0C,0x00,0x01,0x00,0x0B,0x00,
    0x00,0x00,0x02,0x00,0x59,0x01,0x00,0x00,0x76,0x00,0x0B,0x00,0x0B,0x00,0x0A,0x00,
    0x00,0x00,0x0B,0x00,0x00,0x00,0x02,0x00,0x6F,0x01,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t ArialLittle_data[389] =
{
    0x00,0x7C,0x00,0x0F,0x00,0x3B,0x80,0x30,0xC0,0x60,0xC0,0x60,0xC0,0x60,0x40,0x60,
    0x40,0x60,0x40,0x60,0x40,0x60,0xC0,0x60,0xC0,0x30,0xC0,0x3B,0x80,0x0F,0x00,0x0C,
    0x1C,0x7C,0x6C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1F,0x00,0x7B,
    0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x80,0x01,0x80,0x03,0x00,0x06,0x00,0x0C,
    0x00,0x18,0x00,0x30,0x00,0x70,0x00,0x7F,0xC0,0x1F,0x00,0x7B,0x80,0x00,0xC0,0x00,
    0xC0,0x00,0xC0,0x03,0x80,0x1F,0x00,0x03,0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,
    0xC0,0x73,0x80,0x3F,0x00,0x01,0x80,0x03,0x80,0x07,0x80,0x05,0x80,0x0D,0x80,0x19,
    0x80,0x31,0x80,0x21,0x80,0x61,0x80,0xFF,0xE0,0x7F,0xE0,0x01,0x80,0x01,0x80,0x01,
    0x80,0x7F,0x00,0x60,0x00,0x60,0x00,0x40,0x00,0x40,0x00,0x7E,0x00,0x47,0x00,0x01,
    0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0xEF,0x00,0x7E,0x00,0x0F,0x00,0x3D,
    0x00,0x60,0x00,0x60,0x00,0x40,0x00,0xDF,0x00,0xF3,0x80,0xC1,0x80,0xC0,0x80,0xC0,
    0x80,0xC0,0x80,0x61,0x80,0x3F,0x00,0x1E,0x00,0x7F,0xC0,0x00,0xC0,0x00,0xC0,0x00,
    0x80,0x01,0x80,0x01,0x80,0x03,0x00,0x03,0x00,0x06,0x00,0x06,0x00,0x0C,0x00,0x0C,
    0x00,0x18,0x00,0x18,0x00,0x1F,0x00,0x3B,0x80,0x20,0xC0,0x60,0xC0,0x30,0xC0,0x39,
    0x80,0x1F,0x00,0x1F,0x80,0x30,0xC0,0x60,0xC0,0x60,0x40,0x60,0xC0,0x3B,0xC0,0x1F,
    0x00,0x3E,0x00,0x77,0x00,0xC1,0x80,0xC1,0x80,0xC0,0x80,0xC1,0x80,0x63,0x80,0x7F,
    0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x03,0x00,0x5E,0x00,0x7C,0x00,0x1F,0x00,0x3B,
    0x80,0x00,0x80,0x00,0xC0,0x00,0xC0,0x1F,0xC0,0x70,0xC0,0x60,0xC0,0x61,0xC0,0x77,
    0xC0,0x3E,0xC0,0x1F,0x7F,0x60,0xC0,0xC0,0xC0,0xC0,0xC0,0x60,0x7F,0x1E,0x3C,0xC0,
    0x77,0xC0,0x61,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x61,0xC0,
    0x77,0xC0,0x3E,0xC0,0x00,0xC0,0x00,0x80,0x01,0x80,0x7F,0x80,0x7E,0x00,0x4E,0x58,
    0x60,0x60,0x60,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0xC0,0x40,0xC0,0x40,0xC0,0x40,
    0xC0,0x40,0xC0,0x40,0xC0,0x40,0xC0,0x40,0xC0,0x61,0xC0,0x77,0xC0,0x3E,0xC0,0xC0,
    0xC0,0x40,0xC0,0x61,0x80,0x61,0x80,0x21,0x00,0x33,0x00,0x33,0x00,0x12,0x00,0x1E,
    0x00,0x0E,0x00,0x0C,0x00,
};

leRasterFont ArialLittle =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)ArialLittle_data, // data address pointer
            389, // data size
        },
        LE_RASTER_FONT,
    },
    20,
    14,
    LE_FONT_BPP_1, // bits per pixel
    ArialLittle_glyphs, // glyph table
};
