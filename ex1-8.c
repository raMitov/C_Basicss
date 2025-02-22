#include <stdio.h>
/* count lines in input */
//conts new lines, blanks and tabs
int main()
{
    int c, nl, tab, blank;
    nl = 0;
    tab = 0;
    blank = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            ++nl;
            printf("%d\n", nl);
        }
        else if (c == '\t'){
            ++tab;
            printf("%d\n", tab);
        }
        else if (c == ' '){
            ++blank;
            printf("%d\n", blank);
        }
    }
}

