#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", sizeof(size_t));
    printf("%d\n", sizeof(char));
    for (int n = 0; n < 32; n++) {
        size_t size = n * sizeof(char);
        void *p = malloc(size);
        size_t *ps = (size_t *) p;
        printf("n = %d, *ps = %d\n", n, *(--ps));
    }
}


