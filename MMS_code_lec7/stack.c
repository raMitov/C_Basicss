#include "stack.h"
#include <stdlib.h>

void push(Stack* s, char x){
    Node * n = malloc(sizeof(Node));
    if(!n) return;
    n -> data = x;
    n -> next = s -> top;
    s->top = n;
}
void pop(Stack * s){
    if(!s->top) return;
    Node * temp = s->top;
    char val = temp -> data;
    s->top = s->top->next;
    free(temp);
}
char peak(Stack* s){
    if(!s->top) return '\0';
    return s->top->data;
}
int isEmpty(Stack * s){
    if(!s->top) return 1;
    else return 0;
}