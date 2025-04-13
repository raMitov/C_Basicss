#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* square(void *arg) {
    int num = *(int *)arg;
    int *result = malloc(sizeof(int));
    if (result == NULL) {
        perror("malloc");
        return NULL;
    }
    *result = num * num;
    pthread_exit(result);

}

int main(void) {
    pthread_t thread;
    int num = 3;
    int *result;
    pthread_create(&thread, NULL, square, &num);

    pthread_join(thread, (void**)&result);
    printf("%d\n", *result);
    free(result);
    return 0;
}