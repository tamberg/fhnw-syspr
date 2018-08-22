#include "./nest.h"

#define FAV_TEMP 23

void home_leave() {
    while (nest_temp() > MIN_TEMP) {
        nest_down();
    }
}

void home_enter() {
    while (nest_temp() < FAV_TEMP) {
        nest_up();
    }
}

int main() {
    //extern int temp;
    //printf("%d\n", temp);
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
