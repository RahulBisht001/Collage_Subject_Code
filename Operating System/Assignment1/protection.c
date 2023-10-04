#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    mode_t new_mask = 027; // Define a new umask value (e.g., 027)
    mode_t old_mask = umask(new_mask); // Set the new umask and store the old one

    int fd = open("example.txt", O_CREAT | O_RDWR, 0644); // Create a new file

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Change the permissions of the file to read-only for the owner
    if (chmod("example.txt", S_IRUSR) == -1) {
        perror("chmod");
        close(fd);
        exit(1);
    }

    // Change the ownership of the file (user and group)
    if (chown("example.txt", 1000, 1000) == -1) { // Replace 1000 with the desired user and group IDs
        perror("chown");
        close(fd);
        exit(1);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
