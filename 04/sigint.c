#include <stdio.h>
#include <signal.h>
//#include <unistd.h>

int flag = 0;

void handle(int signal) {
    printf("handling signal ", signal);
}

int main() {
    signal(SIGINT, handle);
    while (true) {
        sleep(3);
    }
}
