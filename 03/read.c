#include <assert.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open"); // reads errno
        return -1;
    }
    int n = 32;
    char buf[n]; // allocated on stack
    ssize_t r = read(fd, buf, n);
    while (r > 0) {
        write(STDOUT_FILENO, buf, r);
        r = read(fd, buf, n);
    }
    if (r == -1) {
        perror("read"); // reads errno
        return -1;
    } else {
        assert(r == 0); // EOF
    }
    close(fd);
    return 0;
}
