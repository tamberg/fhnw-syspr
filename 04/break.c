#define _DEFAULT_SOURCE

#include <stdio.h>
#include <unistd.h>

int main() {
    void *b0 = sbrk(0);
    printf("current program break is at %p\n", b0);
    b0 = (char*) b0 + 1;
    printf("%p is after the program break\n", b0);
    brk(b0);
    void *b1 = sbrk(0);
    printf("new program break is at %p\n", b1);
}
