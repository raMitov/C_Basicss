#include <stdio.h>

int main()
{
    char* name[31];
    printf("What's your name?");
    scanf("%s", name);
    printf("I see your name is %s!", name);
    return 0;

}
