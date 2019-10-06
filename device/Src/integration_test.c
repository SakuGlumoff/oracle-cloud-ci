#include "integration_test.h"
#include "debug_print.h"
#include "error.h"

#define ASSERT_EQUALS(a, b) if (a != b) { DBG_PRINT_ERROR("Assert fail"); return ERROR_ASSERT_FAIL; }

static int add(void)
{
    int a = 1;
    int b = 2;

    int addition = a + b;
    ASSERT_EQUALS(addition, 3);

    return ERROR_OK;
}

static int multiply(void)
{
    int a = 1;
    int b = 2;

    int multiplication = a * b;
    ASSERT_EQUALS(multiplication, 2);

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
    {"Addition", add},
    {"Multiply", multiply}
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
        DBG_PRINTF_TRACE("Integration test: run (%d/%d): %s", i, INTEGRATION_TEST_COUNT, INTEGRATION_TESTS[i].name);
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
