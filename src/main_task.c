#include <stdio.h>
#include <pthread.h>
#include "main_task.h"

int main(void)
{
    const char *message = main_greeting();
    printf("%s\n", message);
    return 0;
}

const char *main_greeting(void)
{
    return "Hello, World!";
}