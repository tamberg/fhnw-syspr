#include <stdio.h>

#define max1(A, B) ((A) > (B) ? (A) : (B))

int max2(int a, int b) { return a > b ? a : b; }

int main() {
    int i = 1, j = 0;
    int m1 = max1(i++, j); // => m1 = ((i++) > (j) ? (i++) : (j)) => 2 x side effect!
    int m2 = max2(i++, j); // => m2 = max(2, 0)
    printf("m1 = %d, m2 = %d\n", m1, m2);
}
