//#define _XOPEN_SOURCE 500

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//int ftruncate(int fildes, off_t length);

int main() {
    int fd = open("my.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    int w, i = 0;
    char buf[] = {'x'};
    while (i < 32) {
        w = write(fd, buf, 3);
        if (w == -1) {
            return -1;
        }
        i++;
    }
    int result = ftruncate(fd, 7);
    if (result == -1) {
        return -1;
    }
}
