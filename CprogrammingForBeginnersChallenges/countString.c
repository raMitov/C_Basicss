#include <stdio.h>


int Count(const char *ch)
{
    const char *count = ch;
    while(*count)
    {
        count++;
    }
    return count - ch;

}


int main()
{
    const char arr[] = "Hello World";
    int length = Count(arr);
    printf("%s is %d characters long", arr, length);
}
