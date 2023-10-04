#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    char buffer[256];
    
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process: Reading from the pipe
        close(pipe_fd[1]); // Close the write end
        read(pipe_fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipe_fd[0]);
    } else if (child_pid > 0) {
        // Parent process: Writing to the pipe
        close(pipe_fd[0]); // Close the read end
        const char* message = "Hello from parent!";
        write(pipe_fd[1], message, strlen(message) + 1);
        close(pipe_fd[1]);
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}
