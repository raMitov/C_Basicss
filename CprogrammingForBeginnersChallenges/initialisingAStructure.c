#include "stdio.h"

struct employee{
    char name[20];
    int hireDate;
    float salary;

};
int main()
{
    struct employee josh ={"Joshy Williams", 1262014, 5200};
    struct employee Rado = {"Radoslav Mitov", 24052025, 7000};
    printf("The first employee is %s who is hired on %d and earns %.1f a month\n", josh.name, josh.hireDate, josh.salary);
    printf("The employee of the month is %s who is hired on %d and earns %.1f a month\n", Rado.name, Rado.hireDate, Rado.salary);
    return 0;
}
