#include<stdio.h>
#include<stdbool.h>

int main()
{
    int primes[100];
    int arrLength = sizeof(primes) / sizeof(primes[0]);
    for(int i = 0; i < arrLength;i++)
    {
        primes[i] = 1;
    }
    for(int i = 2; i < arrLength; i++)
    {
        if(primes[i] == 1)
        {
            for(int j = i + i; j < arrLength; j += i)
            {
                primes[j] = 0;
                
            }

        }

    }
    for(int i = 0; i < arrLength;i++)
    {
        if(primes[i] == 1){

        printf("%d ", i);
        }

    }
}
