#include <gui/main_screen/MainView.hpp>
#include <BitmapDatabase.hpp>

MainView::MainView()
    : listElementClickedCallback(this, &MainView::listElementClicked)
{
}

void MainView::setupScreen()
{
    list.setHeight(0); //Compensates for the list height that is set to 200 by the designer
    // 버스 정보 (아이콘, 노선 정보, 도착 정보)
    listElements[0].setupListElement(Bitmap(BITMAP_B_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[1].setupListElement(Bitmap(BITMAP_G_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[2].setupListElement(Bitmap(BITMAP_R_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[3].setupListElement(Bitmap(BITMAP_Y_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[4].setupListElement(Bitmap(BITMAP_B_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[5].setupListElement(Bitmap(BITMAP_G_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[6].setupListElement(Bitmap(BITMAP_R_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[7].setupListElement(Bitmap(BITMAP_Y_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[8].setupListElement(Bitmap(BITMAP_B_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    listElements[9].setupListElement(Bitmap(BITMAP_G_ID), T_BUS_LINE_NUM, T_BUS_ARRIVING);
    
    for (uint8_t i = 0; i < numberOfListElements; ++i)
    {
        listElements[i].setAction(listElementClickedCallback);
        list.add(listElements[i]);
    }
}

void MainView::tearDownScreen()
{
    
}

void MainView::listElementClicked(CustomListElement& element)
{
    // The button of the list element has been pressed
    presenter->sendCallBusRequest(element);
    scrollCnt.invalidate();
}
