#include <stdio.h>

int count; // global

void f() { count++; }

int main() {
    f(); f(); f();
    printf("f was called %d times\n", count);
}
