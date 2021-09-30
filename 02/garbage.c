#include <stdio.h>

void keep_secret() {
    int secret = 1337;
}

void show_secret() {
    //printf("%d\n", secret); // not visible
    int garbage; // not initialised
    printf("%d\n", garbage);
}

int main(void) {
    keep_secret();
    show_secret();
    return 0;
}
