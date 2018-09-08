#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define BUF_SIZE 32

int main() {
    char buf[BUF_SIZE];
    int fd0 = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    int fd1 = open("./temp.txt", O_CREAT|O_WRONLY|O_TRUNC|O_APPEND, S_IRUSR|S_IWUSR);
    while (1) {
        lseek(fd0, 0, SEEK_SET); // set CUR to beginning of file fd0
        int r = read(fd0, buf, BUF_SIZE); // read, e.g. 37500\n => r = 6
        int i = r - 3 - 1; // length of integer part of 37.500 => i = 2
        char *p = buf; // pointer to &buf[0]
        write(fd1, p, i); // write i chars starting at p => 37
        p += i; // move p to compensate for written chars
        write(fd1, ".", 1); // write (missing) point
        write(fd1, p, 3); // write 3 chars =>  500
        write(fd1, ",\r\n", 3); // CSV => ,CRLF
        sleep(3); // seconds
    }
    // CTRL-C to exit process, closes fd0, fd1
    return 0;
}
