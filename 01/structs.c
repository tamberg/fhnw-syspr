#include <stdio.h>

int main(void) {
    struct point { int x; int y; };
    struct point p = { 3, 2 };
    struct point q;
    q.x = p.y;
    q.y = 0;
    printf("(%d, %d)\n", p.x, p.y);
    printf("(%d, %d)\n", q.x, q.y);
    return 0;
}
