#include <gui/main_screen/MainView.hpp>
#include <BitmapDatabase.hpp>

#ifndef SIMULATOR
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#include <cstring>
#include "main.h"

extern UART_HandleTypeDef huart1;
extern HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
extern osMessageQueueId_t busInfoQueueHandle;
#endif

MainView::MainView()
        : listElementClickedCallback(this, &MainView::listElementClicked)
{
}

void MainView::setupScreen()
{
    list.setHeight(0); // Compensates for the list height that is set to 200 by the designer
    // 초기 설정은 필요하지 않음.

    listElements[0].setupListElement(Bitmap(BITMAP_B_ID), "720-1", "5");
    listElements[0].setAction(listElementClickedCallback);
    list.add(listElements[0]);

    currentElementIndex++;
}

void MainView::tearDownScreen()
{
}

void MainView::listElementClicked(CustomListElement& element)
{
    // The button of the list element has been pressed
    presenter->sendCallBusRequest(element);
}

void MainView::updateBusInfo()
{
    presenter->fetchBusInfo();
}

void MainView::addBusInfo(const BusInfo& busInfo)
{
#ifdef SIMULATOR
    touchgfx_printf("[DEBUG] addBusInfo called\n");
#else
    printf("[DEBUG] addBusInfo() called. BusInfo: <routeName: %s, predictTimeSec1: %d, routeId: %s, vehId1: %s, remainSeatCnt1: %d, staOrder: %d>\r\n", busInfo.routeName, busInfo.predictTimeSec1, busInfo.routeId, busInfo.vehId1, busInfo.remainSeatCnt1, busInfo.staOrder);
#endif

    if (currentElementIndex < maximumListElements)
    {
        // 예상 도착 시간을 문자열로 변환
        char predictTimeStr[32];
        snprintf(predictTimeStr, sizeof(predictTimeStr), "%d", busInfo.predictTimeSec1);

        // CustomListElement 설정
        listElements[currentElementIndex].setupListElement(Bitmap(busInfo.remainSeatCnt1 ? BITMAP_R_ID : BITMAP_G_ID), busInfo.routeName, predictTimeStr);
        listElements[currentElementIndex].setAction(listElementClickedCallback);
        listElements[currentElementIndex].busInfo = busInfo;

        currentElementIndex++;
        printf("[Debug] currentElementIndex: %d\r\n", currentElementIndex);
    }
    else
    {
#ifdef SIMULATOR
        touchgfx_printf("[ERROR] Maximum list elements reached\n");
#else
        printf("[ERROR] Maximum list elements reached\r\n");
#endif
    }
}

void MainView::updateMainView()
{
    printf("[DEBUG] updateMainView() called\n");
    list.removeAll();
    for(int i = 0; i < currentElementIndex; i++)
    {
        list.add(listElements[i]);
    }
    scrollCnt.invalidate();
    currentElementIndex = 0;
}