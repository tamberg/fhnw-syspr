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
    int b = 2;
    int n = 5;
    int p = power(b, n);
    printf("%d^%d = %d\n", b, n, p);
    return 0;
}
