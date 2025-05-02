#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    pthread_mutex_t mutex;
    pthread_cond_t notEmpty;
}TsQueue;

void push(TsQueue *tsq, int x);
void pop(TsQueue *tsq);
void tsqInit(TsQueue *tsq){
    tsq->head = tsq->tail = NULL;
    pthread_mutex_init(&tsq->mutex, NULL);
    pthread_cond_init(&tsq->notEmpty, NULL);
}
void* work(void *arg){
    TsQueue *tsq = (TsQueue*)arg;
    for(int i = 0; i < 10; i++){
        push(tsq, i);
    }
}
void* work2(void *arg){
    TsQueue *tsq = (TsQueue*)arg;
    pop(tsq);
}
void destroyQ(TsQueue *tsq);




int main(){
    TsQueue tsq;
    tsqInit(&tsq);
    pthread_t hui;
    pthread_create(&hui, NULL, work, &tsq);
    pthread_t hui2;
    pthread_create(&hui2, NULL, work2, &tsq);
    pthread_join(hui, NULL);
    pthread_join(hui2, NULL);
}





void push(TsQueue *tsq, int x){
    Node * newNode = malloc(sizeof(Node));
    
    if(!newNode) return;
    newNode->data = x;
    newNode->next = NULL;
    pthread_mutex_lock(&tsq->mutex);
    if(tsq->tail){
        tsq->tail->next = newNode;
        tsq->tail = newNode;
    }
    else{
        tsq->head = tsq->tail = newNode;
    }
    pthread_cond_signal(&tsq->notEmpty);
    pthread_mutex_unlock(&tsq->mutex);
}
void pop(TsQueue *tsq){
    pthread_mutex_lock(&tsq->mutex);
    
    while(tsq->head == NULL){
        pthread_cond_wait(&tsq->notEmpty, &tsq->mutex);
    }
    Node * node = tsq->head;
    tsq->head = node->next;
    if(tsq->head == NULL) tsq->tail = NULL;
    free(node);
    pthread_mutex_unlock(&tsq->mutex);
    
}
void destroyQ(TsQueue *tsq){
    pthread_mutex_lock(&tsq->mutex);
    Node* tmp = tsq->head;
    while(tmp){
        Node* temp = tmp;
        tmp = temp->next;
        free(temp);
    }
    pthread_mutex_unlock(&tsq->mutex);
    pthread_mutex_destroy(&tsq->mutex);
    pthread_cond_destroy(&tsq->notEmpty);
}
