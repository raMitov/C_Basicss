#include <stdio.h>


int main()
{
    double height;
    double width;
    scanf("%lf %lf", &height, &width);
    double perimeter = height * 2 + width * 2;
    double area = height * width;
    printf("The perimeter of the rectangle is %.2lf and the area is %.2lf", perimeter, area);
}
