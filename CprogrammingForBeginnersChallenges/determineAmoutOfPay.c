#include <stdio.h>
//challenge is to make a program that calculates weekly pay
int main()
{
    printf("How many hours did you work this week? ...");
    int hours;
    scanf("%d", &hours);
    printf("\n");
    double hourlyWage = 12.00;
    double overtimePay = hourlyWage * 1.5;
    int overtimeCalc = hours - 40;
    double payday = 0;
    if(hours > 40){
        payday += (overtimeCalc * overtimePay) + (40 * hourlyWage);
    }
    else
    {
        payday += (hours * hourlyWage);
    }
    printf("Your pay is %.2lf$\n", payday);
    double tax = 0;
    if(payday - 450 > 0){
        double leftover = payday - 450;
        tax = 300 * 0.15;
        payday -= tax;
        tax = 150 * 0.20;
        payday -= tax;
        tax = leftover * 0.25;
        payday -= tax;
    }
    else
    { 
        if(payday - 300 >= 0)
        {
            
            tax = 300 * 0.15;
            payday -= tax;
        }

    }
    printf("And your hard earned money after taxes is %.2lf\n", payday);
    return 0;


}
