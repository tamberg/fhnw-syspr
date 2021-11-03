#include <stdio.h>
#include <errno.h>

int *f() {
    return &errno;
}

int main() {
    //errno = EINTR;
    *f() = EINTR;
    printf("errno = %d\n", errno);
}
