#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray createArray(int capacity){
    DynamicArray arr;
    arr.data = (int *)malloc(capacity * sizeof(int));
    arr.size = 0;
    arr.capacity = capacity;
    return arr;
}

void insert(DynamicArray *arr, int value){
    if(arr->size == arr->capacity){
        arr->capacity *= 2;

        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
        if(arr->data == NULL){
            printf("Memory allocation falied!\n);
            exit(1);
        }
    }
    arr -> data[arr->size++] = value;


}
void printArray(DynamicArray *arr){
    for(int i = 0; i < arr->size; i++){
        printf("%d",arr->data[i]);
    }
    printf("\n");
}
void freeArray(DynamicArray *arr){
    free(arr->data);
}
int main()
{
    DynamicArray arr = createArray(2);
    insert(&arr, 1);
    insert(&arr, 2);
    insert(&arr, 3);

    printf("Dynamic Array: ");
    printArray(&arr);

    freeArray(&arr);
    return 0;
}
