#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size) {
    return malloc(size); // TODO: replace
}

void my_free(void *p) {
    free(p); // TODO: replace
}

int main() {
    int n = 3;
    int *p = my_malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("%p: %d\n", p, *p);
        p++;
    }
    p -= n;
    my_free(p);
}
