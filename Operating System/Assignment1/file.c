#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // File descriptor for the file
    int fd;

    // Open a file (create it if it doesn't exist)
    fd = open("example.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Write data to the file
    char data[] = "Hello, World!";
    ssize_t bytes_written = write(fd, data, sizeof(data) - 1);

    if (bytes_written == -1) {
        perror("write");
        close(fd);
        exit(1);
    }

    // Close the file
    close(fd);

    // Reopen the file for reading
    fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read data from the file
    char buffer[256];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

    if (bytes_read == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    // Null-terminate the string
    buffer[bytes_read] = '\0';

    // Close the file again
    close(fd);
    // Print the read data
    printf("Read from file: %s\n", buffer);

    return 0;
}
