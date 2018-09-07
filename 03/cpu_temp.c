#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 32

int main() {
    char buf[BUF_SIZE];
    int fd0 = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    int fd1 = open("./temp.txt", O_CREAT|O_WRONLY|O_TRUNC|O_APPEND, S_IRUSR|S_IWUSR);
    while (1) {
        lseek(fd0, 0, SEEK_SET);
        int r = read(fd0, buf, BUF_SIZE);
        // TODO: int i = atoi(buf); buf = ftoa(i / 1000.0);
        write(fd1, buf, r - 1); // remove trailing LF
        write(fd1, ",\r\n", 3); // CSV format ',' CRLF
        // note: $ cat -v temp.txt displays CRLF as ^M
        sleep(3); // seconds
    }
    // CTRL-C to exit process, closes fd0, fd1
    return 0;
}
