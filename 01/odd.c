#include <stdio.h>

int main() {
    int i;
    scanf("%d", &i);
    if (i % 2 == 0) {
        printf("%d ist gerade\n", i);
    } else {
        printf("%d ist ungerade\n", i);
    }
}

