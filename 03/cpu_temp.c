#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define BUF_SIZE 32

int main() {
    //char buf[BUF_SIZE];
    int fd0 = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    int fd1 = open("./temp.txt", O_CREAT|O_WRONLY|O_TRUNC|O_APPEND, S_IRUSR|S_IWUSR);
    while (1) {
        char *buf;
        buf = malloc(BUF_SIZE);
        lseek(fd0, 0, SEEK_SET);
        int r = read(fd0, buf, BUF_SIZE);
        int i = r - 3 - 1;
        write(fd1, buf, i);
        write(fd1, ".", 1);
        while (i > 0) {
            buf++;
            i--;
        }
        write(fd1, buf, 3);
//        for (int j = i; j < i + 3; j++) {
//            write(fd1, &buf[j], 1);
//        }
        write(fd1, ",\r\n", 3); // CSV format ',' CRLF
        sleep(3); // seconds
    }
    // CTRL-C to exit process, closes fd0, fd1
    return 0;
}
