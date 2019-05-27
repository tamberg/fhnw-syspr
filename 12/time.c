#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/times.h>

int main(int argc, char *argv[]) {
    struct tms t0_buf;
    clock_t t0 = times(&t0_buf);
    pid_t pid = fork();
    if (pid == 0) {
//        execlp("curl", "-v", "tmb.gr"); // does not return
        execvp(argv[1], argv + 1); // does not return
    }
    fflush(stdout);
    wait(NULL); // wait for child to exit
    struct tms t1_buf;
    clock_t t1 = times(&t1_buf);

    long ticks_per_s = sysconf(_SC_CLK_TCK);
    printf("\nreal \t%ld\nuser \t%lfs\nsys \t%lfs\n",
        (t1 - t0) / ticks_per_s,
        (t1_buf.tms_cutime - t0_buf.tms_cutime) / (double) ticks_per_s,
        (t1_buf.tms_cstime - t0_buf.tms_cstime) / (double) ticks_per_s);
    return 0;
}
