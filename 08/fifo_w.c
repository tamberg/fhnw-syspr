#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    const char *filepath = "myfifo"; 
    int flags = O_WRONLY;
    int fd = open(filepath, flags);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buffer[] = "hello\n";
    size_t size = sizeof(buffer) / sizeof(buffer[0]);
    ssize_t w = write(fd, buffer, size);
    if (w == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    printf("wrote %d bytes\n", w);
    int result = close(fd);
    if (result == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    return 0;
}
