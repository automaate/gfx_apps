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

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   32
*****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - size of each index
 * unsigned byte - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned (index size) - a value of length 'index size' that contains
 *                           the offset of the string codepoint data in
 *                           the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 * unsigned short : length of the string in bytes:
 * 'length' number of codepoints - the string data (encoding dependent
 ****************************************************************************/

const uint8_t stringTable_data[412] =
{
    0x20,0x00,0x01,0x00,0x02,0x84,0x00,0x00,0x00,0x8C,0x00,0x00,0x01,0x98,0x00,0x00,
    0x03,0xA0,0x00,0x00,0x05,0xA4,0x00,0x00,0x03,0xAC,0x00,0x00,0x07,0xB0,0x00,0x00,
    0x03,0xB4,0x00,0x00,0x08,0xB8,0x00,0x00,0x00,0xBC,0x00,0x00,0x05,0xC4,0x00,0x00,
    0x00,0xCC,0x00,0x00,0x04,0xD8,0x00,0x00,0x02,0xE0,0x00,0x00,0x00,0xE8,0x00,0x00,
    0x02,0xF0,0x00,0x00,0x02,0xF8,0x00,0x00,0x00,0x00,0x01,0x00,0x06,0x08,0x01,0x00,
    0x06,0x10,0x01,0x00,0x00,0x18,0x01,0x00,0x06,0x24,0x01,0x00,0x00,0x38,0x01,0x00,
    0x06,0x40,0x01,0x00,0x02,0x48,0x01,0x00,0x00,0x54,0x01,0x00,0x00,0x60,0x01,0x00,
    0x00,0x70,0x01,0x00,0x02,0x7C,0x01,0x00,0x06,0x84,0x01,0x00,0x02,0x8C,0x01,0x00,
    0x00,0x98,0x01,0x00,0x05,0x00,0x42,0x61,0x63,0x6F,0x6E,0x00,0x09,0x00,0x42,0x72,
    0x65,0x61,0x6B,0x66,0x61,0x73,0x74,0x00,0x05,0x00,0x42,0x79,0x74,0x65,0x73,0x00,
    0x01,0x00,0x3A,0x00,0x04,0x00,0x32,0x3A,0x30,0x30,0x00,0x00,0x02,0x00,0x31,0x32,
    0x02,0x00,0x30,0x31,0x02,0x00,0x30,0x30,0x02,0x00,0x32,0x33,0x05,0x00,0x30,0x31,
    0x3A,0x30,0x30,0x00,0x04,0x00,0x44,0x6F,0x6E,0x65,0x00,0x00,0x09,0x00,0x46,0x61,
    0x76,0x6F,0x72,0x69,0x74,0x65,0x73,0x00,0x04,0x00,0x47,0x6F,0x6F,0x64,0x00,0x00,
    0x03,0x00,0x48,0x61,0x6D,0x00,0x00,0x00,0x04,0x00,0x48,0x65,0x61,0x74,0x00,0x00,
    0x06,0x00,0x48,0x6F,0x74,0x64,0x6F,0x67,0x06,0x00,0x4B,0x61,0x62,0x6F,0x62,0x73,
    0x04,0x00,0x4D,0x65,0x61,0x74,0x00,0x00,0x05,0x00,0x50,0x41,0x53,0x54,0x41,0x00,
    0x05,0x00,0x50,0x49,0x5A,0x5A,0x41,0x00,0x07,0x00,0x50,0x6F,0x75,0x6C,0x74,0x72,
    0x79,0x00,0x00,0x00,0x10,0x00,0x51,0x75,0x69,0x63,0x6B,0x20,0x53,0x65,0x6C,0x65,
    0x63,0x74,0x69,0x6F,0x6E,0x73,0x00,0x00,0x05,0x00,0x53,0x6D,0x61,0x72,0x74,0x00,
    0x06,0x00,0x53,0x41,0x4C,0x4D,0x4F,0x4E,0x07,0x00,0x53,0x61,0x75,0x73,0x61,0x67,
    0x65,0x00,0x00,0x00,0x07,0x00,0x53,0x65,0x61,0x66,0x6F,0x6F,0x64,0x00,0x00,0x00,
    0x0C,0x00,0x53,0x6D,0x61,0x72,0x74,0x20,0x43,0x6F,0x6F,0x6B,0x65,0x72,0x00,0x00,
    0x0A,0x00,0x53,0x65,0x6C,0x65,0x63,0x74,0x69,0x6F,0x6E,0x73,0x05,0x00,0x53,0x74,
    0x65,0x61,0x6B,0x00,0x05,0x00,0x53,0x54,0x45,0x41,0x4B,0x00,0x07,0x00,0x56,0x65,
    0x67,0x67,0x69,0x65,0x73,0x00,0x00,0x00,0x02,0x00,0x42,0x79,
};

/* font asset pointer list */
leFont* fontList[9] =
{
    (leFont*)&NotoSans_Regular,
    (leFont*)&NotoSans_Regular_20,
    (leFont*)&NotoSans_Regular_wheel,
    (leFont*)&NotoSans_Regular_Time,
    (leFont*)&NotoSans_Bold,
    (leFont*)&NotoSans_Bold_CookTime,
    (leFont*)&NotoSans_Regular_Menu,
    (leFont*)&NotoSans_Bold_Time2,
    (leFont*)&NotoSans_Regular_Time2,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        412, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};
