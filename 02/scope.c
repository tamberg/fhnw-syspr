#include <stdio.h>

int i = 0;

void f(void) {
    printf("%d\n", i);
    i++;
}

void g(int i); // forward declaration

int main(void) {
    printf("%d\n", i);
    int i = 23;
    printf("%d\n", i);
    { // block
        printf("%d\n", i);
        int i = 42;
        printf("%d\n", i);
    }
    printf("%d\n", i);
    f();
    printf("%d\n", i);
    g(i); // without the above forward declaration
    // g is implicitly defined as int g(int i);
    printf("%d\n", i);
    return 0;
}

void g(int i) {
    printf("%d\n", i);
    i++;
}
