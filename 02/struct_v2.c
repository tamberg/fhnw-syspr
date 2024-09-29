#include <stdio.h>
#include <stdlib.h>

struct point { int x; int y; };

struct point *create_point(int x, int y) {
    struct point *p = malloc(sizeof(struct point));
    p->x = x;
    p->y = y;
    return p;
}

int main(void) {
    struct point *origin = create_point(0, 0);
    printf("(%d, %d)\n", origin->x, origin->y);
    free(origin);
    return 0;
}
