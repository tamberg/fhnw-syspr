#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    char *f = "./dup.txt";
    int fd1 = open(f, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    int fd2 = dup(fd1);
    int fd3 = open(f, O_RDWR);
    write(fd1, "Ente,", 5); // Ente,
    write(fd2, "Hund,", 5); // Ente,Hund, CUR=10
    lseek(fd2, 0, SEEK_SET); // Ente,Hund, CUR=0
    write(fd1, "Haus,", 5); // Haus,Hund,
    write(fd3, "Pferd", 5); // PferdHund,
    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}
