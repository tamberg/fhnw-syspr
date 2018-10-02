//#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    int fd = open("./clone.c", O_RDONLY);
    int r = read(fd, buf, BUF_SIZE);
    while (r > 0) {
        //write(fileno(stdout), buf, r);
        write(STDOUT_FILENO, buf, r);
        r = read(fd, buf, BUF_SIZE);
    }
    close(fd);
    return 0;
}
