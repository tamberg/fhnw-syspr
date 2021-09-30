#include <stdio.h>

void f(void) {
    //int count; // not initialised, stack garbage
    //int count = 0; // initialised for every call
    static int count = 0; // initialised once only
    printf("%d\n", count);
    count++;
}

int main(void) {
    f(); f(); f();
    return 0;
}
