#include <stdio.h>

int main(void) {
    int c = getchar();
    int result;
    if (('A' <= c) && (c <= 'Z')) { // for ASCII
        result = 'a' + c - 'A';
    } else {
        result = c;
    }
    printf("%c", result);
    return 0;
}
