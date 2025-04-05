#include <stdio.h>
#include <string.h>
int main()
{
    char input[100];
    printf("Please enter a number:\n");
    scanf("%s", input);
    int len = strlen(input);
    printf("Chose a digit and then another digit you want to swap it with\n");
    char digitOne;
    printf("Chose a digit\n");
    scanf(" %c", &digitOne);
    printf("Chose the digit you want to swap it to\n");
    char digitTwo;
    scanf(" %c", &digitTwo);
    for(int i = 0; i < len; i++){
        if(input[i] == digitOne)
        {
            input[i] = digitTwo;
        }
    }
    printf("%s", input);
}
