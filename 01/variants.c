#include <stdio.h>

int main() {
    typedef union variant {
        int int_value;
        float float_value;
    } Variant;
    //Variant v = { 7 }; // sets first field, int_value
    //Variant v = { 23.0 }; // does not set float_value
    //Variant v = { .float_value = 23.0 }; // c99 only
    Variant v; 
    v.int_value = 7;
    printf("%d\n", v.int_value);
    v.float_value = 23.0;
    printf("%f\n", v.float_value);
}
