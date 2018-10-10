#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
    char** p = environ;
    while (*p != 0) {
        printf("%s\n", *p);
	p++;
    }
}
