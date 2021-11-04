#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define STOCK_MAX 32

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
volatile int stock = 0;

void *produce(void *arg) {
    while (1) {
        pthread_mutex_lock(&m); // blocking
        // critical section >>
        if (stock < STOCK_MAX) {
            stock++;
        }
        printf("producer, stock = %d\n", stock);
        // << critical section
        pthread_mutex_unlock(&m);
    }
}

void *consume(void *arg) {
    while (1) {
        pthread_mutex_lock(&m); // blocking
        // critical section >>
        if (stock > 0) {
            stock--;
        }
        printf("consumer, stock = %d\n", stock);
        // << critical section
        pthread_mutex_unlock(&m);
    }
}

int main(int argc, char *argv[]) {
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, produce, NULL);
    pthread_create(&t2, NULL, consume, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
