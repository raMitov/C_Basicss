#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main(){
    pthread_t threads[5];

    for(int i = 0; i < 5; i++){
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }
    for(int i = 0; i < 5; i++){
        pthread_join(threads[i], NULL);
    }

    printf("All joined");
    return 0;
}