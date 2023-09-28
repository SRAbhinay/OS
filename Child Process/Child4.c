#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t child_pid = fork();
    if (child_pid == 0) {
        // Child process
        printf("Child process is running\n");
        printf("Child process ID: %d\n", getpid());
        sleep(5); // Sleep for 5 seconds to allow the parent process to terminate
        printf("Child process is exiting\n");
        exit(0);
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process is running\n");
        printf("Parent process ID: %d\n", getpid());
        printf("Parent process is exiting\n");
    } else {
        // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}