#include <stdio.h>
#include "project.h"
#include "thread_task.h"
#include <pthread.h>

int main(void)
{
    // const char *message = project_greeting();
    // printf("%s\n", message);

    pthread_t tid;
    pthread_create(&tid, NULL, threadFunction, NULL); // Create a new thread that runs the threadFunction
    pthread_join(tid, NULL); // Wait for the thread to finish before exiting the main thread
    printf("Hello from the main thread!\n");
    return 0;
}
