#include <stdio.h>

struct point { int x; int y; };

struct point create_point(int x, int y) {
    struct point p = {x, y};
    return p;
}

int main(void) {
    struct point origin = create_point(0, 0);
    printf("(%d, %d)\n", origin.x, origin.y);
    return 0;
}
