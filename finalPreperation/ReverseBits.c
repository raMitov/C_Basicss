#include <stdio.h>
#include <stdint.h>
uint32_t reverse(uint32_t x){
    for(int i = 0; i < 32; i++){
        uint32_t resoult = 0;
        if((x >> i) & 1){
            resoult |= 1U << (31 - i);
        }
    }
}

int main(){
    
}