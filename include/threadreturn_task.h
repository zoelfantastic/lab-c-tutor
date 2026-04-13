#ifndef THREAD_RETURN_TASK_H
#define THREAD_RETURN_TASK_H  

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

int *returnValue = NULL; // A pointer to hold the return value from the thread
void *threadReturnFunction(void *arg);


#endif // THREAD_RETURN_TASK_H