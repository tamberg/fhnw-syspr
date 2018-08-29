//#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    int fd = open("./file.c", O_RDONLY);
    int r = read(fd, buf, BUF_SIZE);
    while (r > 0) {
        //int w = write(fileno(stdout), buf, r);
        int w = write(STDOUT_FILENO, buf, r);
        r = read(fd, buf, BUF_SIZE);
    }
    int status = close(fd);
    return 0;
}
