#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 1024
#define N 10000

void error(char *fun_name) {
    printf("%s: error no %d\n", fun_name, errno);
    exit(-1);
}

int main() {
    char buf[BUF_SIZE];
    FILE *stream = stdout;
    errno = 0; // setvbuf may set errno
    int res = setvbuf(stream, buf, _IOFBF, BUF_SIZE);
    if (res != 0) { // returns nonzero on failure
        error("setvbuf");
    }
    for (int i = 0; i < N; i++) {
        res = fprintf(stream, "hello"); 
        if (res == -1) {
            error("fprintf");
        }
    }
    //res = fflush(stream);
    //if (res == EOF) {
    //    error("fflush");
    //}
    return 0;
}
