#include <gui/containers/CustomListElement.hpp>
#include <BitmapDatabase.hpp>

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
    busCharacterScaleableImage.setBitmap(iconBMP);
    busCharacterScaleableImage.setWidth(45);
    busCharacterScaleableImage.setHeight(36);
    busCharacterScaleableImage.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    busArrivingTextArea.setTypedText(T_BUS_LINE_NUM);
    busArrivingTextArea.setWildcard(busArrivingText);
    busArrivingTextArea.resizeToCurrentText();

    busLineNumberTextArea.setTypedText(T_BUS_ARRIVING);
    busLineNumberTextArea.setWildcard(busLineText);
    busLineNumberTextArea.resizeToCurrentText();

    invalidate();
}

void CustomListElement::setupListElement(const Bitmap &iconBMP, const char* busLineText, const char* busArrivingText) {
    Unicode::UnicodeChar busLineTextBuffer[32];
    Unicode::UnicodeChar busArrivingTextBuffer[32];

    Unicode::snprintf(busLineTextBuffer, sizeof(busLineTextBuffer), "%s", busLineText);
    Unicode::snprintf(busArrivingTextBuffer, sizeof(busArrivingTextBuffer), "%s", busArrivingText);

    this->setupListElement(iconBMP, busLineTextBuffer, busArrivingTextBuffer);
}

void CustomListElement::setAction(GenericCallback<CustomListElement &> &callback)
{
    viewCallback = &callback;
}

const char* CustomListElement::getBusLineNumber() const {
    static char utf8Buffer[64]; // UTF-8 문자열을 저장할 버퍼 (적절한 크기로 설정 필요)
    touchgfx::Unicode::toUTF8(busLineNumberTextArea.getTypedText().getText(), reinterpret_cast<uint8_t*>(utf8Buffer),
                              sizeof(utf8Buffer));
    return utf8Buffer;
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
