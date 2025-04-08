#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
// Definition of the Node structure.
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Creates a new node with given data.
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Inserts a node at the beginning of the linked list.
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Inserts a node at the end of the linked list.
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Inserts a node at a given position (1-indexed).
// If the position is less than or equal to 1, the new node is inserted at the beginning.
// If the position is greater than the length, the new node is appended at the end.
void insertAtPosition(Node** head, int data, int pos) {
    if (pos <= 1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {  // Position is beyond the current length, so insert at end.
        insertAtEnd(head, data);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Deletes the first node of the linked list.
void deleteFromBeginning(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Deletes the last node of the linked list.
void deleteFromEnd(Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) { // Only one node in the list.
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Deletes the node at a specific position (1-indexed).
void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) return;
    if (pos <= 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = *head;
    int count = 1;
    while (temp->next != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL) return;  // Position is out of bounds.
    Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Searches for the first node with a given key.
// Returns the position (1-indexed) if found, otherwise returns -1.
int search(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

// Prints the linked list.
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Counts and returns the number of nodes in the linked list.
int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


#define THRESHOLD 16
// Insertion sort: optimized for small subarrays
void insertionSort(int arr[], int left, int right) {
    int i, j, key;
    for (i = left + 1; i <= right; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge routine: merges two sorted subarrays [left, mid] and [mid+1, right]
void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy the merged subarray back into the original array.
    memcpy(&arr[left], &temp[left], (right - left + 1) * sizeof(int));
}

// Recursive merge sort routine
void mergeSortRec(int arr[], int temp[], int left, int right) {
    // Use insertion sort for small subarrays for better performance.
    if (right - left + 1 <= THRESHOLD) {
        insertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSortRec(arr, temp, left, mid);
    mergeSortRec(arr, temp, mid + 1, right);

    // Optimization: if the two subarrays are already ordered,
    // skip the merge step.
    if (arr[mid] <= arr[mid + 1])
        return;

    merge(arr, temp, left, mid, right);
}

// Merge sort wrapper function.
// This allocates a temporary array once and then calls the recursive routine.
void mergeSort(int arr[], int n) {
    int *temp = (int*) malloc(n * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    mergeSortRec(arr, temp, 0, n - 1);
    free(temp);
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a circular buffer structure.
typedef struct {
    int *buffer;      // The buffer array (can be changed to hold any data type)
    int capacity;     // Maximum number of elements in the buffer
    int head;         // Index of the next element to be dequeued
    int tail;         // Index where the next element will be enqueued
    int count;        // Number of elements currently in the buffer
} CircularBuffer;

// Create and initialize a circular buffer with given capacity.
CircularBuffer* createBuffer(int capacity) {
    CircularBuffer *cb = (CircularBuffer*) malloc(sizeof(CircularBuffer));
    if (!cb) {
        fprintf(stderr, "Memory allocation error for buffer structure.\n");
        exit(EXIT_FAILURE);
    }
    cb->buffer = (int*) malloc(capacity * sizeof(int));
    if (!cb->buffer) {
        free(cb);
        fprintf(stderr, "Memory allocation error for buffer array.\n");
        exit(EXIT_FAILURE);
    }
    cb->capacity = capacity;
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    return cb;
}

// Free the memory associated with the circular buffer.
void freeBuffer(CircularBuffer *cb) {
    if (cb) {
        free(cb->buffer);
        free(cb);
    }
}

// Return true if the buffer is empty.
bool isEmpty(CircularBuffer *cb) {
    return (cb->count == 0);
}

// Return true if the buffer is full.
bool isFull(CircularBuffer *cb) {
    return (cb->count == cb->capacity);
}

// Enqueue (write) an element into the buffer.
// Returns true if successful; false if the buffer is full.
bool enqueue(CircularBuffer *cb, int data) {
    if (isFull(cb)) {
        return false; // Cannot enqueue: buffer is full.
    }
    cb->buffer[cb->tail] = data;
    // Advance tail index using modulo arithmetic.
    cb->tail = (cb->tail + 1) % cb->capacity;
    cb->count++;
    return true;
}

// Dequeue (read) an element from the buffer.
// Returns true if successful and stores the removed data in *data; false if empty.
bool dequeue(CircularBuffer *cb, int *data) {
    if (isEmpty(cb)) {
        return false; // Cannot dequeue: buffer is empty.
    }
    *data = cb->buffer[cb->head];
    // Advance head index using modulo arithmetic.
    cb->head = (cb->head + 1) % cb->capacity;
    cb->count--;
    return true;
}

// Display the current contents of the buffer.
void displayBuffer(CircularBuffer *cb) {
    printf("Circular Buffer Contents: ");
    int index = cb->head;
    for (int i = 0; i < cb->count; i++) {
        printf("%d ", cb->buffer[index]);
        index = (index + 1) % cb->capacity;
    }
    printf("\n");
}
#define INITIAL_CAPACITY 4  // starting capacity of the stack
#define MIN_CAPACITY INITIAL_CAPACITY

// Definition of the dynamic stack
typedef struct {
    int *data;      // Pointer to the elements
    int capacity;   // Allocated capacity
    int top;        // Index of the top element (or -1 for an empty stack)
} Stack;

// Create a new stack with the given initial capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation error (stack structure)\n");
        exit(EXIT_FAILURE);
    }
    stack->data = (int*) malloc(capacity * sizeof(int));
    if (!stack->data) {
        free(stack);
        fprintf(stderr, "Memory allocation error (stack data)\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

// Check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to expand the stack capacity
bool expandStack(Stack *stack) {
    int newCapacity = stack->capacity * 2;
    int *newData = (int*) realloc(stack->data, newCapacity * sizeof(int));
    if (!newData) {
        fprintf(stderr, "Realloc error while expanding stack.\n");
        return false;
    }
    stack->data = newData;
    stack->capacity = newCapacity;
    return true;
}

// Function to shrink the stack capacity if usage is low.
bool shrinkStack(Stack *stack) {
    // Do not shrink below the minimum capacity
    if (stack->capacity <= MIN_CAPACITY) {
        return true;
    }

    int currentSize = stack->top + 1;
    if (currentSize < stack->capacity / 4) {
        int newCapacity = stack->capacity / 2;
        if (newCapacity < MIN_CAPACITY) {
            newCapacity = MIN_CAPACITY;
        }
        int *newData = (int*) realloc(stack->data, newCapacity * sizeof(int));
        if (!newData) {
            fprintf(stderr, "Realloc error while shrinking stack.\n");
            return false;
        }
        stack->data = newData;
        stack->capacity = newCapacity;
    }
    return true;
}

// Push an element onto the stack
bool push(Stack *stack, int value) {
    // Expand the stack if needed
    if (stack->top == stack->capacity - 1) {
        if (!expandStack(stack)) {
            return false;
        }
    }
    stack->data[++(stack->top)] = value;
    return true;
}

// Pop an element from the stack and store it in *value
bool pop(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow: cannot pop from an empty stack.\n");
        return false;
    }
    *value = stack->data[(stack->top)--];
    // Shrink the stack if the usage is low.
    shrinkStack(stack);
    return true;
}

// Peek the top element without removing it
bool peek(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty: cannot peek.\n");
        return false;
    }
    *value = stack->data[stack->top];
    return true;
}

// Free the stack memory
void freeStack(Stack *stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}
#define INITIAL_CAPACITY 4

// Queue structure using a circular array.
typedef struct {
    int *data;      // pointer to the array of elements
    int capacity;   // current capacity of the queue
    int front;      // index of the front (element to be dequeued next)
    int rear;       // index where the next element will be enqueued
    int count;      // current number of elements in the queue
} Queue;

// Function to create and initialize a queue with a given capacity.
Queue* createQueue(int capacity) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if (!q) {
        fprintf(stderr, "Memory allocation error for queue structure\n");
        exit(EXIT_FAILURE);
    }
    q->data = (int*) malloc(capacity * sizeof(int));
    if (!q->data) {
        free(q);
        fprintf(stderr, "Memory allocation error for queue data\n");
        exit(EXIT_FAILURE);
    }
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return q;
}

// Check if the queue is empty.
bool isEmpty(Queue *q) {
    return (q->count == 0);
}

// Check if the queue is full.
bool isFull(Queue *q) {
    return (q->count == q->capacity);
}

// Expands the queue by doubling its capacity.
// Since the queue may be a circular array, we copy the elements
// in order from the current front into a new array.
bool expandQueue(Queue *q) {
    int newCapacity = q->capacity * 2;
    int *newData = (int*) malloc(newCapacity * sizeof(int));
    if (!newData) {
        fprintf(stderr, "Memory allocation error while expanding queue\n");
        return false;
    }
    // Copy elements in order. The element at q->front should go to newData[0].
    for (int i = 0; i < q->count; i++) {
        newData[i] = q->data[(q->front + i) % q->capacity];
    }
    free(q->data); // Free old array.
    q->data = newData;
    q->capacity = newCapacity;
    q->front = 0;
    q->rear = q->count;  // Rear points to the next free position.
    return true;
}

// Enqueue an element into the queue.
// If the queue is full, expand its capacity.
bool enqueue(Queue *q, int value) {
    if (isFull(q)) {
        if (!expandQueue(q)) {
            return false;
        }
    }
    q->data[q->rear] = value;
    // Advance rear in a circular fashion.
    q->rear = (q->rear + 1) % q->capacity;
    q->count++;
    return true;
}

// Dequeue an element from the queue and store it in *value.
// Returns true if successful, false if the queue is empty.
bool dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue underflow: Cannot dequeue from an empty queue\n");
        return false;
    }
    *value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;
    return true;
}

// Utility function to print the current elements of the queue in order.
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < q->count; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->data[index]);
    }
    printf("\n");
}

// Clean up and free the memory allocated for the queue.
void freeQueue(Queue *q) {
    if (q) {
        free(q->data);
        free(q);
    }
}
#include <stdio.h>
#include <stdlib.h>

// Utility function to swap two elements.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using the Lomuto partition scheme.
// It places the pivot element (selected as arr[high]) in its correct sorted position
// and rearranges all elements so that those less than the pivot come before it,
// and those greater come after.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose the last element as pivot
    int i = low - 1;       // index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot, increment i and swap arr[i] and arr[j]
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Place the pivot element in the correct sorted position.
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main quickSort recursive function.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index.
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array.
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    // Start from the second element (index 1) as the first element is trivially sorted.
    for (i = 1; i < n; i++) {
        key = arr[i];  // current element to be inserted into the sorted region
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key one position ahead.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert key into its correct position.
        arr[j + 1] = key;
    }
}


int main(void) {
    printf("Hello, World!\n");
    return 0;
}