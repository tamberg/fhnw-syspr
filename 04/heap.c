#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 32;
    int size = n * sizeof(int);
    int *p = (int *) malloc(size);
    int *p0 = p;
    while (n > 0) {
        printf("%p, %d\n", (void *) p, *p); // garbage, if reused
        p++;
        n--;
    }
    free(p0);
}
