// Two threads increment a global variable, 
// without protecting the critical section.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g = 0;
int n;

void *start(void *arg) {
    for (int i = 0; i < n; i++) {
        // critical section >>
        g++;
        // << critical section
    }
}

int main(int argc, char *argv[]) {
    n = atoi(argv[1]);
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, start, NULL);
    pthread_create(&t2, NULL, start, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("%d\n", g);
}
