#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\n Showing Orphan Child Process\n");
    int x = fork();

    if (x == 0)
    {
        printf("\n");
        printf("Child Process is Running\n");
        printf("Child Process id: %d\n", getpid());
        printf("Parent Process id: %d\n", getppid());
        sleep(10);

        printf("Child Process is completed after 10 seconds\n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("Parent Process is Running\n");
        printf("Parent id: %d \n", getpid());
        printf("Parent Process is completed\n");

        printf("\n");
    }

    return 0;
}
