#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
}Color;

typedef struct Picture {
    uint16_t height;
    uint16_t width;
    Color *data;
}Picture;

int main(void) {

    int n;
    printf("Enter a number of threads: ");
    scanf("%d", &n);
    pthread_t *prodId1 = malloc (sizeof(pthread_t) * n);
    for (int i = 0; i < n; i++) {
        pthread_create(&prodId1[i], NULL, &pthread_create, NULL);
    }
    unsigned int buffer[10];
    FILE *ptr;

    ptr = fopen("test.bin","rb");
    if (ptr == NULL) {
        perror("Error opening file");
        return -1;
    }
    int y;
    fread(buffer,sizeof(Picture)+sizeof(Color),1,ptr);
    //RGB TO GRAY??
        //conversion formula of rgb to gray
        //I know this makes no sense i have no time
        y=(buffer[1]*0.3) + (buffer[1]*0.59)  + (buffer[1]*0.11);
    for (int i = 0; i < n; i++) {
        pthread_join(prodId1[i], NULL);
    }
    free(prodId1);
    fclose(ptr);
}