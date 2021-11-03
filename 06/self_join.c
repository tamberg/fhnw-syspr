#include <stdio.h>
#include <string.h>
#include <pthread.h>

int main() {
    pthread_t id = pthread_self();
    printf("thread = %ul\n", id);
    int err = pthread_join(id, NULL);
    if (err != 0) {
        char *msg = strerror(err);
        printf("err = %d, msg = %s\n", err, msg);
    }
}
