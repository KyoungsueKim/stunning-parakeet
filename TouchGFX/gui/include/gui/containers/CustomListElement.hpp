#ifndef CUSTOMLISTELEMENT_HPP
#define CUSTOMLISTELEMENT_HPP

#include <gui_generated/containers/CustomListElementBase.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/Bitmap.hpp>
#include <texts/TextKeysAndLanguages.hpp>

class CustomListElement : public CustomListElementBase
{
public:
    CustomListElement();
    virtual ~CustomListElement() {}

    /**
     * Initialize this containers widgets
     */
    void setupListElement(const Bitmap& iconBMP, TEXTS busArrivingTextID, TEXTS busLineTextID);

    /**
     * Setup the view callback
     */
    void setAction(GenericCallback< CustomListElement& >& callback);

    const char* getBusLineNumber() const;

    virtual void callBusAction();

protected:

    /**
     * Callback that that notifies the creator of the list element of an event
     */
    GenericCallback< CustomListElement& >* viewCallback;

private:
    Unicode::UnicodeChar busLineNumberTextAreaBuffer[32];
};

#endif // CUSTOMLISTELEMENT_HPP
