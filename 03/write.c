#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("my.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if (fd == -1) {
        perror("open"); // reads errno
        return -1;
    }
    char *buf = "hello, world!";
    size_t n = strlen(buf);
    ssize_t w = write(fd, buf, n);
    if (w == -1) {
        perror("write"); // reads errno
        return -1;
    }
    close(fd);
    return 0;
}

