#include <stdio.h>
#include <unistd.h>

extern char etext, edata, end;

char a[4096]; // uninitialised data
char b[] = {0x00, 0x01, 0x02}; // initialised data

void f(void) { // stack frame for f()
    char c[4096]; // stack frame for f()
    char d[] = {0x00}; // stack frame for f()
}

int main() {
    printf("PID = %d\n", getpid());
    printf("&etext = %p\n", &etext);
    printf("&edata = %p\n", &edata);
    printf("&end = %p\n", &end);
    printf("&end - &edata = %d\n", &end - &edata);
    printf("&edata - &etext = %d\n", &edata - &etext);
    printf("CTRL-C to stop");
    while(1) {}
}
