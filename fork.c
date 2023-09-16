#include <stdio.h>
int main()
{
    int x; x = fork();
    if(x>0){
        printf("parent process of 1778\n My process of 1778 id : %d\n", getpid());
    }else if(x ==0){
        sleep(5);
        x = fork();
        if (x>0){
            printf("child process of 1778\nmy process of 1778 id: %d\n parent process of 1778 id: %d\n", getpid(), getppid());
            while(1)
            sleep(1);
            printf("child process of 1778\n parent process of 1778 id: %d\n", getppid());
        }
        else if (x==0){
             printf("in child's child process of 1778\n my parent id: %d\n" ,getppid());
        }
    }
    return 0;
}
