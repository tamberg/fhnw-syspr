#include <stdio.h>
#include <pthread.h>

void *start(void *arg) {
    printf("start\n");
    printf("arg = %d\n", *((int *) arg));
    pthread_t id = pthread_self();
    printf("id = %lu\n", id);
    pthread_exit((void *) 0);
}

int main() {
    printf("main\n");
    pthread_t thread;
    int start_arg = 42;
    pthread_create(&thread, NULL, start, &start_arg);
    void *start_res;
    pthread_join(thread, &start_res);
    printf("thread = %lu\n", thread);
    printf("result = %d\n", (int) start_res);
}
