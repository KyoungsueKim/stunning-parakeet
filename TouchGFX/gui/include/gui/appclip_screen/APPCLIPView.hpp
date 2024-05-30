#ifndef APPCLIPVIEW_HPP
#define APPCLIPVIEW_HPP

#include <gui_generated/appclip_screen/APPCLIPViewBase.hpp>
#include <gui/appclip_screen/APPCLIPPresenter.hpp>

class APPCLIPView : public APPCLIPViewBase
{
public:
    APPCLIPView();
    virtual ~APPCLIPView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // APPCLIPVIEW_HPP
