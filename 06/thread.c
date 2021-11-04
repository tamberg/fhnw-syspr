#include <stdio.h>
#include <pthread.h>

void *start(void *arg) {
    printf("New thread running ...\n");
    return NULL;
}

int main() {
    printf("main\n");
    pthread_t thread;
    pthread_create(&thread, NULL, start, NULL);
    pthread_join(thread, NULL);
    printf("Thread joined\n");
    return 0;
}
