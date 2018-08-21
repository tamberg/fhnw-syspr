#include <stdio.h>

int inc(int i) {
    printf("inc\n");
    return i + 1;
}

void map(int a[], int len, int (*f)(int)) {
    printf("map\n");
    for (int i = 0; i < len; i++) {
        a[i] = f(a[i]); 
    }
}

//void map(int a[], int len, int (*f)(int));

int main() {
    int a[] = {1, 2, 3};
    map(a, 3, &inc);
    printf("%d, %d, %d\n", a[0], a[1], a[2]);
}
