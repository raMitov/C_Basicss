#include <stdio.h>
/* count lines in input */
int main()
{
int c, prev = 0;
while ((c = getchar()) != EOF){
    if (c == ' '){
        if(prev != ' '){
            putchar(c);
        }
    } else{
        putchar(c);
    }
    prev = c;
    }
return 0;
}

