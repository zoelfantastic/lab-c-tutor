#include <stdio.h>
#include <pthread.h>
#include "mutex_task.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize a mutex
int sharedCounter = 0; // A shared counter variable

void *mutexFunction(void *arg)
{
    pthread_mutex_lock(&mutex); // Lock the mutex before accessing the shared counter
    sharedCounter++; // Increment the shared counter
    printf("Thread %ld incremented counter to %d\n", (long)arg, sharedCounter);
    pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the shared counter
    pthread_exit(NULL);
}

