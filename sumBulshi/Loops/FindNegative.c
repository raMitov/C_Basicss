#include <stdio.h>
#include <stdlib.h>

const int Scan_For_Negative(const int arr[], const int size){
    for(int i = 0; i < size; i++){
        if(arr[i] < 0){
            return i;
        }
    }
    return -1;
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
    int negativeIdx = Scan_For_Negative(arr, size);
    if(negativeIdx < 0){
        printf("There are no negative numbers in array");
        return 0;
    }
    printf("The index of the negative number is : %d", negativeIdx);
    

}