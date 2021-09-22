#include <stdio.h>

int main (void) {
    //unsigned long v = 18446744073709551615UL;
    unsigned long v = 4294967295;
    //int v = -2147483648;
    //char v = 127;
    int n = sizeof(v);
    for (int i = n*8 - 1; i >= 0; i--) {
      int bit = (v >> i) & 0x1;
      printf("%d", bit);
    }
    printf("\n");
}
