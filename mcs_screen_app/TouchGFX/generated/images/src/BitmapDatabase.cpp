// 4.21.0 0xb1565835
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_drive_1[]; // BITMAP_DRIVE_1_ID = 0, Size: 75x60 pixels
extern const unsigned char image_drive_10a[]; // BITMAP_DRIVE_10A_ID = 1, Size: 150x27 pixels
extern const unsigned char image_drive_10a_green[]; // BITMAP_DRIVE_10A_GREEN_ID = 2, Size: 150x27 pixels
extern const unsigned char image_drive_10b[]; // BITMAP_DRIVE_10B_ID = 3, Size: 140x17 pixels
extern const unsigned char image_drive_1_blue[]; // BITMAP_DRIVE_1_BLUE_ID = 4, Size: 75x60 pixels
extern const unsigned char image_drive_1_green[]; // BITMAP_DRIVE_1_GREEN_ID = 5, Size: 75x60 pixels
extern const unsigned char image_drive_1_red[]; // BITMAP_DRIVE_1_RED_ID = 6, Size: 75x60 pixels
extern const unsigned char image_drive_1_yellow[]; // BITMAP_DRIVE_1_YELLOW_ID = 7, Size: 75x60 pixels
extern const unsigned char image_drive_2[]; // BITMAP_DRIVE_2_ID = 8, Size: 120x65 pixels
extern const unsigned char image_drive_3[]; // BITMAP_DRIVE_3_ID = 9, Size: 84x60 pixels
extern const unsigned char image_drive_5[]; // BITMAP_DRIVE_5_ID = 10, Size: 272x65 pixels
extern const unsigned char image_drive_5a[]; // BITMAP_DRIVE_5A_ID = 11, Size: 272x65 pixels
extern const unsigned char image_drive_5b[]; // BITMAP_DRIVE_5B_ID = 12, Size: 96x45 pixels
extern const unsigned char image_drive_5c[]; // BITMAP_DRIVE_5C_ID = 13, Size: 259x54 pixels
extern const unsigned char image_lauch_1[]; // BITMAP_LAUCH_1_ID = 14, Size: 480x272 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_drive_1, 0, 75, 60, 3, 57, 69, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_10a, 0, 150, 27, 2, 0, 146, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 2, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_10a_green, 0, 150, 27, 2, 0, 146, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 2, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_10b, 0, 140, 17, 0, 0, 140, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 17, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_drive_1_blue, 0, 75, 60, 3, 57, 69, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_1_green, 0, 75, 60, 3, 57, 69, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_1_red, 0, 75, 60, 3, 57, 69, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_1_yellow, 0, 75, 60, 3, 57, 69, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_2, 0, 120, 65, 3, 0, 114, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_3, 0, 84, 60, 2, 58, 80, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 2, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_5, 0, 272, 65, 2, 0, 268, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 2, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_5a, 0, 272, 65, 2, 0, 268, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 2, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_drive_5b, 0, 96, 45, 0, 0, 96, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 45, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_drive_5c, 0, 259, 54, 102, 0, 27, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 54, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_lauch_1, 0, 480, 272, 320, 79, 22, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 71, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase