/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font C:\Users\luisv\Desktop\IoT\AustinPowers\gui\assets\Inter-Regular.ttf -o C:\Users\luisv\Desktop\IoT\AustinPowers\gui\assets\ui_font_Inter14.c --format lvgl -r 0x20-0x7f --symbols äöü --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_INTER14
#define UI_FONT_INTER14 1
#endif

#if UI_FONT_INTER14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0xa8, 0x3c,

    /* U+0022 "\"" */
    0x99, 0x90,

    /* U+0023 "#" */
    0x12, 0x9, 0x4, 0x8f, 0xf2, 0x21, 0x10, 0x89,
    0xfe, 0x24, 0x12, 0x11, 0x0,

    /* U+0024 "$" */
    0x10, 0xf3, 0x5c, 0x99, 0x1e, 0xf, 0xb, 0x13,
    0x27, 0x5b, 0xc1, 0x0,

    /* U+0025 "%" */
    0x61, 0x49, 0xa4, 0x92, 0x86, 0xc0, 0x40, 0x4c,
    0x29, 0x24, 0xa2, 0x50, 0xc0,

    /* U+0026 "&" */
    0x38, 0x44, 0x44, 0x4c, 0x38, 0x70, 0xd2, 0x8a,
    0x8e, 0xce, 0x7a,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x49, 0x49, 0x24, 0x91, 0x24,

    /* U+0029 ")" */
    0x49, 0x12, 0x49, 0x25, 0x24,

    /* U+002A "*" */
    0x25, 0x5c, 0xea, 0x90,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0xfa,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0x84, 0x21, 0x10, 0x84, 0x62, 0x10, 0x8c,
    0x0,

    /* U+0030 "0" */
    0x38, 0x8a, 0x1c, 0x18, 0x30, 0x60, 0xc1, 0x86,
    0x88, 0xe0,

    /* U+0031 "1" */
    0x37, 0x91, 0x11, 0x11, 0x11, 0x10,

    /* U+0032 "2" */
    0x7b, 0x38, 0x41, 0x4, 0x21, 0xc, 0x61, 0xf,
    0xc0,

    /* U+0033 "3" */
    0x7b, 0x38, 0x41, 0xc, 0xe0, 0xc1, 0x87, 0x37,
    0x80,

    /* U+0034 "4" */
    0xc, 0x18, 0x50, 0xa2, 0x4c, 0x91, 0x62, 0xfe,
    0x8, 0x10,

    /* U+0035 "5" */
    0xfe, 0x8, 0x20, 0xf8, 0x20, 0x41, 0x86, 0x27,
    0x0,

    /* U+0036 "6" */
    0x38, 0x89, 0xc, 0xb, 0x98, 0xa0, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x60, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x0,

    /* U+0038 "8" */
    0x79, 0x9a, 0x14, 0x2c, 0xcf, 0x31, 0x41, 0x83,
    0x8d, 0xf0,

    /* U+0039 "9" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0xce, 0x81, 0x84,
    0x88, 0xe0,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0xf0, 0xe, 0xa0,

    /* U+003C "<" */
    0x2, 0x18, 0xc6, 0xe, 0x7, 0x3, 0x81,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x81, 0xc0, 0xe0, 0x70, 0xc6, 0x30, 0x0,

    /* U+003F "?" */
    0x7b, 0x18, 0x41, 0x8, 0x42, 0x8, 0x0, 0xc3,
    0x0,

    /* U+0040 "@" */
    0x1f, 0x83, 0x4, 0x40, 0x2c, 0x79, 0x89, 0x99,
    0x9, 0x90, 0x99, 0x9, 0x99, 0x94, 0xee, 0x40,
    0x3, 0x0, 0xf, 0x80,

    /* U+0041 "A" */
    0x8, 0xe, 0x5, 0x2, 0x83, 0x61, 0x10, 0x88,
    0xfe, 0x41, 0x20, 0xb0, 0x60,

    /* U+0042 "B" */
    0xfd, 0xe, 0xc, 0x18, 0x7f, 0xa1, 0xc1, 0x83,
    0xf, 0xf0,

    /* U+0043 "C" */
    0x3c, 0x63, 0x41, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x41, 0x63, 0x3c,

    /* U+0044 "D" */
    0xfc, 0x86, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x82, 0x86, 0xf8,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0x83, 0xf8, 0x20, 0x82, 0xf,
    0xc0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x83, 0xe8, 0x20, 0x82, 0x8,
    0x0,

    /* U+0047 "G" */
    0x1e, 0x31, 0x90, 0x70, 0x18, 0x4, 0x2, 0x1f,
    0x1, 0x40, 0xb0, 0x87, 0x80,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81,
    0x81, 0x81, 0x81,

    /* U+0049 "I" */
    0xff, 0xe0,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x10, 0x41, 0x45, 0x17,
    0x80,

    /* U+004B "K" */
    0x87, 0x1a, 0x24, 0x8a, 0x1c, 0x34, 0x4c, 0x8d,
    0xa, 0x18,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82, 0xf,
    0xc0,

    /* U+004D "M" */
    0x80, 0xf0, 0x3c, 0xf, 0x87, 0xa1, 0x68, 0xd9,
    0x26, 0x49, 0x9e, 0x63, 0x18, 0xc4,

    /* U+004E "N" */
    0x81, 0xc1, 0xe1, 0xa1, 0x91, 0x99, 0x8d, 0x85,
    0x87, 0x83, 0x81,

    /* U+004F "O" */
    0x3e, 0x31, 0x90, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x41, 0x31, 0x8f, 0x0,

    /* U+0050 "P" */
    0xfd, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x2, 0x0,

    /* U+0051 "Q" */
    0x3e, 0x31, 0x90, 0x50, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x45, 0x31, 0x8f, 0xc0, 0x20,

    /* U+0052 "R" */
    0xfd, 0xa, 0xc, 0x18, 0x30, 0xff, 0x46, 0x85,
    0xe, 0x8,

    /* U+0053 "S" */
    0x79, 0x8e, 0xc, 0xe, 0x7, 0x81, 0x81, 0x83,
    0x8d, 0xe0,

    /* U+0054 "T" */
    0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10,

    /* U+0055 "U" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0056 "V" */
    0x40, 0xa0, 0xd0, 0x44, 0x22, 0x31, 0x10, 0x48,
    0x2c, 0x14, 0x6, 0x3, 0x0,

    /* U+0057 "W" */
    0xc2, 0xa, 0x18, 0xd1, 0xc4, 0x8a, 0x26, 0x51,
    0x12, 0x58, 0xb2, 0x85, 0x14, 0x38, 0xa0, 0xc3,
    0x6, 0x10,

    /* U+0058 "X" */
    0x41, 0x31, 0x88, 0x86, 0xc1, 0x40, 0x40, 0x70,
    0x6c, 0x22, 0x31, 0x90, 0x40,

    /* U+0059 "Y" */
    0x41, 0x31, 0x88, 0x86, 0xc1, 0x40, 0xe0, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x0,

    /* U+005A "Z" */
    0xfe, 0xc, 0x10, 0x41, 0x82, 0xc, 0x10, 0x41,
    0x83, 0xf8,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x4e,

    /* U+005C "\\" */
    0x82, 0x10, 0x84, 0x10, 0x84, 0x20, 0x84, 0x21,
    0x80,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x9e,

    /* U+005E "^" */
    0x23, 0x15, 0xa9, 0xc4,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0xc9, 0x80,

    /* U+0061 "a" */
    0x7b, 0x10, 0x4f, 0xc6, 0x18, 0xdd,

    /* U+0062 "b" */
    0x81, 0x2, 0x5, 0xcc, 0x50, 0x60, 0xc1, 0x83,
    0x8a, 0xe0,

    /* U+0063 "c" */
    0x39, 0x18, 0x20, 0x82, 0x4, 0x4e,

    /* U+0064 "d" */
    0x2, 0x4, 0x9, 0xd4, 0x70, 0x60, 0xc1, 0x82,
    0x8c, 0xe8,

    /* U+0065 "e" */
    0x3c, 0x8e, 0xf, 0xf8, 0x10, 0x11, 0x9e,

    /* U+0066 "f" */
    0x34, 0x4f, 0x44, 0x44, 0x44, 0x40,

    /* U+0067 "g" */
    0x3a, 0x8e, 0xc, 0x18, 0x30, 0x51, 0x9d, 0x3,
    0x8d, 0xf0,

    /* U+0068 "h" */
    0x82, 0x8, 0x2e, 0xce, 0x18, 0x61, 0x86, 0x18,
    0x40,

    /* U+0069 "i" */
    0x9f, 0xe0,

    /* U+006A "j" */
    0x41, 0x55, 0x55, 0x60,

    /* U+006B "k" */
    0x82, 0x8, 0x23, 0x9a, 0x4a, 0x38, 0x92, 0x28,
    0xc0,

    /* U+006C "l" */
    0xff, 0xe0,

    /* U+006D "m" */
    0xb9, 0xd8, 0xc6, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21,

    /* U+006E "n" */
    0xbb, 0x38, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0070 "p" */
    0xb9, 0x8a, 0xc, 0x18, 0x30, 0x71, 0x5c, 0x81,
    0x2, 0x0,

    /* U+0071 "q" */
    0x3a, 0x8e, 0xc, 0x18, 0x30, 0x51, 0x9d, 0x2,
    0x4, 0x8,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88,

    /* U+0073 "s" */
    0x7a, 0x18, 0x3c, 0x1c, 0x18, 0x5e,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x44, 0x43,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0xdd,

    /* U+0076 "v" */
    0x42, 0x85, 0x91, 0x22, 0x47, 0x6, 0xc,

    /* U+0077 "w" */
    0x44, 0x28, 0xc9, 0x29, 0x35, 0x22, 0xbc, 0x53,
    0xc, 0x60, 0x8c,

    /* U+0078 "x" */
    0x8f, 0x25, 0xc, 0x31, 0x4c, 0xa3,

    /* U+0079 "y" */
    0x42, 0x85, 0x91, 0x22, 0x47, 0x6, 0xc, 0x10,
    0x21, 0x80,

    /* U+007A "z" */
    0xfc, 0x31, 0x84, 0x21, 0x8c, 0x3f,

    /* U+007B "{" */
    0x12, 0x22, 0x22, 0xc2, 0x22, 0x22, 0x10,

    /* U+007C "|" */
    0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xc2, 0x22, 0x22, 0x32, 0x22, 0x22, 0xc0,

    /* U+007E "~" */
    0x63, 0x26, 0x30,

    /* U+00E4 "ä" */
    0x48, 0x0, 0x1e, 0xc4, 0x13, 0xf1, 0x86, 0x37,
    0x40,

    /* U+00F6 "ö" */
    0x28, 0x0, 0x1, 0xc4, 0x50, 0x60, 0xc1, 0x82,
    0x88, 0xe0,

    /* U+00FC "ü" */
    0x48, 0x0, 0x21, 0x86, 0x18, 0x61, 0x87, 0x37,
    0x40
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 63, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 62, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 90, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 6, .adv_w = 141, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 143, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 31, .adv_w = 182, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 143, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 50, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 56, .adv_w = 81, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 61, .adv_w = 81, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 66, .adv_w = 112, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 70, .adv_w = 148, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 77, .adv_w = 63, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 78, .adv_w = 103, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 79, .adv_w = 62, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 80, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 89, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 104, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 136, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 143, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 144, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 136, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 138, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 182, .adv_w = 62, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 63, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 187, .adv_w = 148, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 148, .box_w = 6, .box_h = 4, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 197, .adv_w = 148, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 114, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 210, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 233, .adv_w = 151, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 146, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 163, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 161, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 131, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 166, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 166, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 59, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 146, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 126, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 199, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 169, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 171, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 171, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 412, .adv_w = 143, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 143, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 144, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 166, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 151, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 213, .box_w = 13, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 144, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 149, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 140, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 81, .box_w = 3, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 526, .adv_w = 80, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 535, .adv_w = 81, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 540, .adv_w = 105, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 544, .adv_w = 101, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 545, .adv_w = 111, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 547, .adv_w = 126, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 125, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 579, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 81, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 602, .adv_w = 132, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 53, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 53, .box_w = 2, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 617, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 53, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 628, .adv_w = 195, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 131, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 662, .adv_w = 136, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 672, .adv_w = 83, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 117, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 682, .adv_w = 81, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 687, .adv_w = 130, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 125, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 700, .adv_w = 182, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 711, .adv_w = 121, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 717, .adv_w = 125, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 727, .adv_w = 121, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 733, .adv_w = 81, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 740, .adv_w = 73, .box_w = 1, .box_h = 18, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 743, .adv_w = 81, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 750, .adv_w = 148, .box_w = 7, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 753, .adv_w = 126, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 772, .adv_w = 130, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x12, 0x18
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 228, .range_length = 25, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 7,
    3, 13,
    3, 15,
    3, 21,
    3, 34,
    3, 43,
    7, 3,
    7, 8,
    7, 53,
    7, 55,
    7, 56,
    7, 58,
    7, 61,
    7, 87,
    7, 88,
    7, 90,
    8, 7,
    8, 13,
    8, 15,
    8, 21,
    8, 34,
    8, 43,
    9, 68,
    9, 69,
    9, 70,
    9, 72,
    9, 75,
    9, 80,
    9, 82,
    9, 97,
    11, 7,
    11, 13,
    11, 15,
    11, 21,
    11, 34,
    11, 43,
    11, 64,
    12, 19,
    12, 20,
    12, 24,
    12, 53,
    12, 55,
    12, 56,
    12, 57,
    12, 58,
    12, 61,
    12, 89,
    13, 3,
    13, 8,
    13, 17,
    13, 18,
    13, 20,
    13, 22,
    13, 23,
    13, 24,
    13, 25,
    13, 26,
    13, 32,
    13, 53,
    13, 58,
    13, 65,
    14, 19,
    14, 20,
    14, 24,
    14, 53,
    14, 55,
    14, 56,
    14, 57,
    14, 58,
    14, 61,
    14, 89,
    15, 3,
    15, 8,
    15, 17,
    15, 18,
    15, 20,
    15, 22,
    15, 23,
    15, 24,
    15, 25,
    15, 26,
    15, 32,
    15, 53,
    15, 58,
    15, 65,
    16, 13,
    16, 15,
    16, 43,
    17, 13,
    17, 15,
    17, 24,
    17, 58,
    17, 64,
    18, 13,
    18, 15,
    19, 21,
    20, 13,
    20, 15,
    21, 13,
    21, 15,
    21, 18,
    22, 13,
    22, 15,
    23, 13,
    23, 15,
    23, 64,
    24, 4,
    24, 7,
    24, 13,
    24, 15,
    24, 17,
    24, 20,
    24, 21,
    24, 22,
    24, 23,
    24, 24,
    24, 25,
    24, 26,
    24, 27,
    24, 28,
    24, 29,
    24, 34,
    24, 43,
    24, 64,
    24, 66,
    24, 68,
    24, 69,
    24, 70,
    24, 72,
    24, 80,
    24, 82,
    24, 84,
    24, 96,
    24, 97,
    25, 13,
    25, 15,
    26, 13,
    26, 15,
    26, 24,
    26, 58,
    26, 64,
    27, 53,
    27, 55,
    27, 61,
    28, 53,
    28, 55,
    28, 61,
    30, 34,
    30, 55,
    30, 56,
    30, 57,
    30, 58,
    30, 61,
    30, 87,
    30, 89,
    30, 90,
    31, 24,
    31, 53,
    31, 55,
    31, 56,
    31, 57,
    31, 58,
    31, 59,
    31, 61,
    32, 34,
    34, 3,
    34, 8,
    34, 11,
    34, 18,
    34, 30,
    34, 32,
    34, 36,
    34, 40,
    34, 48,
    34, 50,
    34, 53,
    34, 55,
    34, 56,
    34, 58,
    34, 61,
    34, 63,
    34, 74,
    34, 85,
    34, 87,
    34, 88,
    34, 90,
    36, 57,
    36, 64,
    37, 13,
    37, 15,
    37, 16,
    37, 34,
    37, 53,
    37, 55,
    37, 57,
    37, 58,
    37, 61,
    37, 64,
    39, 13,
    39, 15,
    39, 34,
    39, 43,
    39, 64,
    39, 68,
    39, 69,
    39, 70,
    39, 72,
    39, 78,
    39, 79,
    39, 80,
    39, 81,
    39, 82,
    39, 83,
    39, 86,
    39, 87,
    39, 90,
    39, 91,
    39, 97,
    39, 98,
    40, 34,
    40, 53,
    40, 55,
    40, 57,
    40, 58,
    40, 61,
    40, 74,
    40, 75,
    41, 64,
    42, 64,
    43, 13,
    43, 15,
    43, 16,
    43, 64,
    44, 12,
    44, 14,
    44, 29,
    44, 30,
    44, 36,
    44, 40,
    44, 48,
    44, 50,
    44, 68,
    44, 69,
    44, 70,
    44, 72,
    44, 74,
    44, 80,
    44, 82,
    44, 86,
    44, 87,
    44, 88,
    44, 90,
    44, 95,
    44, 97,
    44, 98,
    45, 3,
    45, 8,
    45, 11,
    45, 12,
    45, 14,
    45, 18,
    45, 34,
    45, 36,
    45, 40,
    45, 48,
    45, 50,
    45, 53,
    45, 55,
    45, 58,
    45, 61,
    45, 63,
    45, 85,
    45, 87,
    45, 90,
    45, 95,
    46, 64,
    47, 64,
    48, 13,
    48, 15,
    48, 16,
    48, 34,
    48, 53,
    48, 55,
    48, 57,
    48, 58,
    48, 61,
    48, 64,
    49, 7,
    49, 12,
    49, 13,
    49, 14,
    49, 15,
    49, 34,
    49, 43,
    49, 68,
    49, 69,
    49, 70,
    49, 72,
    49, 80,
    49, 82,
    49, 95,
    49, 97,
    50, 13,
    50, 15,
    50, 16,
    50, 34,
    50, 53,
    50, 55,
    50, 57,
    50, 58,
    50, 61,
    50, 64,
    51, 55,
    51, 58,
    51, 61,
    51, 68,
    51, 69,
    51, 70,
    51, 72,
    51, 80,
    51, 82,
    51, 97,
    53, 7,
    53, 12,
    53, 13,
    53, 14,
    53, 15,
    53, 16,
    53, 21,
    53, 27,
    53, 28,
    53, 29,
    53, 34,
    53, 36,
    53, 40,
    53, 43,
    53, 48,
    53, 50,
    53, 64,
    53, 66,
    53, 68,
    53, 69,
    53, 70,
    53, 72,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 84,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    53, 91,
    53, 95,
    53, 96,
    53, 97,
    53, 98,
    54, 13,
    54, 15,
    54, 16,
    54, 64,
    55, 7,
    55, 12,
    55, 13,
    55, 14,
    55, 15,
    55, 16,
    55, 21,
    55, 27,
    55, 28,
    55, 29,
    55, 30,
    55, 33,
    55, 34,
    55, 36,
    55, 40,
    55, 43,
    55, 48,
    55, 50,
    55, 64,
    55, 66,
    55, 68,
    55, 69,
    55, 70,
    55, 72,
    55, 80,
    55, 82,
    55, 84,
    55, 95,
    55, 96,
    55, 97,
    56, 7,
    56, 12,
    56, 13,
    56, 14,
    56, 15,
    56, 21,
    56, 27,
    56, 28,
    56, 29,
    56, 30,
    56, 34,
    56, 36,
    56, 40,
    56, 43,
    56, 48,
    56, 50,
    56, 66,
    56, 68,
    56, 69,
    56, 70,
    56, 72,
    56, 78,
    56, 79,
    56, 80,
    56, 81,
    56, 82,
    56, 83,
    56, 84,
    56, 95,
    56, 96,
    56, 97,
    57, 12,
    57, 14,
    57, 29,
    57, 30,
    57, 36,
    57, 40,
    57, 48,
    57, 50,
    57, 68,
    57, 69,
    57, 70,
    57, 72,
    57, 80,
    57, 82,
    57, 95,
    57, 97,
    58, 7,
    58, 12,
    58, 13,
    58, 14,
    58, 15,
    58, 21,
    58, 27,
    58, 28,
    58, 29,
    58, 30,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 48,
    58, 50,
    58, 53,
    58, 66,
    58, 68,
    58, 69,
    58, 70,
    58, 72,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 86,
    58, 95,
    58, 96,
    58, 97,
    58, 98,
    59, 12,
    59, 14,
    59, 29,
    59, 36,
    59, 40,
    59, 48,
    59, 50,
    59, 95,
    60, 68,
    60, 69,
    60, 70,
    60, 72,
    60, 75,
    60, 80,
    60, 82,
    60, 97,
    61, 3,
    61, 8,
    61, 11,
    61, 13,
    61, 15,
    61, 18,
    61, 30,
    61, 32,
    61, 36,
    61, 40,
    61, 48,
    61, 50,
    61, 53,
    61, 55,
    61, 56,
    61, 58,
    61, 61,
    61, 63,
    61, 74,
    61, 85,
    61, 87,
    61, 88,
    61, 90,
    63, 7,
    63, 13,
    63, 15,
    63, 21,
    63, 34,
    63, 43,
    63, 64,
    64, 11,
    64, 17,
    64, 18,
    64, 20,
    64, 21,
    64, 22,
    64, 23,
    64, 25,
    64, 26,
    64, 36,
    64, 40,
    64, 48,
    64, 50,
    64, 53,
    64, 54,
    64, 55,
    64, 61,
    64, 63,
    64, 74,
    64, 75,
    64, 78,
    64, 79,
    64, 81,
    64, 83,
    64, 87,
    64, 90,
    66, 18,
    66, 53,
    66, 55,
    66, 56,
    66, 58,
    66, 61,
    66, 87,
    66, 90,
    67, 10,
    67, 34,
    67, 53,
    67, 55,
    67, 56,
    67, 57,
    67, 58,
    67, 61,
    67, 62,
    67, 87,
    67, 88,
    67, 89,
    67, 90,
    67, 94,
    68, 53,
    68, 58,
    68, 89,
    69, 64,
    70, 53,
    70, 55,
    70, 56,
    70, 58,
    70, 61,
    70, 87,
    70, 89,
    70, 90,
    71, 12,
    71, 13,
    71, 14,
    71, 15,
    71, 16,
    71, 21,
    71, 34,
    71, 43,
    71, 58,
    71, 64,
    71, 66,
    71, 68,
    71, 69,
    71, 70,
    71, 72,
    71, 80,
    71, 82,
    71, 84,
    71, 95,
    71, 96,
    71, 97,
    72, 53,
    72, 64,
    73, 18,
    73, 53,
    73, 55,
    73, 56,
    73, 58,
    73, 61,
    73, 87,
    73, 90,
    74, 10,
    74, 55,
    74, 56,
    74, 61,
    74, 62,
    74, 64,
    74, 94,
    75, 10,
    75, 55,
    75, 56,
    75, 61,
    75, 62,
    75, 64,
    75, 94,
    76, 12,
    76, 14,
    76, 21,
    76, 29,
    76, 53,
    76, 68,
    76, 69,
    76, 70,
    76, 72,
    76, 80,
    76, 82,
    76, 95,
    76, 97,
    77, 64,
    78, 18,
    78, 53,
    78, 55,
    78, 56,
    78, 58,
    78, 61,
    78, 87,
    78, 90,
    79, 18,
    79, 53,
    79, 55,
    79, 56,
    79, 58,
    79, 61,
    79, 87,
    79, 90,
    80, 10,
    80, 34,
    80, 53,
    80, 55,
    80, 56,
    80, 57,
    80, 58,
    80, 61,
    80, 62,
    80, 87,
    80, 88,
    80, 89,
    80, 90,
    80, 94,
    81, 10,
    81, 34,
    81, 53,
    81, 55,
    81, 56,
    81, 57,
    81, 58,
    81, 61,
    81, 62,
    81, 87,
    81, 88,
    81, 89,
    81, 90,
    81, 94,
    82, 53,
    82, 64,
    83, 12,
    83, 13,
    83, 14,
    83, 15,
    83, 16,
    83, 29,
    83, 34,
    83, 43,
    83, 53,
    83, 59,
    83, 68,
    83, 69,
    83, 70,
    83, 71,
    83, 72,
    83, 80,
    83, 82,
    83, 85,
    83, 87,
    83, 88,
    83, 89,
    83, 90,
    83, 95,
    83, 97,
    84, 53,
    84, 55,
    84, 56,
    84, 58,
    84, 61,
    85, 12,
    85, 14,
    85, 21,
    85, 29,
    85, 35,
    85, 37,
    85, 38,
    85, 39,
    85, 41,
    85, 42,
    85, 44,
    85, 45,
    85, 46,
    85, 47,
    85, 49,
    85, 51,
    85, 53,
    85, 55,
    85, 56,
    85, 58,
    85, 61,
    85, 67,
    85, 68,
    85, 69,
    85, 70,
    85, 72,
    85, 73,
    85, 76,
    85, 77,
    85, 80,
    85, 82,
    85, 84,
    85, 93,
    85, 95,
    85, 97,
    86, 53,
    86, 58,
    87, 13,
    87, 15,
    87, 16,
    87, 29,
    87, 30,
    87, 34,
    87, 43,
    87, 53,
    87, 58,
    87, 64,
    87, 66,
    87, 68,
    87, 69,
    87, 70,
    87, 72,
    87, 80,
    87, 82,
    87, 96,
    87, 97,
    88, 7,
    88, 13,
    88, 15,
    88, 34,
    88, 43,
    88, 53,
    88, 59,
    88, 68,
    88, 69,
    88, 70,
    88, 72,
    88, 80,
    88, 82,
    88, 97,
    89, 12,
    89, 14,
    89, 30,
    89, 53,
    89, 68,
    89, 69,
    89, 70,
    89, 72,
    89, 80,
    89, 82,
    89, 95,
    89, 97,
    90, 13,
    90, 15,
    90, 16,
    90, 29,
    90, 30,
    90, 34,
    90, 43,
    90, 53,
    90, 58,
    90, 64,
    90, 66,
    90, 68,
    90, 69,
    90, 70,
    90, 72,
    90, 80,
    90, 82,
    90, 96,
    90, 97,
    91, 53,
    91, 68,
    91, 69,
    91, 70,
    91, 72,
    91, 80,
    91, 82,
    91, 97,
    92, 68,
    92, 69,
    92, 70,
    92, 72,
    92, 75,
    92, 80,
    92, 82,
    92, 97,
    93, 64,
    95, 19,
    95, 20,
    95, 24,
    95, 53,
    95, 55,
    95, 56,
    95, 57,
    95, 58,
    95, 61,
    95, 89,
    96, 18,
    96, 53,
    96, 55,
    96, 56,
    96, 58,
    96, 61,
    96, 87,
    96, 90,
    97, 10,
    97, 34,
    97, 53,
    97, 55,
    97, 56,
    97, 57,
    97, 58,
    97, 61,
    97, 62,
    97, 87,
    97, 88,
    97, 89,
    97, 90,
    97, 94,
    98, 53,
    98, 58
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -8, -18, -18, -14, -18, -37, -8, -8,
    -13, -14, -9, -17, -14, -8, -8, -8,
    -8, -18, -18, -14, -18, -37, -3, -3,
    -3, -3, 6, -3, -3, -3, -8, -31,
    -31, -10, -18, -22, -15, -8, -3, -5,
    -17, -11, -11, -14, -18, -11, -5, -18,
    -18, -6, -19, -6, -3, -6, -3, -5,
    -2, -20, -8, -8, -31, -8, -3, -5,
    -17, -11, -11, -14, -18, -11, -5, -18,
    -18, -6, -19, -6, -3, -6, -3, -5,
    -2, -20, -8, -8, -31, -9, -9, -14,
    -6, -6, -4, -8, -10, -10, -10, -3,
    -5, -5, -8, -8, -2, -6, -6, -8,
    -8, -10, -13, -10, -28, -28, -3, -4,
    -13, -2, -3, 4, -3, -2, -8, -8,
    -20, -24, -22, -36, -10, -11, -11, -11,
    -11, -11, -11, -9, -10, -11, -5, -5,
    -6, -6, -4, -8, -10, -8, -14, -14,
    -8, -14, -14, -11, -15, -14, -11, -22,
    -15, -9, -8, -9, -17, -18, -17, -17,
    -13, -20, -14, -17, -14, -18, -18, -18,
    -8, -11, -14, -8, -8, -8, -8, -19,
    -15, -13, -17, -15, -18, 1, -8, -15,
    -15, -15, -1, -9, -10, -10, -9, -8,
    -7, -8, -3, -8, -8, -9, -9, -8,
    -20, -15, -8, -9, -9, -9, -9, -1,
    -1, -9, -1, -9, -1, -8, -8, -8,
    -8, -9, -8, -5, -7, -5, -1, -5,
    -5, 8, 8, 8, 8, -8, -8, -13,
    -11, -24, -24, -15, -8, -8, -8, -8,
    -8, -9, -9, -9, -9, 8, -9, -9,
    -8, -9, -14, -9, -24, -9, -8, -20,
    -20, -9, -19, -11, -10, 10, -6, -6,
    -6, -6, -22, -15, -8, -15, -29, -5,
    -15, -15, -9, 8, 8, -10, -10, -9,
    -8, -7, -8, -3, -8, -8, -9, -8,
    -10, -9, -10, -8, -17, -22, -1, -1,
    -1, -1, -1, -1, -10, -1, -10, -10,
    -9, -8, -7, -8, -3, -8, -8, -9,
    -4, -5, -4, -1, -1, -1, -1, -1,
    -1, -1, -8, -17, -8, -17, -8, -18,
    -15, -8, -8, -18, -19, -7, -7, -20,
    -7, -7, -13, -17, -18, -18, -18, -18,
    -13, -13, -18, -13, -18, -13, -17, -17,
    -14, -14, -14, -14, -10, -17, -9, -11,
    -11, -8, -8, -13, -11, -11, -11, -22,
    -11, -22, -17, -8, -14, -14, -17, -14,
    -8, -14, -8, -8, -22, -8, -8, -18,
    -11, -11, -11, -11, -11, -11, -11, -10,
    -11, -9, -11, -11, -11, -22, -11, -22,
    -8, -11, -11, -17, -14, -13, -8, -8,
    -14, -8, -8, -11, -11, -11, -11, -11,
    -8, -8, -11, -8, -11, -8, -8, -11,
    -11, -11, -15, -15, -13, -11, -3, -3,
    -3, -3, -6, -6, -6, -6, -6, -6,
    -15, -6, -14, -18, -8, -18, -8, -15,
    -14, -14, -23, -22, -17, -8, -8, -8,
    -8, -8, 10, -16, -17, -17, -17, -17,
    -9, -9, -17, -9, -17, -9, -15, -9,
    -18, -16, -17, -9, -9, -9, -14, -8,
    -8, -8, -8, -9, -3, -3, -3, -3,
    6, -3, -3, -3, -18, -18, -18, 9,
    9, -8, -11, -14, -8, -8, -8, -8,
    -9, -11, -13, -17, -11, -18, 1, -8,
    -11, -15, -11, -8, -31, -31, -10, -18,
    -22, -15, -15, -10, -24, -10, -13, -10,
    -10, -10, -10, -9, -9, -9, -9, -13,
    -9, -18, -18, -15, 8, 22, 10, 10,
    10, 10, -18, -18, -9, -10, -11, -11,
    -17, -11, -4, -4, -3, -8, -9, -11,
    -11, -6, -19, -11, -3, -4, -4, -5,
    -4, -3, -17, -14, -1, 8, -11, -11,
    -11, -19, -11, -4, -3, -4, -6, -13,
    -6, -13, -6, -14, -8, -14, 2, -3,
    -3, -5, -5, -5, -5, -5, -5, -5,
    -6, -3, -5, -11, 8, -9, -10, -11,
    -11, -17, -11, -4, -4, 8, 8, 8,
    8, 8, 9, 8, 8, 8, 8, 8,
    8, 9, 8, -10, -10, -10, -19, -13,
    -5, -5, -5, -5, -5, -5, -10, -5,
    8, -9, -10, -11, -11, -17, -11, -4,
    -4, -9, -10, -11, -11, -17, -11, -4,
    -4, -3, -8, -9, -11, -11, -6, -19,
    -11, -3, -4, -4, -5, -4, -3, -3,
    -8, -9, -11, -11, -6, -19, -11, -3,
    -4, -4, -5, -4, -3, -11, 8, -9,
    -14, -9, -14, -8, -9, -9, -13, -13,
    -8, -4, -4, -4, 8, -4, -4, -4,
    8, 4, 2, 4, 4, -9, -4, -17,
    -10, -8, -17, -10, -4, -4, -3, -6,
    3, 3, 3, 3, 3, 3, 3, 3,
    3, 3, 3, 3, -8, -2, -2, -3,
    -2, 3, -1, -1, -1, -1, 3, 3,
    3, -1, -1, -2, 3, -4, -1, -11,
    -13, -8, -8, -13, -8, -9, -15, -14,
    -8, -8, -18, -4, -4, -4, -4, -4,
    -4, -4, -4, -4, -8, -17, -17, -15,
    -13, -11, -8, -4, -4, -4, -4, -4,
    -4, -4, -5, -5, -8, -14, -5, -5,
    -5, -5, -5, -5, -5, -5, -8, -8,
    -13, -8, -9, -15, -14, -8, -8, -18,
    -4, -4, -4, -4, -4, -4, -4, -4,
    -4, -8, -3, -3, -3, -3, -3, -3,
    -3, -3, -3, -3, -3, 6, -3, -3,
    -3, 8, -8, -3, -5, -17, -11, -11,
    -14, -18, -11, -5, -9, -10, -11, -11,
    -17, -11, -4, -4, -3, -8, -11, -11,
    -11, -6, -19, -11, -3, -4, -4, -5,
    -4, -3, -11, -13
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 868,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_Inter14 = {
#else
lv_font_t ui_font_Inter14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_INTER14*/
