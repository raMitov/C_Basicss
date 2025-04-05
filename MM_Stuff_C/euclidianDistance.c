#include <stdio.h>
#include <math.h>


struct Point{
    float x;
    float y;
};
float EuclidianDistance(struct Point A,struct Point B)
{
    float tempDist = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    return tempDist;
}

int main()
{
   struct Point A;
   struct Point B;
    float distance = 0;
    printf("Enter point one (x1, y1)\n");
    scanf("%f%f", &A.x, &A.y);
    printf("Enter point two (x2, y2)\n");
    scanf("%f%f", &B.x, &B.y);
    distance = EuclidianDistance(A, B);
    printf("The euclidian distance between these two points is %.2f \n", distance);
    return 0;
}
