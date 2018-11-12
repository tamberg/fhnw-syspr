#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 32

int main() {
    const char *filepath = "myfifo"; 
    mode_t mode = S_IRUSR | S_IWUSR;
    int result = mkfifo(filepath, mode);
    if (result == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    int flags = O_RDONLY;
    int fd = open(filepath, flags);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buffer[BUF_SIZE];
    ssize_t r = read(fd, buffer, BUF_SIZE);
    if (r == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    while (r != 0) {
        for (int i = 0; i < r; i++) {
            printf("%c", buffer[i]);
        }
        r = read(fd, buffer, BUF_SIZE);
        if (r == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
    }
    result = remove(filepath);
    if (result == -1) {
        perror("remove");
        exit(EXIT_FAILURE);
    }
    return 0;
}
