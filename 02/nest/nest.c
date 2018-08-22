#include "nest.h"

int temp;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int up() {
    temp = min(temp + 1, MAX_TEMP);
    return temp;
}

int down () {
    temp = max(temp - 1, MIN_TEMP);
    return temp;
}
