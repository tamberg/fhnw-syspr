#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _size;

void *my_malloc(size_t size) {
    _size = size;
    void *p = sbrk(size);
    return p;
}

void my_free(void *p) {
    sbrk(_size);
}

int main() {
    int n = 3;
    int *p = my_malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("%p: %d\n", (void *) p, *p);
        p++;
    }
    p -= n;
    my_free(p);
}
