#ifndef THREAD_ARGS_TASK_H
#define THREAD_ARGS_TASK_H

#include <stdio.h>
#include <pthread.h>

const int thread_count = 10; // Number of threads to create
// pthread_mutex_t mutexThread = PTHREAD_MUTEX_INITIALIZER; // Initialize a mutex for thread arguments

void *threadArgsFunction(void *arg);

#endif // THREAD_ARGS_TASK_H