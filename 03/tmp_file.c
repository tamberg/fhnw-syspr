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
    int ch = getchar();
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
