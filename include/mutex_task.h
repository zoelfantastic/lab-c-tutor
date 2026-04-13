#ifndef MUTEX_TASK_H
#define MUTEX_TASK_H  

const int count = 1000000; // Number of increments each thread will perform
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize a mutex
int sharedCounter = 0; // A shared counter variable

void *mutexFunction(void *arg);

#endif // MUTEX_TASK_H