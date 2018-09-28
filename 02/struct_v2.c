#include <stdio.h>
#include <stdlib.h>

typedef struct { int x; int y; } Point;

Point *create_point(int x, int y) {
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

int main() {
    Point *origin = create_point(0, 0);
    printf("(%d, %d)\n", origin->x, origin->y);
    free(origin);
    return 0;
}
