#define _DEFAULT_SOURCE
#define MY_IMPL 1 // or 0

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#if MY_IMPL

struct block {
    int free;
    void *p;
    size_t n; // bytes
    struct block *next;
};

struct block *blocks;

void print_blocks(void) {
    printf("blocks [\n");
    struct block *b = blocks;
    while (b != NULL) {
        printf("\t{ %p, %zu, %s }%s\n", b->p, b->n, 
            b->free ? "free" : "used", 
            b->next == NULL ? "" : ",");
        b = b->next;
    }
    printf("]\n");
}

struct block *find_free_block(size_t n) {
    // implement a first fit strategy
    struct block *b = blocks;
    while (b != NULL && (!(b->free) || b->n < n)) {
        b = b->next;
    }
    assert(b == NULL || (b->free && b->n >= n));
    return b;
}

void mark_free_block(void *p) {
    struct block *b = blocks;
    while (b != NULL && b->p != p) {
        b = b->next;
    }
    assert(b != NULL);
    assert(!b->free);
    b->free = 1;
}

#endif

void *my_malloc(size_t n) {
#if MY_IMPL
    // implement malloc()
    struct block *b = find_free_block(n);
    if (b == NULL) {
        // create block
        b = malloc(sizeof(struct block)); // oops!
        b->n = n;
        b->p = sbrk(n); // incr heap size
        // insert block
        b->next = blocks;
        blocks = b;
    } else {
        b->free = 0;
        // TODO split block if too big
    }
    assert(b != NULL);
    void *p = b->p;
    printf("malloc(%zu) => %p\n", n, p);
    print_blocks();
    return p;
#else
    return malloc(n);
#endif
}

void my_free(void *p) {
#if MY_IMPL
    // implement free()
    printf("free(%p)\n", p);
    mark_free_block(p);
    // TODO fuse free blocks
    // TODO decr heap size using brk()
    print_blocks();
#else
    free(p);
#endif
}

void test(void) {
    // simple test calling my_malloc() and my_free()
    // same assertions hold for malloc(), free()
    printf("running tests...\n");

    size_t n = sizeof(int); // any other type should work as well
    size_t m = sizeof(long);

    void *p = my_malloc(n); // void * prevents type casts later on
    assert(p != NULL);

    void *q = my_malloc(m);
    assert(q != NULL);
    assert(q != p);
    assert(q - p >= n); // >= allows malloc() to do alignment

    void *r = my_malloc(n);
    assert(r != NULL);
    assert(r != p);
    assert(r != q);
    assert(r - q >= m);

    my_free(q);

    void *s = my_malloc(n);
    assert(s != NULL);
    assert(s != p);
    assert(s == q); // reuse

    my_free(p);
    my_free(r);
    my_free(s);

    printf("done.\n");
}

int main(void) {
    test();
    return 0;
}
