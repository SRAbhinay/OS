#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int numChildProcesses;
    printf("Enter the number of child processes to generate: ");
    scanf("%d", &numChildProcesses);
    for(int i = 0; i < numChildProcesses; i++)
    {
        pid_t childPid = fork();
        if(childPid < 0)
        {
            perror("Fork Failed");
            exit(EXIT_FAILURE);
        }
        else if(childPid == 0)
        {
            printf("Child Process ID: %d", "Parent Process ID: %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
        printf("Parent process ID: %d\n", getpid());
        return 0;
    }
}

