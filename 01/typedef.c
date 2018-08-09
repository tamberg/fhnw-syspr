#include <stdio.h>

int main() {
    typedef struct point { int x; int y; } Point;
    Point p = { 3, 2 };
    Point q;
    q.x = p.y;
    printf("p = (%d, %d)\n", p.x, p.y);
    printf("q = (%d, %d)\n", q.x, q.y);
    typedef struct rectangle { Point a; Point b; } Rectangle;
    typedef struct circle { Point origin; int r; } Circle;
    Rectangle r;
    r.a = p;
    r.b = q;
    Circle c;
    c.origin = r.a;
    c.r = 2;
    printf("a = (%d, %d), b = (%d, %d)\n", r.a.x, r.a.y, r.b.x, r.b.y);
    printf("origin = (%d, %d), r = %d\n", c.origin.x, c.origin.y, c.r);
    return 0;
}
