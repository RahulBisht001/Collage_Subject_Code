#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int child_status;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process: My PID is %d\n", getpid());
        exit(0);
    } else {
       printf("child process terminated");
        // Wait for the child process to exit and get its status
        wait(NULL);
    }

    return 0;
}
