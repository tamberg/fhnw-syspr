#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    printf("%d\n", EINTR);
    for (int i = 0; i < 135; i++) {
        printf("%s\n", strerror(i));
    }
}
