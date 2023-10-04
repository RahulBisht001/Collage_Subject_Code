#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ftruncate(fd, 1024);
    char *ptr = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    strcpy(ptr, "Hello, Memory-Mapped File!");
    munmap(ptr, 1024);
    close(fd);
    return 0;
}
