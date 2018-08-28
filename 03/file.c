#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main() {
    // TODO: error handling
    char buf[BUF_SIZE];
    int fd = open("./file.c", O_RDONLY);
    int r = read(fd, buf, BUF_SIZE);
    while (r > 0) {
        int w = write(STDOUT_FILENO, buf, r);
        r = read(fd, buf, BUF_SIZE);
    }
    int status = close(fd);
    return 0;
}
