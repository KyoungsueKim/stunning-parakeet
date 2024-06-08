#include <gui/comfirm_screen/COMFIRMView.hpp>
#include <touchgfx/Utils.hpp>

COMFIRMView::COMFIRMView()
{

}

void COMFIRMView::setupScreen()
{
    COMFIRMViewBase::setupScreen();
}

void COMFIRMView::tearDownScreen()
{
    COMFIRMViewBase::tearDownScreen();
}

void COMFIRMView::callBusBell(){
	touchgfx_printf("Button Clicked!\n");
}
