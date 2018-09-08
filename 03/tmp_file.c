#define _XOPEN_SOURCE 500
// http://man7.org/linux/man-pages/man7/feature_test_macros.7.html
// http://man7.org/linux/man-pages/man3/mkstemp.3.html
// https://stackoverflow.com/questions/5378778/what-does-d-xopen-source-do-mean#5724485

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void error(char *fun_name) {
    printf("%s: error no %d\n", fun_name, errno);
    exit(-1);
}

int main() {
    char template[] = "/tmp/my-XXXXXX";
    int fd = mkstemp(template);
    if (fd == -1) {
        error("mkstep");
    }
    printf("created filename %s\n", template);
    printf("press RETURN to unlink\n");
    getchar();
    int result = unlink(template);
    if (result == -1) {
        error("unlink");
    }
    printf("unlinked filename %s\n", template);
    result = close(fd);
    if (result == -1) {
        error("close");
    }
    return 0;
}
