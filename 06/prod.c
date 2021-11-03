#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int n = 10; // max number of items
int i = 0; // shared resource

void *produce(void *arg) {
    while (1) {
        pthread_mutex_lock(&m);
        if (i < n) { // not full
            i++; // produce
            printf("produced one item, i = %d\n", i);
        } else {
            printf("produced nothing.\n");
        }
        pthread_mutex_unlock(&m);
        sleep(5); // s
    }
}

void *consume(void *arg) {
    while (1) {
        pthread_mutex_lock(&m);
        if (i > 0) { // not empty
            i--; // consume
            printf("consumed one item, i = %d\n", i);
        } else {
            printf("consumed nothing.\n");
        }
        pthread_mutex_unlock(&m);
        sleep(1); // s
    }
}

int main() {
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, produce, NULL);
    pthread_create(&t2, NULL, consume, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
