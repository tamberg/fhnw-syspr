#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// $ ls -al /var/log/syslog
// -rw-r----- 1 root adm ...
// $ ./error
// $ sudo ./error

int main() {
    int fd = open("/var/log/syslog", O_RDWR);
    if (fd == -1) {
        printf("error: %d", errno);
        return -1;
    }
    // write & read ...
    close(fd);
    return 0;
}
