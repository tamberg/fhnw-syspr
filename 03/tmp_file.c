#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    char template[] = "/tmp/my-XXXXXX";
    int fd = mkstemp(template);
    if (fd == -1) {
        printf("mkstep: error no %d\n", errno);
        return -1;
    }
    printf("created filename %s\n", template);
    printf("press RETURN to unlink\n");
    int ch = getchar();
    unlink(template);
    printf("unlinked filename %s\n", template);
    close(fd);
    return 0;
}
