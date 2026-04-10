#include <stdio.h>
#include <pthread.h>
#include "mutex_task.h"

const int count = 1000000; // Number of increments each thread will perform
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize a mutex
int sharedCounter = 0; // A shared counter variable

void *mutexFunction(void *arg)
{
    pthread_mutex_lock(&mutex); // Lock the mutex before accessing the shared counter
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        sharedCounter++; // Increment the shared counter
    }
    pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the shared counter
}

int main(int argc, char const *argv[])
{
    /* code */
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex
    pthread_create(&t1, NULL, mutexFunction, NULL); // Create first thread
    pthread_create(&t2, NULL, mutexFunction, NULL); // Create second thread
    pthread_join(t1, NULL); // Wait for the first thread to finish
    pthread_join(t2, NULL); // Wait for the second thread to finish
    pthread_mutex_destroy(&mutex); // Destroy the mutex after use
    printf("Shared Counter from 2 threads: %ld\n", (long)sharedCounter);
    return 0;
}
