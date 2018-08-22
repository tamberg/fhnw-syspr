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

//int main(int argc, char *argv[]) {
//    int ch = (argc == 2) ? argv[1][0] : 'h'; //'h'elp
int main() {
    int ch = getchar();
    while (ch != 'q') {
        switch (ch) {
            case 'l': home_leave(); break;
            case 'e': home_enter(); break;
//            default: printf("usage: home leave|enter\n");
        }
        ch = getchar();
    }
}
