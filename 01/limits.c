#include <stdio.h>
#include <limits.h>

int main () {
    printf("Bits per byte %d\n\n", CHAR_BIT);
    
    printf("char: %d .. %d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char: %d .. %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 .. %d\n\n", UCHAR_MAX);
    
    printf("short: %d .. %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 .. %d\n\n", USHRT_MAX);
    
    printf("int: %d .. %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 .. %u\n\n", UINT_MAX);
    
    printf("long: %ld .. %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 .. %lu\n\n", ULONG_MAX);
    
    //printf("long long: %lld .. %lld\n", LONG_LONG_MIN, LONG_LONG_MAX);
    //printf("unsigned long long: 0 .. %llu\n", ULONG_LONG_MAX);
    return 0;
}
