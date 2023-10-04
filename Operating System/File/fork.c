#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    printf("Hello World\n");
    printf("Parent Process ID is: %d\n", getpid());
    return 0;
}
