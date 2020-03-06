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
 * Name:         ArialUnicodeMS
 * Height:       14
 * Baseline:     13
 * Style:        Plain
 * Glyph Count:  11
 * Range Count:  1
 * Glyph Ranges: 0x30-0x3A
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
const uint8_t ArialUnicodeMS_glyphs[224] =
{
    0x0B,0x00,0x00,0x00,0x30,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x06,0x00,0x0D,0x00,0x0A,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x01,0x00,0x1A,0x00,0x00,0x00,0x32,0x00,0x0A,0x00,
    0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,0x27,0x00,0x00,0x00,
    0x33,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,
    0x41,0x00,0x00,0x00,0x34,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x02,0x00,0x5B,0x00,0x00,0x00,0x35,0x00,0x09,0x00,0x0D,0x00,0x0A,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,0x75,0x00,0x00,0x00,0x36,0x00,0x0A,0x00,
    0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,0x8F,0x00,0x00,0x00,
    0x37,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,
    0xA9,0x00,0x00,0x00,0x38,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x02,0x00,0xC3,0x00,0x00,0x00,0x39,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,
    0x00,0x00,0x0D,0x00,0x00,0x00,0x02,0x00,0xDD,0x00,0x00,0x00,0x3A,0x00,0x03,0x00,
    0x0A,0x00,0x05,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x01,0x00,0xF7,0x00,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t ArialUnicodeMS_data[257] =
{
    0x1E,0x00,0x33,0x00,0x21,0x80,0x61,0x80,0x60,0x80,0x60,0x80,0x40,0x80,0x60,0x80,
    0x60,0x80,0x61,0x80,0x21,0x80,0x33,0x00,0x1E,0x00,0x18,0x38,0x68,0x48,0x08,0x08,
    0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1E,0x00,0x73,0x00,0x01,0x80,0x01,0x80,0x01,
    0x80,0x01,0x00,0x03,0x00,0x06,0x00,0x0C,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0x7F,
    0x80,0x3E,0x00,0x73,0x00,0x01,0x80,0x01,0x80,0x03,0x00,0x1E,0x00,0x03,0x00,0x01,
    0x80,0x00,0x80,0x01,0x80,0x01,0x80,0x63,0x00,0x7E,0x00,0x03,0x00,0x07,0x00,0x07,
    0x00,0x0D,0x00,0x19,0x00,0x11,0x00,0x31,0x00,0x61,0x00,0x43,0x00,0xFF,0xC0,0x03,
    0x00,0x01,0x00,0x01,0x00,0x7E,0x00,0x60,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0xFC,
    0x00,0x07,0x00,0x03,0x00,0x01,0x00,0x01,0x00,0x03,0x00,0xC6,0x00,0x7C,0x00,0x0F,
    0x00,0x1C,0x00,0x30,0x00,0x20,0x00,0x60,0x00,0x6F,0x00,0x71,0x80,0x60,0x80,0x60,
    0x80,0x60,0x80,0x21,0x80,0x33,0x80,0x1E,0x00,0x7F,0x80,0x01,0x80,0x01,0x80,0x01,
    0x00,0x03,0x00,0x02,0x00,0x06,0x00,0x06,0x00,0x0C,0x00,0x0C,0x00,0x08,0x00,0x18,
    0x00,0x10,0x00,0x1E,0x00,0x33,0x80,0x61,0x80,0x61,0x80,0x21,0x80,0x3F,0x00,0x1E,
    0x00,0x33,0x00,0x61,0x80,0x40,0x80,0x60,0x80,0x73,0x80,0x1E,0x00,0x1E,0x00,0x33,
    0x00,0x61,0x80,0x60,0x80,0x60,0x80,0x61,0x80,0x63,0x80,0x3E,0x80,0x01,0x80,0x01,
    0x80,0x03,0x00,0x07,0x00,0x3C,0x00,0x40,0xE0,0x40,0x00,0x00,0x00,0x00,0x00,0xC0,
    0x40,
};

leFont ArialUnicodeMS =
{
    {
        LE_ASSET_TYPE_FONT, // asset type
        LE_ASSET_LOCATION_ID_INTERNAL, // data location id
        (void*)ArialUnicodeMS_data, // data address pointer
        257, // data size
    },
    14,
    13,
    LE_FONT_BPP_1, // bits per pixel
    ArialUnicodeMS_glyphs, // glyph table
    ArialUnicodeMS_data, // font data
};
