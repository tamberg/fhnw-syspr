#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *start(void *arg) {
    int i = *((int *) arg);
    printf("thread started, arg = %d\n", i);
    int *result = malloc(sizeof(int));
    *result = i * 2;
    return result;
}

int main() {
    printf("main\n");
    pthread_t thread;
    int i = 3;
    void *arg = &i;
    pthread_create(&thread, NULL, start, arg);
    void *retval;
    pthread_join(thread, &retval);
    int val = *((int *) retval);
    printf("thread joined, retval = %d\n", val);
    return 0;
}
