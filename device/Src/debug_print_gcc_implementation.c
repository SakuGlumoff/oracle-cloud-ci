#include "debug_print.h"
#include "error.h"

#if defined(UNIT_TEST)
#include <stdio.h>
#endif

int debug_print_callback(char *debugMessage, unsigned int length)
{
#if defined(UNIT_TEST)
    printf("%s", debugMessage);
    return ERROR_OK;
#elif defined(INTEGRATION_TEST)
    return ERROR_NOT_IMPLEMENTED;
#else
    return ERROR_OK;
#endif
}
