#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;

void handle(int signal) {
    flag = 1;
}

int main() {
    signal(SIGINT, handle);
    pause(); // wait for signals
    printf("flag = %s\n", flag ? "true" : "false");
}
