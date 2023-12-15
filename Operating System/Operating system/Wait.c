#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }

    if (pid == 0)
    {
        printf("Hello from the child process!\n");
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("Child process has terminated.\n");
    }

    exit(0);
}
