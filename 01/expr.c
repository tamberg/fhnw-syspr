#include <stdio.h>

int main(void) {
    int a, b;
    a = 1 + 2 * 3; // Punkt vor Strich
    b = 6 * a; // b = 6 * (1 + 2 * 3)
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    float c;
    c = b * 0.25;
    a = c; // a = 10.5
    printf("c = %f\n", c);
    printf("a = %d\n", a);
    return 0;
}

