#include <stdio.h>
#include <gnu/libc-version.h>

int main() {
    printf("%d, %d\n", __GLIBC__, __GLIBC_MINOR__);
    printf("%s\n", gnu_get_libc_version());
    return 0;
}
