#include <stdio.h>
#include <stdlib.h>

#define N 8

int main() {
    int size = N * sizeof(int);
    int *p = (int *) malloc(size);
    int *p0 = p;
    for (int i = 0; i < N; i++) {
        printf("%p, %d\n", (void *) p, *p); // garbage, if reused
        p++;
    }
    free(p0);
}
