#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Node structure for linked list
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Thread-safe queue structure
typedef struct {
    Node* head;
    Node* tail;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    size_t size;
} TSQueue;

// Initialize queue
void tsqueue_init(TSQueue* q) {
    q->head = q->tail = NULL;
    q->size = 0;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->cond, NULL);
}

// Destroy queue and free resources
void tsqueue_destroy(TSQueue* q) {
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
void tsqueue_enqueue(TSQueue* q, void* data) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    pthread_mutex_lock(&q->lock);

    if (q->tail) {
        q->tail->next = newNode;
    } else {
        q->head = newNode;
    }
    q->tail = newNode;
    q->size++;

    pthread_cond_signal(&q->cond);
    pthread_mutex_unlock(&q->lock);
}

// Remove and return item from queue (blocks if empty)
void* tsqueue_dequeue(TSQueue* q) {
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

// Get current queue size
size_t tsqueue_size(TSQueue* q) {
    pthread_mutex_lock(&q->lock);
    size_t size = q->size;
    pthread_mutex_unlock(&q->lock);
    return size;
}

// Example usage
void* producer(void* arg) {
    TSQueue* q = (TSQueue*)arg;
    for (int i = 0; i < 10; i++) {
        int* num = malloc(sizeof(int));
        *num = i;
        tsqueue_enqueue(q, num);
        printf("Enqueued: %d\n", i);
    }
    return NULL;
}

void* consumer(void* arg) {
    TSQueue* q = (TSQueue*)arg;
    for (int i = 0; i < 10; i++) {
        int* num = (int*)tsqueue_dequeue(q);
        printf("Dequeued: %d\n", *num);
        free(num);
    }
    return NULL;
}

int main() {
    TSQueue q;
    tsqueue_init(&q);

    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer, &q);
    pthread_create(&cons, NULL, consumer, &q);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    tsqueue_destroy(&q);
    return 0;
}
/*
 *#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The array grows by doubling when full, shrinks when 3/4 empty
#define GROWTH_FACTOR 2
#define SHRINK_THRESHOLD 0.25

typedef struct {
    int* data;           // Pointer to array elements
    size_t size;         // Current number of elements
    size_t capacity;     // Current maximum capacity
    pthread_mutex_t mtx; // Controls access to array
    pthread_cond_t cond; // For wait/notify patterns
} TSArray;

// Initialize array with specified initial capacity
int tsarray_init(TSArray* arr, size_t init_capacity) {
    if (init_capacity == 0) init_capacity = 4; // Minimum size

    arr->data = malloc(init_capacity * sizeof(int));
    if (!arr->data) return -1;

    arr->size = 0;
    arr->capacity = init_capacity;

    if (pthread_mutex_init(&arr->mtx, NULL) != 0) {
        free(arr->data);
        return -1;
    }

    if (pthread_cond_init(&arr->cond, NULL) != 0) {
        pthread_mutex_destroy(&arr->mtx);
        free(arr->data);
        return -1;
    }

    return 0;
}

// Free all resources
void tsarray_destroy(TSArray* arr) {
    pthread_mutex_lock(&arr->mtx);
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = 0;
    pthread_mutex_unlock(&arr->mtx);

    pthread_mutex_destroy(&arr->mtx);
    pthread_cond_destroy(&arr->cond);
}

// Internal resize helper
static void resize(TSArray* arr, size_t new_capacity) {
    int* new_data = realloc(arr->data, new_capacity * sizeof(int));
    if (!new_data) {
        fprintf(stderr, "Failed to resize array\n");
        return;
    }

    arr->data = new_data;
    arr->capacity = new_capacity;
}

// Add element to end of array
void tsarray_push(TSArray* arr, int value) {
    pthread_mutex_lock(&arr->mtx);

    if (arr->size >= arr->capacity) {
        resize(arr, arr->capacity * GROWTH_FACTOR);
    }

    arr->data[arr->size++] = value;
    pthread_cond_signal(&arr->cond); // Wake any waiting threads
    pthread_mutex_unlock(&arr->mtx);
}

// Remove and return last element, blocks if empty
int tsarray_pop(TSArray* arr) {
    pthread_mutex_lock(&arr->mtx);

    while (arr->size == 0) {
        pthread_cond_wait(&arr->cond, &arr->mtx);
    }

    int value = arr->data[--arr->size];

    // Shrink if we're below threshold
    if (arr->size <= arr->capacity * SHRINK_THRESHOLD
        && arr->capacity > 4) {
        resize(arr, arr->capacity / GROWTH_FACTOR);
    }

    pthread_mutex_unlock(&arr->mtx);
    return value;
}

// Get element at index (NULL if out of bounds)
int* tsarray_get(TSArray* arr, size_t index) {
    pthread_mutex_lock(&arr->mtx);
    int* value = NULL;

    if (index < arr->size) {
        value = &arr->data[index];
    }

    pthread_mutex_unlock(&arr->mtx);
    return value;
}

// Example usage with producer-consumer pattern
void* producer(void* arg) {
    TSArray* arr = (TSArray*)arg;
    for (int i = 0; i < 100; i++) {
        tsarray_push(arr, i);
        printf("Produced: %d\n", i);
    }
    return NULL;
}

void* consumer(void* arg) {
    TSArray* arr = (TSArray*)arg;
    for (int i = 0; i < 100; i++) {
        int val = tsarray_pop(arr);
        printf("Consumed: %d\n", val);
    }
    return NULL;
}

int main() {
    TSArray arr;
    if (tsarray_init(&arr, 10) != 0) {
        fprintf(stderr, "Failed to initialize array\n");
        return 1;
    }

    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer, &arr);
    pthread_create(&cons, NULL, consumer, &arr);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    tsarray_destroy(&arr);
    return 0;
}




// pipeline.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10   // Size of the bounded buffer
#define TERMINATION_VAL -1  // Special value to indicate end-of-data

// -------- Buffer (Queue) Structure --------
typedef struct {
    int data[BUFFER_SIZE];       // Array to hold the items
    int front, rear, count;      // For circular buffer management
    pthread_mutex_t mutex;       // Mutex for protecting buffer access
    pthread_cond_t notEmpty;     // Condition variable: buffer is not empty
    pthread_cond_t notFull;      // Condition variable: buffer is not full
} Buffer;

// Initialize the buffer
void buffer_init(Buffer* buf) {
    buf->front = 0;
    buf->rear = 0;
    buf->count = 0;
    pthread_mutex_init(&buf->mutex, NULL);
    pthread_cond_init(&buf->notEmpty, NULL);
    pthread_cond_init(&buf->notFull, NULL);
}

// Destroy (clean up) the buffer
void buffer_destroy(Buffer* buf) {
    pthread_mutex_destroy(&buf->mutex);
    pthread_cond_destroy(&buf->notEmpty);
    pthread_cond_destroy(&buf->notFull);
}

// Push an item into the buffer (producer)
void buffer_push(Buffer *buf, int item) {
    pthread_mutex_lock(&buf->mutex);
    while (buf->count == BUFFER_SIZE) {  // Buffer full: wait for space
        pthread_cond_wait(&buf->notFull, &buf->mutex);
    }
    buf->data[buf->rear] = item;
    buf->rear = (buf->rear + 1) % BUFFER_SIZE;
    buf->count++;
    pthread_cond_signal(&buf->notEmpty);
    pthread_mutex_unlock(&buf->mutex);
}

// Pop an item from the buffer (consumer)
int buffer_pop(Buffer *buf) {
    int item;
    pthread_mutex_lock(&buf->mutex);
    while (buf->count == 0) {  // Buffer empty: wait for data
        pthread_cond_wait(&buf->notEmpty, &buf->mutex);
    }
    item = buf->data[buf->front];
    buf->front = (buf->front + 1) % BUFFER_SIZE;
    buf->count--;
    pthread_cond_signal(&buf->notFull);
    pthread_mutex_unlock(&buf->mutex);
    return item;
}

// Global buffers for the pipeline stages
Buffer buffer1;  // Stage 1 -> 2
Buffer buffer2;  // Stage 2 -> 3
Buffer buffer3;  // Stage 3 -> 4

// -------- Stage 1: Producer (Read file) --------
void* producer(void* arg) {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Error opening input.txt");
        exit(EXIT_FAILURE);
    }
    int num;
    // Read numbers from the file
    while (fscanf(fp, "%d", &num) == 1) {
        buffer_push(&buffer1, num);
    }
    fclose(fp);
    // Signal end-of-data in the pipeline
    buffer_push(&buffer1, TERMINATION_VAL);
    return NULL;
}

// -------- Stage 2: Count Divisors --------
// Function to count the number of divisors of a positive integer
int count_divisors(int n) {
    if (n <= 0) return 0;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            count++;
    }
    return count;
}

void* countDivisors(void* arg) {
    while (1) {
        int num = buffer_pop(&buffer1);
        // Check for termination value
        if (num == TERMINATION_VAL) {
            buffer_push(&buffer2, TERMINATION_VAL);
            break;
        }
        int divisors = count_divisors(num);
        buffer_push(&buffer2, divisors);
    }
    return NULL;
}

// -------- Stage 3: Square the Count --------
void* squareStage(void* arg) {
    while (1) {
        int divisors = buffer_pop(&buffer2);
        // Check for termination value
        if (divisors == TERMINATION_VAL) {
            buffer_push(&buffer3, TERMINATION_VAL);
            break;
        }
        int squared = divisors * divisors;
        buffer_push(&buffer3, squared);
    }
    return NULL;
}

// -------- Stage 4: Writer (Write to file) --------
void* writer(void* arg) {
    FILE* fp = fopen("output.txt", "w");
    if (!fp) {
        perror("Error opening output.txt");
        exit(EXIT_FAILURE);
    }
    while (1) {
        int result = buffer_pop(&buffer3);
        // Termination signal: stop writing
        if (result == TERMINATION_VAL) {
            break;
        }
        fprintf(fp, "%d\n", result);
    }
    fclose(fp);
    return NULL;
}

// -------- Main Function --------
int main(void) {
    // Initialize buffers
    buffer_init(&buffer1);
    buffer_init(&buffer2);
    buffer_init(&buffer3);

    // Create thread identifiers
    pthread_t prod_thread, count_thread, square_thread, writer_thread;

    // Create threads for each stage of the pipeline
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&count_thread, NULL, countDivisors, NULL);
    pthread_create(&square_thread, NULL, squareStage, NULL);
    pthread_create(&writer_thread, NULL, writer, NULL);

    // Wait for all threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(count_thread, NULL);
    pthread_join(square_thread, NULL);
    pthread_join(writer_thread, NULL);

    // Clean up buffers
    buffer_destroy(&buffer1);
    buffer_destroy(&buffer2);
    buffer_destroy(&buffer3);

    printf("Pipeline processing complete. See output.txt for results.\n");
    return 0;
}

 */
