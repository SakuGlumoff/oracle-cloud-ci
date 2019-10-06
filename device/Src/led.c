#include "led.h"
#include "error.h"
#include "main.h"
#include "stm32f4xx_hal_gpio.h"

int led_turnOn(void)
{
    HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
    return ERROR_OK;
}

int led_turnOff(void)
{
    HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
    return ERROR_OK;
}

int led_readState(void)
{
    GPIO_PinState ledState = 0;
    ledState = HAL_GPIO_ReadPin(LD1_GPIO_Port, LD1_Pin);
    return (int)ledState;
}
