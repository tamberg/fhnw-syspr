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
    off_t cur = lseek(fd, 0, SEEK_CUR);
    printf("%d\n", cur);
    off_t set = lseek(fd, 0, SEEK_SET);
    printf("%d\n", set);
    off_t end = lseek(fd, 0, SEEK_END);
    printf("%d\n", end);
    int len = end - set;
    cur = lseek(fd, 0, SEEK_CUR);
    printf("%d\n", cur); // min(BUF_SIZE, len)
    cur = lseek(fd, -len, SEEK_END);
    printf("%d\n", cur); // 0
    cur = lseek(fd, len, SEEK_SET);
    printf("%d\n", cur); // end
    r = read(fd, buf, BUF_SIZE);
    printf("%d\n", r); // 0, EOF
}
