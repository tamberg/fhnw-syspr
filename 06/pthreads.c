#include <stdio.h>
#include <pthread.h>

void *run(void *arg) {
    printf("run\n");
    printf("arg = %d\n", *((int *) arg));
    pthread_exit(arg);
}

int main() {
    printf("main\n");
    pthread_t thread;
    int i = 42;
    pthread_create(&thread, NULL, run, &i);
    void *status;
    pthread_join(thread, &status);
    printf("status = %d\n", *((int *) status));
}
