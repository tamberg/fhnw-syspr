#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipe_fd[2];
    pipe(pipe_fd);
    pid_t pid = fork();
    if (pid == 0) { // child
        close(pipe_fd[0]);
        char buf[] = "hello";
        size_t size = sizeof(buf) / sizeof(buf[0]);
        int w = write(pipe_fd[1], buf, size);
        close(pipe_fd[1]); // sends EOF
        wait(NULL);
    } else { // parent
        close(pipe_fd[1]);
        char buf[1];
        while (read(pipe_fd[0], &buf, 1) == 1) {
            write(STDOUT_FILENO, buf, 1);
        }
    }
}
