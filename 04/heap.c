#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n = 32;
    int size = n * sizeof(int);
    int *p = (int *) malloc(size);
    while (n > 0) {
        p++;
        n--;
    }

    void *b0 = sbrk(0);
    printf("current program break is at %p\n", b0);
    b0 = (char*) b0 + 1;
    printf("%p is after the program break\n", b0);
    brk(b0);
    void *b1 = sbrk(0);
    printf("new program break is at %p\n", b1);
}
