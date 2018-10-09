#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("PID = %d, parent PID = %d\n", pid, ppid);
}
