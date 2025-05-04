//Demonstrate pointer arithmetic by iterating through a string (char*) 
//and an array of integers (int*) to sum all elements. (Concept: pointer arithmetic on different types)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumOfString(const char *str){
    int sum = 0;
    while(*str!= '\0'){
        if(*str > '0' && *str < '9') sum += *str - '0';
        *str++;
    }
    return sum;
}
int sumOfArray(int *arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *arr;
        arr++;
    }
    return sum;
}

int main(){

    char string[100];
    int arr[10];

    scanf("%99s", &string);
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }

    return 0;
}