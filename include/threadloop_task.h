#ifndef THREAD_LOOP_TASK_H
#define THREAD_LOOP_TASK_H

#include <stdio.h>
#include <pthread.h>

const int thread_count = 25;
pthread_mutex_t loopMutex = PTHREAD_MUTEX_INITIALIZER; // Initialize a mutex for the thread loop
int loopCounter = 0; // A shared counter variable for the thread loop

void *threadLoopFunction(void *arg);

#endif // THREAD_LOOP_TASK_H