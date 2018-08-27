#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    printf("%d\n", EINTR);
    // $ sudo find / -name errno*.h => ~133
    for (int i = 0; i < 135; i++) {
        printf("%s\n", strerror(i));
    }
}
