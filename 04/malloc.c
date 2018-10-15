#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// naive implementation
// allows a single my_malloc()
// followed by a single my_free()

int _size;

void *my_malloc(size_t size) {
    printf("my_malloc(%lu)\n", size);
    _size = size;
    void *p = sbrk(size);
    return p;
}

void my_free(void *p) {
    printf("my_free(%p)\n", p);
    void *q = sbrk(-_size);
    if (q == (void *) -1) {
        printf("my_free: error %d\n", errno);
        exit(-1);
    }
}

void test() {
    int n = 3;
    int *p = my_malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("%p: %d\n", (void *) p, *p);
        p++;
    }
    p -= n;
    my_free(p);
}

int main() {
    test();
    test();
}
