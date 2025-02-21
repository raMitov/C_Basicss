#include <stdio.h>
#include <string.h>

int main(void)
{
    char answer[100];
    printf("What's your name? ");
    fgets(answer, sizeof(answer), stdin);

    answer[strcspn(answer, "\n")] = '\0';
    printf("hello, %s\n", answer);
    return 0;
}