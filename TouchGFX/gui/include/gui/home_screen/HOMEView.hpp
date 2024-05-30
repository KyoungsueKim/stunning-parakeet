#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include <gui_generated/home_screen/HOMEViewBase.hpp>
#include <gui/home_screen/HOMEPresenter.hpp>

class HOMEView : public HOMEViewBase
{
public:
    HOMEView();
    virtual ~HOMEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // HOMEVIEW_HPP
