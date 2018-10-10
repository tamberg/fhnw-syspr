#define _BSD_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int main() {
    char** p = environ;
    while (*p != 0) {
        printf("%s\n", *p);
	p++;
    }

    const int N = 18;
    char *my_var = (char *) malloc(N * sizeof(char));
    strcpy(my_var, "MY_HEAP_VAR=hello");
    putenv(my_var);

    int overwrite = 0; // don't overwrite the value if the name exists
    setenv("MY_CONST_VAR", "hola", overwrite); // requires _BSD_SOURCE

    char *h = getenv("MY_HEAP_VAR");
    printf("MY_HEAP_VAR=%s\n", h);
    char *c = getenv("MY_CONST_VAR");
    printf("MY_CONST_VAR=%s\n", c);
}
