#include <stdio.h>

int i = 0;

void f() {
    printf("%d\n", i);
}

//void g(int i); // forward declaration

int main() {
    printf("%d\n", i);
    int i = 1;
    printf("%d\n", i);
    { // block
        printf("%d\n", i);
        int i = 3;
        printf("%d\n", i);
    }
    printf("%d\n", i);
    f();
    g(i); // without the above forward declaration
    // g is implicitly defined as int g(int i);
}

void g(int i) {
    printf("%d\n", i);
}
