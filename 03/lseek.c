#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 128 //1024

int main() {
    // TODO: error handling
    char buf[BUF_SIZE];
    int fd = open("./lseek.c", O_RDONLY);
    ssize_t r = read(fd, buf, BUF_SIZE);
    off_t c = lseek(fd, 0, SEEK_CUR);
    printf("%d\n", c);
    off_t s = lseek(fd, 0, SEEK_SET);
    printf("%d\n", s);
    off_t e = lseek(fd, 0, SEEK_END);
    printf("%d\n", e);
    c = lseek(fd, 0, SEEK_CUR);
    printf("%d\n", c);
}
