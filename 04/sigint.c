#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle(int signal) {
    printf("handling signal %d\n", signal); // unsafe
}

int main() {
    signal(SIGINT, handle);
    while (1) {
        sleep(3);
    }
}
