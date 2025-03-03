#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tell me how long of a string you are going to enter\n");
    int n;
    scanf("%d", &n);
    getchar();
    printf("You have to enter a %d long string\n", n);
    char *str = NULL;
    str = (char *)malloc(n * sizeof(char));
    fgets(str, sizeof(str), stdin);
    printf("%s", str);
    free(str);
    return 0;
}
