/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId LARGE = 1;
    static const touchgfx::FontId SMALL = 2;
    static const touchgfx::FontId TYPOGRAPHY = 3;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;    // NanumGothic_24_4bpp
    static const touchgfx::FontId LARGE = 1;      // NanumGothic_14_4bpp
    static const touchgfx::FontId SMALL = 2;      // NanumGothic_15_4bpp
    static const touchgfx::FontId TYPOGRAPHY = 3; // NanumGothic_20_4bpp
    static const uint16_t NUMBER_OF_FONTS = 4;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /*flashReader*/)
    {
    }

    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
