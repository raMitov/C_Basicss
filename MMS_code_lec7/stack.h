#ifndef STACK_H
#define STACK_H

typedef struct Node{
    char data;
    struct Node* next;
}Node;

typedef struct Stack{
    struct Node* top;
}Stack;

void push(Stack* s, char x);
void pop(Stack * s);
char peak(Stack* s);
int isEmpty(Stack * s);

#endif