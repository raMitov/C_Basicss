#include <stdio.h>
#include <string.h>
#include "stack.h"
int isBalanced(const char* input){
    Stack s = {NULL};
    for (int i = 0; input[i]; i++) {
        char c = input[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            char top = peak(&s);
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                pop(&s);
            } else {
                return 0; 
            }
        }
    }
    return isEmpty(&s);
}
int main(){
    char input[100];
    scanf("%s", input);
    if (isBalanced(input)) {
        printf("Balanced\n");
    } else {
        printf("Not balanced\n");
    }
    return 0;
}
