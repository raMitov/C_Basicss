#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(unsigned int n){
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(){

}