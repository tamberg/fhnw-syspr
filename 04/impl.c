#include <stdlib.h>
#include <malloc.h>

int main(void) {
    size_t n = sizeof(int);
    int *p = malloc(n);
    // rounds size_t n for alignment,
    // stores value to the left of p,
    // see also TLPI p. 144 ff.
    size_t s = *(((size_t *) p) - 1);
    size_t u = malloc_usable_size(p);
    // u and s depend on implementation,
    // still might provide some insight
    printf("%d ?= %d ?= %d\n", n, s, u);
    return 0;
}
