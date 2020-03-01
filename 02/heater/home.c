#include "./heater.h"

#define FAV_TEMP 23

void home_leave() {
    while (heater_temp() > MIN_TEMP) {
        heater_down();
    }
}

void home_enter() {
    while (heater_temp() < FAV_TEMP) {
        heater_up();
    }
}

int main() {
    int ch = getchar();
    while (ch != 'q') {
        switch (ch) {
            case 'l': home_leave(); break;
            case 'e': home_enter(); break;
            case '\n': break; // ignore
            default: printf("usage: type 'l'eave | 'e'nter | 'q'uit \n");
        }
        ch = getchar();
    }
}
