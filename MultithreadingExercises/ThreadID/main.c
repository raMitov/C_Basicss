#include <stdio.h>
#include <pthread.h>

void * threadid(void * args) {
    pthread_t self = pthread_self();
    printf("Thread ID: %ld\n", (unsigned long) self);
    pthread_exit(NULL);
    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, threadid, NULL);
    pthread_t main  = pthread_self();
    printf("Main Thread ID %ld\n", (unsigned long) main);

    if (pthread_equal(thread, main)) {
        printf("Threads match\n");
    }
    else {
        printf("Threads differ\n");
    }
    pthread_join(thread, NULL);

    return 0;
}