#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//system call fork() is used to create a new process so here it will print hello world two times
int main()
{
    fork();
    printf("Hello World!\n");
    return 0;
}