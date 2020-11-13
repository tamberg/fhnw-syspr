#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    printf("main\n");
    pid_t result = fork();
    if (result == 0) { // child
        printf("%d: after fork, in child\n", getpid());
        execve("./hello", NULL, NULL);
        printf("%d: after exec, in child\n"); // does not run
    } else {
        printf("%d: after fork, in parent\n", getpid());
        wait(NULL);
        printf("%d: after wait, in parent\n", getpid());
    }
}
