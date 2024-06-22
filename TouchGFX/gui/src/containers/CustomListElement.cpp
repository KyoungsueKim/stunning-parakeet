#include <gui/containers/CustomListElement.hpp>
#include <BitmapDatabase.hpp>

CustomListElement::CustomListElement() : viewCallback(0)
{
    
}

void CustomListElement::setupListElement(const Bitmap &iconBMP, TEXTS busLineTextID, TEXTS busArrivingTextID)
{
    busCharacterScaleableImage.setBitmap(iconBMP);
    busCharacterScaleableImage.setWidth(45);
    busCharacterScaleableImage.setHeight(36);
    busCharacterScaleableImage.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    busArrivingTextArea.setTypedText(busArrivingTextID);
    busArrivingTextArea.resizeToCurrentText();

    busLineNumberTextArea.setTypedText(busLineTextID);
    busLineNumberTextArea.resizeToCurrentText();

    invalidate();
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
