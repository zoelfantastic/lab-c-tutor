#include <stdio.h>
#include <pthread.h>
#include "thread_task.h"

void *threadFunction(void *arg)
{
   
    printf("Hello from %s!\n", (char *)arg);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t tid1, tid2;
    
    pthread_create(&tid2, NULL, threadFunction, (void *) "Thread 2"); // Create a new thread 2 that runs the threadFunction
    pthread_create(&tid1, NULL, threadFunction, (void *) "Thread 1"); // Create a new thread 1 that runs the threadFunction
    
    pthread_join(tid1, NULL); // Wait for the thread to finish before exiting the main thread
    pthread_join(tid2, NULL); // Wait for the thread to finish before exiting the main thread
    
    printf("Hello from the main thread!\n");
    return 0;
}

