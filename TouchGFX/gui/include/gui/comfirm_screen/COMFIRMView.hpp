#ifndef COMFIRMVIEW_HPP
#define COMFIRMVIEW_HPP

#include <gui_generated/comfirm_screen/COMFIRMViewBase.hpp>
#include <gui/comfirm_screen/COMFIRMPresenter.hpp>

class COMFIRMView : public COMFIRMViewBase
{
public:
    COMFIRMView();
    virtual ~COMFIRMView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void callBusBell();
protected:
};

#endif // COMFIRMVIEW_HPP
