#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// $ ls -al /var/log/syslog
// -rw-r----- 1 root ...

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    int fd = open("./file.c", O_RDWR);
    if (fd == -1) {
        printf("error: %d", errno);
        return -1;
    } else {
        // write & read ...
        close(fd);
    }
    return 0;
}
