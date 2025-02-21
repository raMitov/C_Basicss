#include <stdio.h>

int main()
{
    char name[31];
    printf("What's your name?\n" );
    scanf("%s", name);
    printf("Hello %s!\nYou look so sexy. \n", name);
    return 0;
}
