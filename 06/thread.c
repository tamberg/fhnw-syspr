#include <stdio.h>
#include <pthread.h>

void *start(void *arg) {
    printf("thread started...\n");
    return NULL;
}

int main() {
    printf("main\n");
    pthread_t thread;
    pthread_create(&thread, NULL, start, NULL);
    pthread_join(thread, NULL);
    printf("thread joined\n");
    return 0;
}
