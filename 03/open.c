#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("my.txt", O_RDWR);
    if (fd == -1) {
        perror("open"); // reads errno
        return -1;
    }
    printf("file opened, fd = %d\n", fd);
    close(fd);
    return 0;
}
