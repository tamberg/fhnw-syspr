#include <stdio.h>

void keep_secret() {
    int secret = 1337;
    printf("%d\n", secret);
}

void show_secret() {
    //printf("%d\n", secret); // not visible
    int garbage; // not initialised
    printf("%d\n", garbage);
}

int main() {
    keep_secret();
    show_secret();
}
