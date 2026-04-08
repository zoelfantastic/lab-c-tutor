#include <stdio.h>
#include <pthread.h>
#include "thread_task.h"

void *threadFunction(void *arg)
{
    printf("Hello from the thread!\n");
    pthread_exit(NULL);
    //return NULL;
}
