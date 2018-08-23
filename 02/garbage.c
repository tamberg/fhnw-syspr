#include <stdio.h>

void alice_work() {
    int secret = 1337;
    printf("%d\n", secret);
}

void eve_spy() {
    //printf("%d\n", secret); // not visible
    int garbage; // not initialised
    printf("%d\n", garbage);
}

int main() {
    alice_work();
    eve_spy();
}
