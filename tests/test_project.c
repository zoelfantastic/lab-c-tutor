#include <assert.h>
#include <string.h>
#include "project.h"

int main(void)
{
    const char *message = project_greeting();
    assert(message != NULL);
    assert(strcmp(message, "Hello from lab_c_tutor!") == 0);
    return 0;
}
