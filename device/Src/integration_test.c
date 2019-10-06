#include "integration_test.h"
#include "debug_print.h"
#include "error.h"
#include "button.h"
#include "led.h"
#include "stm32f4xx_hal.h"

#define ASSERT_EQUALS(a, b) if (a != b) { DBG_PRINT_ERROR("Assert fail"); return ERROR_ASSERT_FAIL; }

static int test_button(void)
{
    int realButtonState = 0;
    const int expectedButtonState = 1;

    realButtonState = button_readState();
    ASSERT_EQUALS(realButtonState, expectedButtonState);

    return ERROR_OK;
}

static int test_led(void)
{
    int realLedState = 0;
    const int expectedLedState = 0;

    led_turnOn();
    HAL_Delay(1000);
    led_turnOff();
    realLedState = led_readState();
    ASSERT_EQUALS(realLedState, expectedLedState);

    return ERROR_OK;
}

typedef struct IntegrationTest
{
    char *name;
    int (*testFunc)(void);
} integration_test_t;

#define INTEGRATION_TEST_COUNT (2)
static const integration_test_t INTEGRATION_TESTS[INTEGRATION_TEST_COUNT] =
{
    {"Button", test_button},
    {"Led", test_led}
};

int integration_test_init(void)
{
    int error = ERROR_OK;

    //TODO: Initializations

    return error;
}

int integration_test_run(void)
{
    int error = ERROR_OK;
    int testsRan = 0;
    int testsFailed = 0;
    int testsSucceeded = 0;

    DBG_PRINT_TRACE("Integration test: start");
    int i = 0;
    for (i = 0; i < INTEGRATION_TEST_COUNT; i++)
    {
        DBG_PRINTF_TRACE("Integration test: run (%d/%d): %s", i+1, INTEGRATION_TEST_COUNT, INTEGRATION_TESTS[i].name);
        testsRan++;
        int testStatus = INTEGRATION_TESTS[i].testFunc();
        if (testStatus)
        {
            testsFailed++;
        }
        else
        {
            testsSucceeded++;
        }
    }
    DBG_PRINTF_TRACE("Integration test: end: { Total: %d, Failed: %d, Succeeded: %d }", testsRan, testsFailed, testsSucceeded);

    return error;
}
