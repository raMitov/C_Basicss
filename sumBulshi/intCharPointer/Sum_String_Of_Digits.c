#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SumOfDigits(const char *str){
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {  
            sum += str[i] - '0';  
        }
    }
    return sum;
}

int main(){
    char input[100];
    printf("Input type up to 99 digits in console and see their sum\n");
    scanf("%99s", input);
    printf("The sum of the digits is -> %d", SumOfDigits(input));

}