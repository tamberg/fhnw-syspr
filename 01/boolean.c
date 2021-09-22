#include <stdio.h>
//#include <stdbool.h>

//typedef enum { false = 0, true = 1 } bool;

int main (void) {
    _Bool b;
    //bool b;
    //b = true;
    b = 1;
    b = 15;
    printf("%d\n", b);
    printf("%s\n", b ? "true" : "false");
}

