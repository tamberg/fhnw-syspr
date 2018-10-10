#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main() {
    char** p = environ;
    while (*p != 0) {
        printf("%s\n", *p);
	p++;
    }

    char *user = getenv("USER"); // requires _GNU_SOURCE
    printf("USER=%s\n", user);
}
