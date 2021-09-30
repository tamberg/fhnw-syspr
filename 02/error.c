#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// $ ls -al /var/log/syslog
// -rw-r----- 1 root adm ...
// $ ./error
// error: 13
// $ sudo ./error
// (OK)

int main(void) {
    int fd = open("/var/log/syslog", O_RDWR);
    if (fd == -1) {
        printf("error: %d", errno);
        return -1;
    }
    // read & write...
    close(fd);
    return 0;
}
