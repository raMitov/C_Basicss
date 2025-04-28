#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;

}Node;

typedef struct Queue{
    Node * front;
    Node * rear;
}Queue;

void enqueue(Queue* q, int x);
int dequeue(Queue* q);
int peak(Queue* q);
int isEmpty(Queue* q);
#endif