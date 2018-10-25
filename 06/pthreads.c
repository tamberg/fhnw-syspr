#include <stdio.h>
#include <pthread.h>

void *run(void *arg) {
    printf("run\n");
    printf("arg = %d\n", *((int *) arg));
    pthread_t id = pthread_self();
    printf("id = %lu\n", id);
    pthread_exit((void *) 0);
}

int main() {
    printf("main\n");
    pthread_t thread;
    int run_arg = 42;
    pthread_create(&thread, NULL, run, &run_arg);
    void *run_res;
    pthread_join(thread, &run_res);
    printf("thread = %lu\n", thread);
    printf("result = %d\n", (int) run_res);
}
