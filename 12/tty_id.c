#include <stdio.h>
#include <unistd.h>

int main(void) {
    int fd = STDIN_FILENO;
    int is_tty = isatty(fd);
    char *name = ttyname(fd);
    printf("%s is %sa tty\n", name, is_tty ? "": "not ");
    return 0;
}
