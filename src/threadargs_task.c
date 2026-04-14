#include "threadargs_task.h"

void *threadArgsFunction(void *arg)
{
    int threadNum = (int)(long)arg; // Cast the argument to an integer representing the thread number
    printf("Hello from thread %d!\n", threadNum); // Print a message from the thread
}


int main(int argc, char const *argv[])
{
    /* code */
    pthread_t threads[thread_count];
    for (size_t i = 0; i < thread_count; i++)
    {
        /* code */
        pthread_create(&threads[i], NULL, threadArgsFunction, (void *)i); // Create threads that execute the threadArgsFunction
    }
    for (size_t i = 0; i < thread_count; i++)
    {
        /* code */
        pthread_join(threads[i], NULL); // Wait for all threads to finish
    }   

    return 0;
}

