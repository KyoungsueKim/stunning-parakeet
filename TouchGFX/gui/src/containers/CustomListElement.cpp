#include <gui/containers/CustomListElement.hpp>
#include <BitmapDatabase.hpp>

#include <cstring>

CustomListElement::CustomListElement() : viewCallback(0)
{
    
}

CustomListElement::CustomListElement(const Bitmap &iconBMP, Unicode::UnicodeChar* busLineText, Unicode::UnicodeChar* busArrivingText) : viewCallback(0)
{
    setupListElement(iconBMP, busLineText, busArrivingText);
}

CustomListElement::CustomListElement(const Bitmap &iconBMP, const char* busLineText, const char* busArrivingText) : viewCallback(0) {
    setupListElement(iconBMP, busLineText, busArrivingText);
}

void CustomListElement::setupListElement(const Bitmap &iconBMP, Unicode::UnicodeChar* busLineText, Unicode::UnicodeChar* busArrivingText)
{

}

void CustomListElement::setupListElement(const Bitmap &iconBMP, const char* busLineText, const char* busArrivingText) {
    Unicode::strncpy(busLineNumberTextAreaBuffer, busLineText, strlen(busLineText));
    busLineNumberTextArea.resizeToCurrentText();
    Unicode::strncpy(busArrivingTextAreaBuffer, busArrivingText, strlen(busArrivingText));
    busArrivingTextArea.resizeToCurrentText();

    busCharacterScaleableImage.setBitmap(iconBMP);
    busCharacterScaleableImage.setWidth(45);
    busCharacterScaleableImage.setHeight(36);
    busCharacterScaleableImage.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    invalidate();
}

void CustomListElement::setAction(GenericCallback<CustomListElement &> &callback)
{
    viewCallback = &callback;
}

// interaction name: callBusInteraction     function name: callBusAction
void CustomListElement::callBusAction()
{
    // Inform the view of the event
    if (viewCallback->isValid())
    {
        viewCallback->execute(*this);
    }
}
