#include <stdio.h>

extern char etext, edata, end; // no include required

int i; // uninitialised data
char a[1024]; // uninitialised data
char b[] = {0x00, 0x01, 0x02}; // initialised data

void f(void) {
    char c[4096]; // stack frame for f()
    char d[] = {0x00}; // stack frame for f()
}

void g(void) {
    char e[256]; // stack frame for g()
    char *s = "hello"; // stack frame for g()
}

int main() {
    printf("&etext = %p\n", (void *) &etext);
    printf("&edata = %p\n", (void *) &edata);
    printf("&end = %p\n", (void *) &end);
    printf("&end - &edata = %ld\n", (long int) (&end - &edata));
    printf("&edata - &etext = %ld\n", (long int) (&edata - &etext));
    printf("CTRL-C to stop");
    while(1) {}
}
