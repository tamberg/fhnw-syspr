#include "nest.h"

int temp;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int nest_up() {
    temp = min(temp + 1, MAX_TEMP);
    printf("%d\n", temp);
    return temp;
}

int nest_down () {
    temp = max(temp - 1, MIN_TEMP);
    printf("%d\n", temp);
    return temp;
}
