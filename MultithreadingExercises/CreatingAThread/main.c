#include <stdio.h>
#include <pthread.h>

void* thread_func(void * arg) {
    printf("thread_func start\n");
}
int main(void) {
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_func, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }
    printf("Hello Thread\n");
    pthread_join(thread, NULL);
    printf("Hello, World!\n");
    return 0;
}