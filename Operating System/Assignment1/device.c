#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main() {
    int fd;
    char buffer[256];
    
    // Open a file for writing
    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Write data to the file
    char data[] = "Hello, World!\n";
    ssize_t bytes_written = write(fd, data, sizeof(data) - 1);
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    // Close the file
    close(fd);

    // Open a file for reading
    fd = open("output.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read data from the file
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    // Null-terminate the string
    buffer[bytes_read] = '\0';

    // Close the file
    close(fd);

    // Print the read data
    printf("Read from file: %s", buffer);

    // Use ioctl to set terminal to non-blocking mode
    struct termios term;
    if (ioctl(STDIN_FILENO, FIONBIO, &term) < 0) {
        perror("ioctl");
        exit(1);
    }

    printf("Terminal is now in non-blocking mode.\n");

    return 0;
}
