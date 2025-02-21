#include <stdio.h>
#include <math.h>
int main()
{
    double a, b;
    printf("Give me A-side of triangel");
    scanf("%lf", &a); 
    printf("Give me B-side of triangel");
    scanf("%lf", &b);
    double c = sqrt((a*a) + (b*b));
   // double answer = cbrt(c);
    printf("The answer is %f\n", c);

    return 0;
}
