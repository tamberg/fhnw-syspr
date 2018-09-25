#include <stdio.h>

typedef struct { int x; int y; } Point;

Point create_point(int x, int y) {
    Point p = {x, y};
    return p;
}

Point create_point(int x, int y);

int main() {
    Point origin = create_point(0, 0);
    printf("(%d, %d)\n", origin.x, origin.y);
    return 0;
}
