//Task: Use a C union of an int and a char[4] to pack an integer into bytes. 
//Write to the int member and then read the char array to examine the byte values. (Concept: union aliasing and shared memory)
#include <stdio.h>

union arri{
    int num;
     char nums[4];
};
void arriInitChars(union arri *arr){
    for(int i = 0; i < 4; i++){
        arr->nums[i] = 'A';
    }
    for(int i = 0; i < 4; i++){
        printf("%c ", arr->nums[i]);
    }
    printf("size -> %zu\n" ,sizeof(*arr));
}
void arriInitint(union arri *arr){
    arr->num = 1234;
    
    printf("%d ", arr->num);
    
    printf(" size -> %zu\n" ,sizeof(*arr));
}
int main(){
    union arri arr;
    arriInitChars(&arr);
    
    arriInitint(&arr);
}