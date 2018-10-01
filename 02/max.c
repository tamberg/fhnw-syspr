#include <stdio.h>

#define max1(A, B) ((A) > (B) ? (A) : (B))

int max2(int a, int b) { return a > b ? a : b; }

int main() {
    int i1 = 1, j1 = 0;
    int m1 = max1(++i1, j1); // => m1 = ((++i1) > (j1) ? (++i1) : (j1)) => 2 x side effect!

    int i2 = 1, j2 = 0;
    int m2 = max2(++i2, j2); // => m2 = max(2, 0)
    printf("m1 = %d, m2 = %d\n", m1, m2);
}
