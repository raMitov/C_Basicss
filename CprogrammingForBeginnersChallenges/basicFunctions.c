#include <stdio.h>
#include <math.h>

int GCD(int a, int b);
float ABS(float a);
float SQRT(float d);
int findBigger(int a, int b);
int findSmaller(int a, int b);


int main()
{
    int a = 48;
    int b = 18;
    int result = GCD(a, b);
    printf("The greatest common divisor is: %d\n", result);
    int ab = -12;
    float bs = -12.6;
    printf("The absolute value of %d is %.1f\n", ab, ABS(ab));
    printf("The absolute value of %.1f is %.1f\n", bs, ABS(bs));
    printf("The square root of %d is %.1f\n", ab, SQRT(ab));
}
int findBigger(int a, int b)
{
    return (a > b) ? a : b;

}
int findSmaller(int a, int b)
{
    return (a < b) ? a : b;
}

int GCD(int x, int c)
{
    int helper = 0;
    int greatest = 0;
    int a = findBigger(x, c);
    int b = findSmaller(x, c);
    if(b == 0)
    {
        return a;
    }
    while(b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

float ABS(float a)
{
  if(a < 0)
  {
    return -a;
  }
  else
  {
    return a;
  }
}

float SQRT(float x)
{
    x = ABS(x);
    if(x < 2)
    {
        return x;
    }
    float y = x;
    float z = (y +(x / 2)) / 2;
    while(fabs(y-z) >= 0.00001)
    {
        y = z;
        z = (y + (x / y)) /2;
    }
    return z;
}
