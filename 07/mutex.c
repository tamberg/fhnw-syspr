#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int g = 0;
int n;

void *start(void *arg) {
    //pthread_mutex_lock(&m);
    for (int i = 0; i < n; i++) {
        pthread_mutex_lock(&m);
        g++;
        pthread_mutex_unlock(&m);
    }
    //pthread_mutex_unlock(&m);
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
