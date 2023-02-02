#include <stdio.h>
#include <unistd.h>

int main() 
{
    pid_t pid, ppid;

    pid = fork();
    if (pid == 0) 
    {
        printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
    } else 
    {
        printf("Parent Process: PID = %d, PPID = %d\n", getpid(), getppid());
    }

    return 0;
}
