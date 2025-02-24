#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

}
int main()
{
    int var = 12;
    int *pVar = NULL;

    pVar = &var;
    printf("num address is: %p\n", &var);
    printf("The address of the pointer: %p\n", &pVar);
    printf("The value of the pointer %p\n", pVar);
    printf("The value of what the pointer is pointing to: %d\n", *pVar);
    
    int x = 122;
    int *px = NULL;
    //Exercise: Write a program to declare an integer variable x and a pointer ptr that points to x. Print the value of x using the pointer.
    px = &x;
    printf("value of x is: %d\n", *px);

    //Exercise: Write a program to demonstrate pointer arithmetic. Declare an array of integers and use a pointer to traverse and print the array.
    int arr[] = {1, 3, 4, 5, 6};
    int *parr = NULL;
    parr = arr;
    for(int i = 0; i < 5; i++)
    {
        printf("Element %d: %d\n", i, *(parr + i));

    }

    //Exercise: Write a function swap that takes two integer pointers and swaps the values they point to. Test the function in main.
    int a = 12;
    int b = 22;
    printf(" a = %d and b = %d\nBut with simple pointers..\n", a, b);
    swap(&a, &b);
    printf("a = %d and b = %d\n", a, b);
}
