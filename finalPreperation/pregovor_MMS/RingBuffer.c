#include <stdio.h>


typedef struct CircBuf{
    unsigned int writeIndex;
    unsigned int readIndex;
    int arr[10];
    int size;

}CircBuf;

int push(CircBuf *buf, int x){
        if (buf->size == 10) {  
            printf("Overwriting oldest value: %d\n", buf->arr[buf->readIndex]);
            buf->readIndex = (buf->readIndex + 1) % 10;  
        }
         else {
            buf->size++;  
        }
        buf->arr[buf->writeIndex] = x;  
        buf->writeIndex = (buf->writeIndex + 1) % 10;  
        return 0;
    
}
int pop(CircBuf *buf){
    if (buf->size <= 0) {
        printf("Buffer empty!\n");
        return -1;  
    }
    int x = buf->arr[buf->readIndex];
    buf->readIndex = (buf->readIndex + 1) % 10; 
    buf->size--;
    return x;
}
void printBuf(CircBuf *buf){
    for(int i = 0; i < buf->size; i++){
        printf("%d ", buf->arr[i]);
    }
}

int main(){
    CircBuf buf = {0, 0, {0}, 0};
    for(int i = 0; i <= 20; i++){
        printf("Read buffer\n");

        push(&buf, i);

        printf("Print buffer\n");
        printBuf(&buf);
        
    }

}