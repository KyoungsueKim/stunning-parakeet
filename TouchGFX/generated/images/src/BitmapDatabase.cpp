// 4.24.0 0xfea895ac
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_alternate_theme_images_widgets_button_regular_height_36_tiny_round_inactive[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUND_INACTIVE_ID = 0, Size: 100x36 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_regular_height_36_tiny_round_normal[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUND_NORMAL_ID = 1, Size: 100x36 pixels
extern const unsigned char image_b[]; // BITMAP_B_ID = 2, Size: 1123x1000 pixels
extern const unsigned char image_bg[]; // BITMAP_BG_ID = 3, Size: 480x272 pixels
extern const unsigned char image_g[]; // BITMAP_G_ID = 4, Size: 1123x1000 pixels
extern const unsigned char image_list_element_background[]; // BITMAP_LIST_ELEMENT_BACKGROUND_ID = 5, Size: 413x44 pixels
extern const unsigned char image_r[]; // BITMAP_R_ID = 6, Size: 1123x1000 pixels
extern const unsigned char image_y[]; // BITMAP_Y_ID = 7, Size: 1123x1000 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_alternate_theme_images_widgets_button_regular_height_36_tiny_round_inactive, 0, 100, 36, 17, 0, 66, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 3, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_regular_height_36_tiny_round_normal, 0, 100, 36, 12, 1, 76, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 34, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_b, 0, 1123, 1000, 0, 0, 1123, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 1000, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 },
    { image_bg, 0, 480, 272, 0, 0, 480, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 272, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 },
    { image_g, 0, 1123, 1000, 0, 0, 1123, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 1000, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 },
    { image_list_element_background, 0, 413, 44, 0, 0, 413, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 44, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 },
    { image_r, 0, 1123, 1000, 0, 0, 1123, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 1000, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 },
    { image_y, 0, 1123, 1000, 0, 0, 1123, ((uint8_t)touchgfx::Bitmap::RGB888) >> 3, 1000, ((uint8_t)touchgfx::Bitmap::RGB888) & 0x7 }
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
