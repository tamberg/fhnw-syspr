#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

#define BSIZE 32

typedef struct {
    char buf[BSIZE];
    int occupied;
    int nextin;
    int nextout;
    pthread_mutex_t mutex;
    pthread_cond_t more;
    pthread_cond_t less;
} buffer_t;

buffer_t *buffer;

void producer(buffer_t *b, char item) {
    pthread_mutex_lock(&b->mutex);
   
    while (b->occupied >= BSIZE)
        pthread_cond_wait(&b->less, &b->mutex);

    assert(b->occupied < BSIZE);

    b->buf[b->nextin++] = item;
    printf("p:%c, ", item);
    b->nextin %= BSIZE;
    b->occupied++;

    /* now: either b->occupied < BSIZE and b->nextin is the index
       of the next empty slot in the buffer, or
       b->occupied == BSIZE and b->nextin is the index of the
       next (occupied) slot that will be emptied by a consumer
       (such as b->nextin == b->nextout) */

    pthread_cond_signal(&b->more);

    pthread_mutex_unlock(&b->mutex);
}


char consumer(buffer_t *b) {
    char item;
    pthread_mutex_lock(&b->mutex);
    while(b->occupied <= 0)
        pthread_cond_wait(&b->more, &b->mutex);

    assert(b->occupied > 0);

    item = b->buf[b->nextout++];
    printf("c:%c, ", item);
    b->nextout %= BSIZE;
    b->occupied--;

    /* now: either b->occupied > 0 and b->nextout is the index
       of the next occupied slot in the buffer, or
       b->occupied == 0 and b->nextout is the index of the next
       (empty) slot that will be filled by a producer (such as
       b->nextout == b->nextin) */

    pthread_cond_signal(&b->less);
    pthread_mutex_unlock(&b->mutex);

    return(item);
}

void *run_producer(void *arg) {
    int n = 10000;
    while(n > 0) {
        producer(buffer, 'a');
        n--;
    }
    producer(buffer, 'q');
}

void *run_consumer(void *arg) {
    char ch = consumer(buffer);
    while (ch != 'q') {
        ch = consumer(buffer);
    }
}

int main() {
    buffer = malloc(sizeof(buffer_t));
    pthread_t consumer_thread, producer_thread;
    int result = pthread_create(&consumer_thread, NULL, run_consumer, NULL);
    result = pthread_create(&producer_thread, NULL, run_producer, NULL);
    result = pthread_join(producer_thread, NULL);
    result = pthread_join(consumer_thread, NULL);
}
