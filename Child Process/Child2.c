#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int numChildProcesses = 4;
    printf("Parent Process ID: %d\n", getpid());
    for (int i = 0; i < numChildProcesses; i++) {
        pid_t childPid = fork();

        if (childPid < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (childPid == 0) {
            printf("Child Process ID: %d\n", getpid());
            if (i == 0) {
                sleep(2);
            }
            if (i == 3) {
                sleep(5);
            }
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < numChildProcesses; i++) {
        wait(NULL);
    }
    // Parent process termination
    printf("Parent process terminated.\n");
    return 0;
}
