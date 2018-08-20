#include <stdio.h>

int power(int base, int n) {
    int result = 1;
    while (n > 0) {
        result *= base;
        n--;
    }
    // n == 0
    return result;
}

int main() {
    int b = 2;
    int n = 5;
    int p = power(b, n);
    printf("%d^%d = %d\n", b, n, p);
    return 0;
}
