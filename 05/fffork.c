#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    (void) argc; // unused
    printf("%s\n", argv[0]);
    printf("%d, %d\n", fork(), getpid());
    printf("%d, %d\n", fork(), getpid());
    printf("%d, %d\n", fork(), getpid());
}
