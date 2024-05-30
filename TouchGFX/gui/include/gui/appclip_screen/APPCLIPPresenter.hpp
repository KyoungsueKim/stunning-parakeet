#ifndef APPCLIPPRESENTER_HPP
#define APPCLIPPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class APPCLIPView;

class APPCLIPPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    APPCLIPPresenter(APPCLIPView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~APPCLIPPresenter() {}

private:
    APPCLIPPresenter();

    APPCLIPView& view;
};

#endif // APPCLIPPRESENTER_HPP
