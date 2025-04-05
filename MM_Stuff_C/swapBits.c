#include <stdio.h>

void DecimalToBinary(unsigned int N)
{
    unsigned int binaryNum[1000];
    int i = 0;
    while(N > 0)
    {
        binaryNum[i] = N % 2;
        N = N / 2;
        i++;

    }
    for(int j = i - 1; j >=0; j--)
        printf("%d", binaryNum[j]);

}
unsigned int swapBits(unsigned int N,unsigned int i,unsigned int j){
    unsigned int bit1 = (N >> i) & 1;
    unsigned int bit2 = (N >> j) & 1;
    unsigned int bitMask = (1 << i) | (1 << j);
    if(bit1 != bit2){
        N ^= bitMask;
    }
    return N;
}

int main()
{
    unsigned int N, i, j;
    printf("Enter a number\n");
    scanf("%d", &N);
    printf("The number %d is: ", N);
    DecimalToBinary(N);
    printf(" in binary\n Now enter which bits you want to swap...\n");
    scanf("%d%d", &i, &j);
    unsigned int newNum = swapBits(N, i, j);
    printf("The resulting number is: %d \n In binary it is: ", newNum);
    DecimalToBinary(newNum);
    
    return 0;
}

