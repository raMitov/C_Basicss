#include <stdio.h>

unsigned int CountSetBits(unsigned int x){
    unsigned int count = 0;
    while(x){
        if(x & 1) count++;
        x = x >> 1;
    }
    return count;
}
unsigned int BrianK(unsigned int x){
    unsigned int count = 0;
    while(x){
        x &= (x-1);
        count++;
    }

    return count;
}

unsigned int BuiltIn(unsigned int x){
    return __builtin_popcout(x);
}

int main(){
    printf("Give me a number and im gonna show you how many bits it has\n");
    unsigned int x;
    scanf("%d", &x);

    printf("The number %d has %d set bits, now lets double check -> %d bits again!\n", x,CountSetBits(x), BrianK(x));
}