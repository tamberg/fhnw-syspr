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

    while (b->occupied >= BSIZE) {
        pthread_cond_wait(&b->less, &b->mutex);
    }

    assert(b->occupied < BSIZE);

    b->buf[b->nextin++] = item;
    printf("%c++", item);
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
    while(b->occupied <= 0) {
        pthread_cond_wait(&b->more, &b->mutex);
    }

    assert(b->occupied > 0);

    item = b->buf[b->nextout++];
    printf("%c--", item);
    b->nextout %= BSIZE;
    b->occupied--;

    /* now: either b->occupied > 0 and b->nextout is the index
       of the next occupied slot in the buffer, or
       b->occupied == 0 and b->nextout is the index of the next
       (empty) slot that will be filled by a producer (such as
       b->nextout == b->nextin) */

    pthread_cond_signal(&b->less);
    pthread_mutex_unlock(&b->mutex);

    return item;
}

void *run_producer(void *arg) {
    int n = *((int *) arg);
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s number-of-iterations\n", argv[0]);
        exit(-1);
    }
    buffer = malloc(sizeof(buffer_t));
    int result = pthread_mutex_init(&(buffer->mutex), NULL);
    result = pthread_cond_init(&(buffer->less), NULL);
    result = pthread_cond_init(&(buffer->more), NULL);
    pthread_t consumer_thread, producer_thread;
    result = pthread_create(&consumer_thread, NULL, run_consumer, NULL);
    int n = atoi(argv[1]);
    result = pthread_create(&producer_thread, NULL, run_producer, &n);
    result = pthread_join(producer_thread, NULL);
    result = pthread_join(consumer_thread, NULL);
}
