#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
#define MAX_DIGITS 7
int main(){
    char input[8];

    printf("Enter an integer with up to %d digits: ", MAX_DIGITS);
    scanf("%s", input);
    int len = strlen(input);
    int count = 0;
    for(int i = 0; i < len; i++){
        if(input[i] != '0'){
            count++;
        }
    }
    char output[count];
    int j = 0;
    for(int i = 0; i < len; i++){
        if(input[i] != '0'){
            output[j++] = input[i];
        }
    }
    qsort(output, j, sizeof(char), compare);
    printf("%s", output);

}
