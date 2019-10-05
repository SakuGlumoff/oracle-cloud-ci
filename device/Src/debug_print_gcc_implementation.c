#include "debug_print.h"
#include "error.h"

int debug_print_callback(char* debugMessage, unsigned int length)
{
#if defined(UNIT_TEST)
#include <stdio.h>
    printf("%s", debugMessage);
    return ERROR_OK;
#elif defined(INTEGRATION_TEST)
#include <stdio.h>
    return ERROR_NOT_IMPLEMENTED;
#else
    return ERROR_OK;
#endif
}
