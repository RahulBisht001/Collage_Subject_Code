#include <stdio.h>
#include <unistd.h>
int main()
{

    int x = fork();
    if (x > 0)
    {
        printf("\n");
        printf("Parent Process is Running\n");

        sleep(5);
        printf("Parent process is completed after 5 seconds\n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("Child process is running\n");

        printf("Child process completed\n");
        printf("\n");
    }
    return 0;
}