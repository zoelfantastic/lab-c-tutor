#include "process_task.h"

int main(void)
{
    int id_branch = fork();
    if (id_branch == 0) {
        // This is the child process
        printf("Hello from the child process!\n");
    } else if (id_branch > 0) {
        // This is the parent process
        printf("Hello from the parent process!\n");
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    return 0;
}