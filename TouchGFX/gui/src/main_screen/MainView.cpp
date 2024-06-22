#include <gui/main_screen/MainView.hpp>
#include <BitmapDatabase.hpp>

#ifndef SIMULATOR
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
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
    list.setHeight(0); //Compensates for the list height that is set to 200 by the designer
    // 버스 정보 (아이콘, 노선 정보, 도착 정보)
    listElements[0].setupListElement(Bitmap(BITMAP_B_ID), "720-1", "5");
    
    for (auto & listElement : listElements)
    {
        listElement.setAction(listElementClickedCallback);
        list.add(listElement);
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

void MainView::updateBusInfo()
{
    presenter->fetchBusInfo();
}

void MainView::setBusInfo(const BusInfo& busInfo)
{
#ifdef SIMULATOR
    touchgfx_printf("[DEBUG] setBusInfo called\n");
#else
    HAL_UART_Transmit(&huart1, (uint8_t *)"[DEBUG] setBusInfo called\n", 30, HAL_MAX_DELAY);
#endif

    list.removeAll();

    // 예측 시간을 문자열로 변환
    char predictTimeBuffer[32];
    snprintf(predictTimeBuffer, sizeof(predictTimeBuffer) / sizeof(predictTimeBuffer[0]), "%d", busInfo.predictTimeSec1);

    // listElements 배열을 사용하여 데이터를 설정
    listElements[0].setupListElement(Bitmap(BITMAP_B_ID), busInfo.routeName, predictTimeBuffer);
}