#include <stdio.h>

int power(int b, int n) {
    int p = 1;
    while (n > 0) {
        p = p * b;
        n--;
    }
    // n == 0
    return p;
}

int main() {
    int a = 2;
    int m = 5;
    int q = power(a, m);
    printf("%d^%d = %d\n", a, m, q);
    return 0;
}
