#include <assert.h>
#include <string.h>
#include "main_task.h"

int main(void)
{
    const char *message = main_greeting();
    assert(message != NULL);
    assert(strcmp(message, "Hello from lab_c_tutor!") == 0);
    return 0;
}
