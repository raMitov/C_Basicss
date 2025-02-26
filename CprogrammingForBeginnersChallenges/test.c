#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

}
int main(void)

{

    int a = 6;
    int b = 12;
    printf("a = %d and b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d and b = %d\n",a , b);
    
    return 0;

   
}
