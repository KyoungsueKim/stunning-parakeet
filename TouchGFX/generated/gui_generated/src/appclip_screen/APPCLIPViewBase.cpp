/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/appclip_screen/APPCLIPViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

APPCLIPViewBase::APPCLIPViewBase() :
    buttonCallback(this, &APPCLIPViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    BG.setPosition(0, 0, 480, 272);
    BG.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    add(BG);

    back.setXY(351, 209);
    back.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUND_INACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUND_NORMAL_ID));
    back.setLabelText(touchgfx::TypedText(T___SINGLEUSE_4P5O));
    back.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    back.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    back.setAction(buttonCallback);
    add(back);

    textArea1.setXY(37, 32);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_33F0));
    add(textArea1);
}

APPCLIPViewBase::~APPCLIPViewBase()
{

}

void APPCLIPViewBase::setupScreen()
{

}

void APPCLIPViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &back)
    {
        //Interaction1
        //When back clicked change screen to HOME
        //Go to HOME with no screen transition
        application().gotoHOMEScreenNoTransition();
    }
}
