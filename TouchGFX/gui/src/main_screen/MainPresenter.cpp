#include <cstdio>
#include <cstring>

#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

#ifndef SIMULATOR
#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
#include "main.h"

extern UART_HandleTypeDef huart1;
extern HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
extern osMessageQueueId_t busInfoQueueHandle;
#endif


MainPresenter::MainPresenter(MainView &v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::sendCallBusRequest(const CustomListElement& element)
{
    const char* busLineNumber = element.busInfo.routeName;

    // "<request> (call_bus) %s\n";
    char request[128];
    sprintf(request, "<request> (call_bus) {%d, %s, %s}\n", element.busInfo.staOrder, element.busInfo.routeId, element.busInfo.vehId1);

#ifdef SIMULATOR
    touchgfx_printf(request);
#else
    HAL_UART_Transmit(&huart1, (uint8_t *)request, strlen(request), HAL_MAX_DELAY);
#endif
}

void MainPresenter::fetchBusInfo()
{
    BusInfo busInfo;
    if (osMessageQueueGet(busInfoQueueHandle, &busInfo, NULL, 0) == osOK)
    {
        view.addBusInfo(busInfo);
        if (osMessageQueueGetCount(busInfoQueueHandle) <= 0)
        {
            view.updateMainView();
        }
    }
}