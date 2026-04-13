#include "threadloop_task.h"

void *threadLoopFunction(void *arg)
{
    pthread_mutex_lock(&loopMutex); // Lock the mutex before accessing the shared counter
    for (size_t i = 0; i < 1000000; i++)
    {
        /* code */
        loopCounter++; // Increment the shared counter  
    }
    pthread_mutex_unlock(&loopMutex); // Unlock the mutex after accessing the shared counter
    return NULL;
}

int main(int argc, char const *argv[])
{
    /* code */
    pthread_mutex_init(&loopMutex, NULL); // Initialize the mutex
    pthread_t threads[thread_count];
    for (size_t i = 0; i < thread_count; i++)
    {
        /* code */
        pthread_create(&threads[i], NULL, threadLoopFunction, NULL); // Create threads
    }
    for (size_t i = 0; i < thread_count; i++)
    {
        /* code */
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }
    pthread_mutex_destroy(&loopMutex); // Destroy the mutex after use
    printf("Loop Counter from %d threads: %d\n", thread_count, loopCounter);
    return 1;
}
