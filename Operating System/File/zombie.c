#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\n Showing a Zombie Process\n");
    int x = fork();
    if (x > 0)
    {
        printf("\n");
        printf("Parent Process is Running\n");
        printf("Parent id: %d \n", getpid());
        sleep(10);
        printf("Parent process is completed after 10 seconds\n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("Child process is running\n");
        printf("Child process id: %d\n", getpid());
        printf("Parent id: %d\n", getppid());
        printf("Child process completed\n");
        printf("\n");
    }

    return 0;
}
