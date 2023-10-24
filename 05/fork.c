#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t res = fork();
    if (res == 0) {
        printf("child %d of parent %d\n", getpid(), getppid());
    }
    // parent
    wait(NULL);
    printf("parent %d of child %d\n", getpid(), res);
    return 0;
}
