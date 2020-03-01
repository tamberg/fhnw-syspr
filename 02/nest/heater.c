#include "heater.h"

static int temp = MIN_TEMP;

static int max(int a, int b) {
    return a > b ? a : b;
}

static int min(int a, int b) {
    return a < b ? a : b;
}

int heater_temp() {
    printf("%d\n", temp);
    return temp;
}

void heater_up() {
    temp = min(temp + 1, MAX_TEMP);
}

void heater_down() {
    temp = max(temp - 1, MIN_TEMP);
}
