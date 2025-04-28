#include "queue.h"

void enqueue(Queue* q, int x){
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if(!q->rear){
        q->front = q->rear = n;
    }
    else{
        q->rear->next = n;
        q->rear = n;
    }
}
int dequeue(Queue* q){
    if(!q->front) return -1;

    Node *temp  = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if(!q->front) q->rear = NULL;
    free(temp);
    return val;
}
int peak(Queue* q){
    if(!q->front) return -1;
    return q->front->data;
}
int isEmpty(Queue* q){
    if(!q->front && !q->rear) return 1;
    else return 0;
}