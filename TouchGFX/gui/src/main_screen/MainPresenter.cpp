#include <cstdio>
#include <cstring>

#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

#ifndef SIMULATOR
#include "stm32h7xx_hal.h"

extern UART_HandleTypeDef huart1;
extern HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
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
    // Send a request to the bus via uart. 
    // The bus will send a response back to the presenter
    // The presenter will then update the view
    // HAL_UART_Transmit(&huart1, (uint8_t *)"aa", 2, HAL_MAX_DELAY);

    const char* busLineNumber = element.getBusLineNumber();

    // "<request> (call_bus) %s\n";
    char request[64];
    sprintf(request, "<request> (call_bus) {%s}\n", busLineNumber);

#ifdef SIMULATOR
    touchgfx_printf(request);
#else
    HAL_UART_Transmit(&huart1, (uint8_t *)request, strlen(request), HAL_MAX_DELAY);
#endif
}
