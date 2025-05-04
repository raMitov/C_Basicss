#include <stdio.h>
#include <stdlib.h>

int return_sum(int arr[], int size){
    int sum = 0;
    for(int i = 0; i< size; i++){
        if(arr[i] == 0) break;
        sum+= arr[i];
    }
    return sum;
}

int main(){
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    printf("\n Now give the array values \n");
    int n;
    for(int i = 0; i < size; i++){
        scanf("%d", &n);
        arr[i] = n;
    }
    printf("The sum of the elements is: %d", return_sum(arr, size));
    
    

}