#include <stdio.h>

int main() {
    int result;
    int ch = getchar();
    switch (ch) {
        case 'y': result = 1; break;
        case 'n': result = 0; break;
        default: result = -1;
    }
    printf("%d, %d", ch, result);
    return 0;
}
