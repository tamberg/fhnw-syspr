#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 32

//int atoi(char *a, int n) {
//    int i = 0;
//    while (n > 0) {
//        i = (i * 10) + (*a - '0');
//        a++;
//        n--;
//    }
//    return i;
//}

int main() {
    char buf[BUF_SIZE];
    int fd0 = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    int fd1 = open("./temp.txt", O_CREAT|O_WRONLY|O_TRUNC|O_APPEND, S_IRUSR|S_IWUSR);
    //FILE *f1 = fdopen(fd1);
    while (1) {
        lseek(fd0, 0, SEEK_SET);
        int r = read(fd0, buf, BUF_SIZE);

        //int t0 = atoi(buf, r - 1); // 37500
        //int t1 = t0 / 1000; //  37
        //int t2 = t0 / 100; // 375
        //int tm =  t2 % t1; // 5
        //fprintf(f1, "%d.%d,\r\n", t1, tm);

        int i = r - 3 - 1;
        write(fd1, buf, i);
        write(fd1, ".", 1);
        for (int j = i; j < 3; j++) {
            write(fd1, &buf[j], 1);
        }
        write(fd1, ",\r\n", 3); // CSV format ',' CRLF
        // note: $ cat -v temp.txt displays CRLF as ^M

        sleep(3); // seconds
    }
    // CTRL-C to exit process, closes fd0, fd1
    return 0;
}
