#include <stdio.h>

int StrLen(const char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
void Conc(const char str1[], const char str2[], char res[])
{
    int i = 0;
    int a = StrLen(str1);
    int b = StrLen(str2);
    int length = a + b;
    while(i != a)
    {
        res[i] = str1[i];
        i++;
    }
    int j = 0;
    while(j != length)
    {
        res[i + j] = str2[j];
        j++;
    }
    return;
}
int compareStrings(const char str1[], const char str2[])
{
    int a = StrLen(str1);
    int b = StrLen(str2);
    if(a > b || b > a){
        return 1;
    }
    else
    {
        return 0;
    }
    

}
int main()
{
    char str[6] = "Hello";
    int length = StrLen(str);
    printf("String length is %d\n", length);
    char str2[6] = "World";
    const int resSize = 10;
    char result[resSize];
    
    int comparison = compareStrings(str, str2);
    printf("The two strings are they equal? = %d\n", comparison);
    Conc(str, str2, result);
    printf("The string concatination resulted in: %s\n", result);
    int secondComparison = compareStrings(str, result);
    printf("The second two sstrings are they equal? = %d\n", secondComparison);
    
}
