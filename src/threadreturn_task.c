#include "threadreturn_task.h"

int main(int argc, char const *argv[])
{
    /* code */
    returnValue = (int *)malloc(sizeof(int)); // Allocate memory for the return value
    if (returnValue == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }
    pthread_t thread;
    pthread_create(&thread, NULL, threadReturnFunction, NULL); // Create a thread that executes the threadReturnFunction
    pthread_join(thread, (void **)&returnValue); // Wait for the thread to finish
    printf("Thread has finished execution with return value %d.\n", *returnValue);
    free(returnValue); // Free the allocated memory
    return 0;
}


void *threadReturnFunction(void *arg)
{
    srand(time(NULL));
    int randomNum = rand() % 6 + 1; // Generate a random number between 0 and 7
    *returnValue = randomNum; // Set the return value
}