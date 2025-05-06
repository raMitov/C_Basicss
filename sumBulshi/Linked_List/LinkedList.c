#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

typedef struct LinkedList{
    Node * head;
    int length;
}LinkedList;
void push(LinkedList *ls, int data){
    Node * newNode = malloc(sizeof(Node));
    if(!newNode) return;
    newNode->data = data;
    newNode->next = ls->head;
    ls->head = newNode;
    ls->length++;
}
void printList(LinkedList *ls){
    Node * newNode = newNode = ls->head;
    while(newNode){
        printf("%d", newNode->data);
        newNode = newNode->next;
    }
    printf("NULL");
}
void reverseList(LinkedList *ls){
    Node *prev = NULL;
    Node *current = ls->head;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;  
        current->next = prev; 
        prev = current;        
        current = next;        
    }

    ls->head = prev;  
}
int main(){
    LinkedList *ls = malloc(sizeof(LinkedList));
    ls->head = NULL;
    ls->length = 0;
    push(ls, 10);
    push(ls, 13);
    push(ls, 14);
    printList(ls);

    //skipping free cuz idc
}