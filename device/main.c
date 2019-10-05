#include "error.h"
#include "unit_test.h"

int main(void)
{
    int error = ERROR_OK;
#if defined(UNIT_TEST)
    error = unit_test_init();
    if (error) return error;
    
    error = unit_test_run();
    if (error) return error;
#elif defined(INTEGRATION_TEST)
#else
#endif //Configurations
    return error;
}
