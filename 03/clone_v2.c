//#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    (void) argc; // prevents 'unused parameter' warning
    char buf[BUF_SIZE];
    char *path = strcat(argv[0], ".c");
    int fd = open(path, O_RDONLY);
    int r = read(fd, buf, BUF_SIZE);
    while (r > 0) {
        //write(fileno(stdout), buf, r);
        write(STDOUT_FILENO, buf, r);
        r = read(fd, buf, BUF_SIZE);
    }
    close(fd);
    return 0;
}
