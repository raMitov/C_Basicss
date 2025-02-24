#include <stdio.h>

int main()
{
    double arr[5][12];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            scanf("%lf", &arr[i][j]);
        }

    }
    double avgarr[5];
    double avg = 0;
    printf("These are the years and months.\n");
    printf("-------------------------------\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            printf("%.1lf ", arr[i][j]);
            avg += arr[i][j];
        }
        avgarr[i] = avg / 12;
        avg = 0;
        printf("\n");
    }
    printf("YEAR RAINFAL (inches)\n");
    printf("____________\n");
    int year = 2010;
    double yearly = 0;
    for(int i = 0; i < 5; i++)
    {
        printf("%d %.1lf\n", year, avgarr[i]);
        year++;
        yearly += avgarr[i];
    }
    double yearlyAVG = yearly/5;
    printf("\n\n");
    printf("The yearly average is %.1lf inches\n\n", yearlyAVG);
    printf("MONTHLY AVERAGES\n\n");
    
   printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
   double month = 0;
   double monthlyAVG[12];
   double calcMonthly = 0;
   for(int col = 0; col < 12; col++)
   {
       for(int row = 0; row < 5; row++)
       {
           month+= arr[row][col];
       }
        calcMonthly = month / 5;
        monthlyAVG[col] = calcMonthly;
        printf("%.1lf ", monthlyAVG[col]);
        month = 0;
   }


    return 0;

}
