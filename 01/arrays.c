#include <stdio.h>

int main() {
    //float values[3];
    float values[3] = { 20.1, 23, 15.2 };
    printf("%.1f\n", values[1]);
    values[1] = 7.0;
    printf("%.1f\n", values[2]);
    int n = sizeof(values) / sizeof(values[0]);
    printf("%d\n", n);
}

