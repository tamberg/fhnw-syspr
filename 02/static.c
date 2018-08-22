#include <stdio.h>

void f() {
    //int count; // not initialised, stack garbage
    //int count = 0; // initialised for every call
    static int count = 0; // initialised once only
    printf("%d\n", count);
    count++;
}

int main() {
    f(); f(); f();
}
