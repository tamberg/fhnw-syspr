# include <stdio.h>

int main(void) {
    int a[] = {3, 1, 4};
    int *p;
    p = &a[0];
    p = p + 1;
    int b = *p;
    printf("%d\n", b);
    printf("%d\n", *a);
    return 0;
}
