#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    float data;
    struct Node *next;
} Node;


Node* readList() {
    Node *head = NULL, *tail = NULL;
    float value;
    while (scanf("%f", &value) == 1) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            //here is the problem
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (tail != NULL) {
        tail->next = NULL;
    }
    return head;
}


void print(Node *node) {
    if (node == NULL) {
        printf("empty\n");
        return;
    }
    Node *curr = node;
    do {
        //??? omg
        printf("%f", curr->data);
        curr = curr->next;
    } while (curr != node);
    printf("\n");
}

int getLength(Node *node) {
    if (node == NULL) {
        return 0;
    }
    int count = 0;
    Node *curr = node;
    do {
        count++;
        curr = curr->next;
    } while (curr != node);
    return count;
}

int areEqual(Node *node1, Node *node2) {
    if (node1 == NULL && node2 == NULL)
        return 1;
    if (node1 == NULL || node2 == NULL)
        return 0;

    int len1 = getLength(node1);
    int len2 = getLength(node2);
    if (len1 != len2)
        return 0;

    Node *curr1 = node1, *curr2 = node2;
    do {
        if (curr1->data != curr2->data)
            return 0;
        curr1 = curr1->next;
        curr2 = curr2->next;
    } while (curr1 != node1 && curr2 != node2);

    return 1;
}

void insertAfterN(Node *node, int skipCount, float newElem) {
    if (node == NULL)
        return;
    Node *curr = node;
    for (int i = 0; i < skipCount; i++) {
        curr = curr->next;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("error\n");
        exit(1);
    }
    newNode->data = newElem;
    newNode->next = curr->next;
    curr->next = newNode;
}

void deleteFirst(Node **ptr) {
    if (ptr == NULL || *ptr == NULL)
        return;

    Node *head = *ptr;

    if (head->next == head) {
        free(head);
        *ptr = NULL;
        return;
    }

    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node *newHead = head->next;
    last->next = newHead;
    free(head);
    *ptr = newHead;
}

Node* copyCyclicList(Node *node) {
    if (node == NULL)
        return NULL;
    int n = getLength(node);
    Node *newHead = NULL, *newTail = NULL;
    Node *curr = node;
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("error\n");
            exit(1);
        }
        newNode->data = curr->data;
        newNode->next = NULL;
        if (newHead == NULL) {
            newHead = newNode;
            newTail = newNode;
        } else {
            newTail->next = newNode;
            newTail = newNode;
        }
        curr = curr->next;
    }
    if (newTail != NULL) {
        newTail->next = newHead;
    }
    return newHead;
}

void freeCyclicList(Node *node) {
    if (node == NULL) {
        return;
    }
    Node *curr = node;
    Node *nextNode;
    do {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    } while (curr != node);
}
int main(void) {
    Node * circList = NULL;
    circList = readList();
    print(circList);
    freeCyclicList(circList);
}