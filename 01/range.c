#include <stdio.h>

int main() {
    int i = 0;
    int j = -1;
    while (i > j) {
        j = i;
        i++;
    }
    printf("%d, %d\n", i, j);
}
