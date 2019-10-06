#include "debug_print.h"
#include "error.h"

#if defined(UNIT_TEST)
#include <stdio.h>
#endif

#if defined(INTEGRATION_TEST)
#include "usart.h"
#include "stm32f4xx_hal_uart.h"
#endif

int debug_print_callback(char *debugMessage, unsigned int length)
{
#if defined(UNIT_TEST)
    printf("%s", debugMessage);
    return ERROR_OK;
#elif defined(INTEGRATION_TEST)
    if (HAL_UART_Transmit_IT(&huart2, (uint8_t*)debugMessage, (uint16_t)length) == HAL_OK)
    {
        return ERROR_OK;
    }
    else
    {
        return ERROR_USART_FAIL;
    }
#else
    return ERROR_OK;
#endif
}
