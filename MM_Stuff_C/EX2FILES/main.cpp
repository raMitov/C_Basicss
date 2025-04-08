#include <iostream>
#include <new>
#include <string.h>
typedef struct Node {
    int data;
    Node* next;

}Node;
void add(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {

        head = newNode;
    } else {

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void freeList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}
bool isEven(int n)
{
    // n^1 is n+1, then even, else odd
    if ((n ^ 1) == (n + 1))
        return true;
    else
        return false;
}
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void split(Node* source, Node** frontRef, Node** backRef) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node** headRef) {
    if (*headRef == nullptr || (*headRef)->next == nullptr)
        return;

    Node* a;
    Node* b;

    split(*headRef, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}

int main() {
    FILE * f = fopen("input.txt", "r");
    int n;
    Node * allNumbers = nullptr;
    Node * oddNumbers = nullptr;
    Node * evenNumbers = nullptr;
    while (fscanf(f, "%d", &n) != EOF) {
        add(allNumbers, n);
        if (isEven(n)) {
            add(evenNumbers, n);
        }
        else {
            add(oddNumbers, n);
        }
    }
    fclose(f);
    mergeSort(&evenNumbers);
    mergeSort(&oddNumbers);
    FILE * oddFile = fopen("odd.txt", "w");
    FILE * evenFile = fopen("even.txt", "w");
    while (oddNumbers != nullptr) {
        fprintf(oddFile, "%d\n", oddNumbers->data);
        oddNumbers = oddNumbers->next;
    }
    fclose(oddFile);
    while (evenNumbers != nullptr) {
        fprintf(evenFile, "%d\n", evenNumbers->data);
        evenNumbers = evenNumbers->next;
    }
    freeList(allNumbers);
    freeList(evenNumbers);
    freeList(oddNumbers);
    return 0;
}

