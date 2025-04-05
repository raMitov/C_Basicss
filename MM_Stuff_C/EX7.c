#include <stdio.h>
#include <limits.h>

int main(){
    int num;
    int min1 = INT_MAX, min2 = INT_MAX;
    int evenSum = 0, evenCount = 0;
    printf("Enter numbers and a non number to stop\n");
    while(scanf("%d", &num) == 1)
    {
        if(num < min1){
            min2 = min1;
            min1 = num;
        }
        else if(num < min2){
            min2 = num;
        }
        if(num % 2 == 0){
            evenSum += num;
            evenCount++;
        }
    }
    printf("The smallest numbers are %d and %d\n", min1, min2);

    double avg = (double)evenSum / evenCount;
    printf("The avarage of the even numbers is %.2f\n", avg);

}
