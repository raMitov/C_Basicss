#include <stdio.h>
#include "queue.h"
int main(){

    Queue q = {NULL, NULL};

    printf("Is queue empty? %d\n", isEmpty(&q));

    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("The front of the queue is %d\n", peak(&q));

    printf("Is queue empty? %d\n", isEmpty(&q));
    printf("Dequeueing %d\n", dequeue(&q));
    printf("Dequeueing %d\n", dequeue(&q));

    printf("The front of the queue is %d\n", peak(&q));

    printf("Dequeueing %d\n", dequeue(&q));
    printf("Dequeueing %d\n", dequeue(&q));

    return 0;

}