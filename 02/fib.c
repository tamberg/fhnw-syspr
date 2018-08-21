#include <stdio.h>

int f(int n) {
    if (n < 2) {
        return n;
    } else {
        return (f(n-1) + f(n-2));
    }
}

int main() {
    for (int i = 0; i < 32; i++)  {
        printf("%d\n", f(i));
    }
}
