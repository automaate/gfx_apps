#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   30
*****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of strings in the table
 * for each string:
 *   unsigned short - the length of the string
 *   'length' number of codepoints - the characters of the string (depends on encoding)
 ****************************************************************************/

const uint8_t stringTable_data[309] =
{
    0x1C,0x00,0x0E,0x00,0x53,0x74,0x72,0x69,0x6E,0x67,0x20,0x55,0x70,0x64,0x61,0x74,
    0x65,0x73,0x11,0x00,0x46,0x72,0x61,0x6D,0x65,0x20,0x55,0x70,0x64,0x61,0x74,0x65,
    0x20,0x28,0x48,0x7A,0x29,0x0A,0x00,0x39,0x38,0x37,0x36,0x35,0x34,0x33,0x32,0x31,
    0x30,0x0A,0x00,0x46,0x75,0x6C,0x6C,0x53,0x63,0x72,0x65,0x65,0x6E,0x07,0x00,0x47,
    0x50,0x55,0x20,0x4F,0x66,0x66,0x06,0x00,0x47,0x50,0x55,0x20,0x4F,0x6E,0x0F,0x00,
    0x49,0x6D,0x61,0x67,0x65,0x20,0x52,0x65,0x6E,0x64,0x65,0x72,0x69,0x6E,0x67,0x05,
    0x00,0x54,0x79,0x70,0x65,0x3A,0x0C,0x00,0x4A,0x50,0x47,0x20,0x28,0x32,0x34,0x2D,
    0x62,0x69,0x74,0x29,0x01,0x00,0x2D,0x0B,0x00,0x4D,0x6F,0x74,0x69,0x6F,0x6E,0x20,
    0x46,0x69,0x6C,0x6C,0x04,0x00,0x4E,0x65,0x78,0x74,0x01,0x00,0x3E,0x0A,0x00,0x30,
    0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x13,0x00,0x30,0x31,0x32,0x33,0x34,
    0x35,0x36,0x37,0x38,0x39,0x20,0x61,0x76,0x67,0x63,0x75,0x72,0x72,0x2D,0x0B,0x00,
    0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x78,0x07,0x00,0x50,0x4E,0x47,
    0x38,0x38,0x38,0x38,0x01,0x00,0x2B,0x0D,0x00,0x50,0x72,0x65,0x2D,0x70,0x72,0x6F,
    0x63,0x65,0x73,0x73,0x65,0x64,0x01,0x00,0x3C,0x09,0x00,0x52,0x61,0x77,0x20,0x31,
    0x36,0x62,0x69,0x74,0x0D,0x00,0x52,0x61,0x77,0x20,0x52,0x4C,0x45,0x20,0x31,0x36,
    0x62,0x69,0x74,0x04,0x00,0x4E,0x75,0x6D,0x3A,0x15,0x00,0x44,0x69,0x73,0x70,0x6C,
    0x61,0x79,0x20,0x52,0x65,0x66,0x72,0x65,0x73,0x68,0x20,0x28,0x48,0x7A,0x29,0x3A,
    0x0A,0x00,0x37,0x38,0x39,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x05,0x00,0x53,0x69,
    0x7A,0x65,0x3A,0x0D,0x00,0x53,0x74,0x72,0x69,0x6E,0x67,0x20,0x49,0x6E,0x64,0x65,
    0x78,0x3A,0x01,0x00,0x61,
};

/*****************************************************************************
 * string index table data
 * 
 * this table quickly maps a string ID to an offset into the string
 * data table
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - number of languages in the table
 * unsigned byte - size of each index, either 1 byte or 2
 * array of index sub arrays - each sub array contains an index for each
 *                             defined language
 * array size is: (language count * index size) * index count
 ****************************************************************************/

const uint8_t stringIndexTable_data[64] =
{
    0x1E,0x00,0x01,0x02,0x02,0x00,0x12,0x00,0x25,0x00,0x31,0x00,0x3D,0x00,0x46,0x00,
    0x4E,0x00,0x5F,0x00,0x66,0x00,0x74,0x00,0x77,0x00,0x84,0x00,0x8A,0x00,0x8D,0x00,
    0x99,0x00,0x8D,0x00,0x8D,0x00,0xAE,0x00,0xBB,0x00,0xC4,0x00,0xC7,0x00,0xD6,0x00,
    0xD9,0x00,0xE4,0x00,0xF3,0x00,0xF9,0x00,0x10,0x01,0x1C,0x01,0x23,0x01,0x32,0x01,
};

/* font asset pointer list */
leFont* fontList[10] =
{
    &ArialLarge,
    &ArialMed,
    &ArialSmall,
    &ArialNarrow,
    &ArialNarrowMed,
    &ArialTiny,
    &ArialTitle,
    &ArialLittle,
    &ArialTinyAve,
};
/*****************************************************************************
 * font index table
 * 
 * this table maps a string ID to a font asset
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - size of each index, either 1 byte or 2
 * array of index sub arrays - each sub array contains an index for each
 *                             defined language
 * array size is: (language count * index size) * index count
 ****************************************************************************/

const uint8_t fontIndexTable_data[33] =
{
    0x0A,0x00,0x01,0x06,0x05,0x04,0x05,0x03,0x03,0x06,0x03,0x05,0x04,0x06,0x05,0x04,
    0x00,0x07,0x01,0x02,0x05,0x05,0x04,0x05,0x04,0x05,0x05,0x03,0x05,0x04,0x03,0x03,
    0x08,
};

const leStringTable stringTable =
{
    {
        LE_ASSET_TYPE_STRINGTABLE, // asset type
        LE_ASSET_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        309, // data size
    },
    1,
    30,
    (void*)stringIndexTable_data, // font lookup table
    fontList, // font lookup table
    (void*)fontIndexTable_data, // font index table
    LE_STRING_ENCODING_ASCII // encoding standard
};