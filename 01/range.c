#include <stdio.h>
#include <limits.h>

const int CHAR_SIZE = sizeof(char);
const int SCHAR_SIZE = sizeof(signed char);
const int UCHAR_SIZE = sizeof(unsigned char);
const int SHRT_SIZE = sizeof(short);
const int USHRT_SIZE = sizeof(unsigned short);
const int INT_SIZE = sizeof(int);
const int UINT_SIZE = sizeof(unsigned int);
const int LONG_SIZE = sizeof(long);
const int ULONG_SIZE = sizeof(unsigned long);

int main () {
    printf("char: %d byte, %d .. %d\n", CHAR_SIZE, CHAR_MIN, CHAR_MAX);
    printf("signed char: %d byte, %d .. %d\n", SCHAR_SIZE, SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: %d byte, 0 .. %d\n\n", UCHAR_SIZE, UCHAR_MAX);
    // short
    printf("short: %d byte, %d .. %d\n", SHRT_SIZE, SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %d byte, 0 .. %d\n\n", USHRT_SIZE, USHRT_MAX);
    // int
    printf("int: %d byte, %d .. %d\n", INT_SIZE, INT_MIN, INT_MAX);
    printf("unsigned int: %d byte, 0 .. %u\n\n", UINT_SIZE, UINT_MAX);
    // long
    printf("long: %d byte, %ld .. %ld\n", LONG_SIZE, LONG_MIN, LONG_MAX);
    printf("unsigned long: %d byte, 0 .. %lu\n\n", ULONG_SIZE, ULONG_MAX);
    // long long (not defined on the Raspberry Pi Zero W)
    //printf("long long: %lld .. %lld\n", LONG_LONG_MIN, LONG_LONG_MAX);
    //printf("unsigned long long: 0 .. %llu\n", ULONG_LONG_MAX);
    return 0;
}
