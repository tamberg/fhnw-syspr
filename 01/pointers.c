#include <stdio.h>

int main() {
    int i = 23;
    int *p;
    p = &i;
    int j = *p;
    printf("%d, %p, %d, %d\n", i, (void *) p, *p, j);
    return 0;
}
