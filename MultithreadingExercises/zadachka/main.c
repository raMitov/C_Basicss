#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>



typedef struct Node {
    void* data;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
    Node* tail;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    size_t size;
} Queue;

// Initialize queue
void queue_init(Queue* q) {
    q->head = q->tail = NULL;
    q->size = 0;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->cond, NULL);
}

// Destroy queue
void queue_destroy(Queue* q) {
    pthread_mutex_lock(&q->lock);
    Node* current = q->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    pthread_mutex_unlock(&q->lock);
    pthread_mutex_destroy(&q->lock);
    pthread_cond_destroy(&q->cond);
}

// Add item to queue
void queue_enqueue(Queue* q, void* data) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->tail) {
        q->tail->next = newNode;
    } else {
        q->head = newNode;
    }
    q->tail = newNode;
    q->size++;
}
void* queue_dequeue(Queue* q) {
    pthread_mutex_lock(&q->lock);

    while (!q->head) {
        pthread_cond_wait(&q->cond, &q->lock);
    }
    Node* node = q->head;
    void* data = node->data;
    q->head = node->next;
    if (!q->head) {
        q->tail = NULL;
    }
    q->size--;
    free(node);
    pthread_mutex_unlock(&q->lock);
    return data;
}

int main(void) {
    FILE * file = fopen("test.txt", "r");
    if (!file) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }
    int K, N, M;
    fscanf(file, "%d %d %d", &K, &N, &M);
    fclose(file);
    pthread_t *prodId1 = malloc (sizeof(pthread_t) * K);
    N = N / 2;
    for (int i = 0; i < K; i++) {
        pthread_create(&prodId1[i], NULL, &queue_init, &N);
    }
    for (int i = 0; i < K;i++) {
        pthread_join(prodId1[i], NULL);
    }

    //I dont know
    free(prodId1);
    return 0;

}