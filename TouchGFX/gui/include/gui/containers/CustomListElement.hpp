#ifndef CUSTOMLISTELEMENT_HPP
#define CUSTOMLISTELEMENT_HPP

#include <gui_generated/containers/CustomListElementBase.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/Bitmap.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "main.h"

class CustomListElement : public CustomListElementBase
{
public:
    CustomListElement();
    CustomListElement(const Bitmap &iconBMP, Unicode::UnicodeChar* busLineText, Unicode::UnicodeChar* busArrivingText);
    CustomListElement(const Bitmap &iconBMP, const char* busLineText, const char* busArrivingText);
    virtual ~CustomListElement() {}

    /**
     * Initialize this containers widgets
     */
    void setupListElement(const Bitmap &iconBMP, Unicode::UnicodeChar* busLineText, Unicode::UnicodeChar* busArrivingText);
    void setupListElement(const Bitmap &iconBMP, const char* busLineText, const char* busArrivingText);

    /**
     * Setup the view callback
     */
    void setAction(GenericCallback< CustomListElement& >& callback);

    virtual void callBusAction();

    BusInfo busInfo;

protected:

    /**
     * Callback that that notifies the creator of the list element of an event
     */
    GenericCallback< CustomListElement& >* viewCallback;

private:

};

#endif // CUSTOMLISTELEMENT_HPP
