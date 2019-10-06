#include "button.h"
#include "main.h"
#include "stm32f4xx_hal_gpio.h"

int button_readState(void)
{
    GPIO_PinState buttonState = 0;
    buttonState = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
    return (int)buttonState;
}
