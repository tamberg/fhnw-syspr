#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        execlp("curl", "-v", "tmb.gr"); // does not return
    }
    printf("waiting...\n");
    fflush(stdout);
    wait(NULL); // wait for child to exit
    printf("done.\n");
    return 0;
}
