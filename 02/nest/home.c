#include "./nest.h"

#define FAV_TEMP 23

void home_leave() {
    while (nest_down() > MIN_TEMP) {}
}

void home_enter() {
    while (nest_up() < FAV_TEMP) {}
}

int main(int argc, char *argv[]) {
    int ch = (argc == 2) ? argv[1][0] : 'h'; //'h'elp
    switch (ch) {
        case 'l': home_leave(); break;
        case 'e': home_enter(); break;
        default: printf("usage: home leave|enter\n");
    }
}
