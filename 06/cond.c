#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

int n = 10; // max number of items
int i = 0; // shared resource

void *produce(void *arg) {
    while (1) {
        pthread_mutex_lock(&m);
        if (i == n) { // full
            printf("produce waiting for not_full\n");
            pthread_cond_wait(&not_full, &m);
        } else { // i < n
            i++;
            printf("produced one item, i = %d\n", i);
            pthread_cond_signal(&not_empty);
        }
        sleep(3); // s
        pthread_mutex_unlock(&m);
    }
}

void *consume(void *arg) {
    while (1) {
        pthread_mutex_lock(&m);
        if (i == 0) { // empty
            printf("consume waiting for not_empty\n");
            pthread_cond_wait(&not_empty, &m);
        } else { // i > 0
            i--;
            printf("consumed one item, i = %d\n", i);
            pthread_cond_signal(&not_full);
        }
        sleep(1); // s
        pthread_mutex_unlock(&m);
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
