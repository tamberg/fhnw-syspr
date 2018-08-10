#include <stdio.h>
#include <limits.h>

int main () {
    printf("Bits per byte %d\n", CHAR_BIT);

    printf("char: %d <= c <= %d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char: %d <= c <= %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: %d <= c <= %d\n", UCHAR_MIN, UCHAR_MAX);

    printf("short: %d <= s <= %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %d <= c <= %d\n", USHRT_MIN, USHRT_MAX);

    printf("int: %d <= s <= %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: %d <= c <= %d\n", UINT_MIN, UINT_MAX);

    printf("long: %d <= s <= %d\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: %d <= c <= %d\n", ULONG_MIN, ULONG_MAX);
    return 0;
}
