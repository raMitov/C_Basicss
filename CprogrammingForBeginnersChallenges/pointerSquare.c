#include <stdio.h>

void square(int *p)
{
    *p *= *p;
}

int main()
{
    int x = 2;
    square(&x);
    printf("x^2 = %d\n", x);

}
