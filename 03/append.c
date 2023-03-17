#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    int n = atoi(argv[2]);
    while (n > 0) {
        lseek(fd, 0, SEEK_END);
        write(fd, "0123456789", 10); // appends (?) 10 bytes
        n--;
    }
    return 0;
}
