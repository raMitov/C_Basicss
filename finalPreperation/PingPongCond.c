#include <stdio.h>

unsigned int CountSetBits(unsigned int x){
    unsigned int count = 0;
    for(int i = 0; i < 32; i++){
        if(x & 1) count++;
        x >> 1;
    }
    return count;
}

int main(){
    unsigned int x = 12;
    printf("%d", CountSetBits(x));
}