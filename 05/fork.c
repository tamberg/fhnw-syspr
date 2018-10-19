#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    (void) argc; // unused
    printf("%s\n", argv[0]);
    pid_t pid = fork();
    if (pid == 0) {
        pid = getpid();
        pid_t pid_p = getppid();
        printf("I'm child %d of parent %d\n", pid, pid_p);
    } else {
        pid_t pid_c = pid;
        pid = getpid();
        printf("I'm parent %d of child %d\n", pid, pid_c);
        //int status;
        //wait(&status);
        //printf("Done waiting for child, status %d\n", status);
    }
    exit(0);
}
