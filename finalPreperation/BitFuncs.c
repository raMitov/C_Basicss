#include <stdio.h>
#include <string.h>

void set_Bit(unsigned int *x, const int pos);
void clear_Bit(unsigned int *x, const int pos);
void toggle_Bit(unsigned int *x, const int pos);
void decToBin(int num) {
    int started = 0;  
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (bit || started || i == 0) {  
            printf("%d", bit);
            started = 1;
        }
    }
}

int main(){
    unsigned int x;
    printf("Please enter a number -> ");
    scanf("%u", &x);
    printf("The number %d is -> ", x);
    decToBin(x);
    printf(" in binary, now chose which bit you want to change : \n");
    int pos;
    scanf("%d", &pos);
    printf("After turning on the %d'th bit the number became\n", pos);
    set_Bit(&x, pos);
    printf("%d, which is -> ", x);
    decToBin(x);
    printf(" in binary :D\n");
    printf("Now chose a bit to be cleared: ");
    scanf("%d", &pos);
    clear_Bit(&x, pos);
    printf("\nNow the number became %d, in binary -> ");
    decToBin(x);


}

void set_Bit(unsigned int *x, const int pos){
    if(pos >= 32 || pos < 0) return;
    *x |= (1U << pos);  
}
void clear_Bit(unsigned int *x, const int pos){
    if(pos >= 32 || pos < 0) return;
    *x &= ~(1U << pos);
}
void toggle_Bit(unsigned int *x, const int pos){
    if(pos > 32 || pos < 0) return;
    *x ^= (1U << pos);
}