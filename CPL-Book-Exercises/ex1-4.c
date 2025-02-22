#include <stdio.h>

int main(){
    float fahr, celsius;
    float lower, upper, step;

    lower = 0.0;
    upper = 100.0;
    step = 10;
    celsius = lower;

    printf("Celsius Farenheit\n");
    printf("_________________\n");

    while(celsius <= upper){
        fahr = (9.0 * celsius / 5.0) + 32;
        printf("%7.0f %7.0f\n", celsius, fahr);
        celsius += step;
    }
    return 0;

}
