#include <stdio.h>
#include <pthread.h>

void * increment(void * arg) {
    int *p = (int *) arg;
    for (int i = 0; i < 1000000; i++) {
        *p = *p + 1;
    }
    return NULL;
}

int main(void) {
    int n = 1;
    pthread_t tid;
    pthread_create(&tid, NULL, increment, &n);
    pthread_t tid2;
    pthread_create(&tid2, NULL, increment, &n);
    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);
    printf("Final value of n is %d\n", n);4
    return 0;
}