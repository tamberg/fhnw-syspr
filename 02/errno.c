#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    printf("%d\n", EINTR);

    errno = 27;
    perror("open"); // reads errno

    // $ sudo find / -name errno*.h => ~133
    for (int i = 0; i < 135; i++) {
        printf("%d: %s\n", i, strerror(i));
    }
}
