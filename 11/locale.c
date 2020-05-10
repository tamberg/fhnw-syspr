#include <locale.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *c = setlocale(LC_ALL, argv[1]);
    if (c == NULL) {
        printf("error");
        return -1;
    }
    printf("%'.2Lf\n", 10000.5);
}
