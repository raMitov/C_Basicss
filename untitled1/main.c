#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void append(Node** head, int data) {
    Node* node = createNode(data);
    if ((*head) == NULL) {
        (*head) = node;
    }
    else {
        Node* temp = (*head);
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}
Node* readListFromFIle(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    Node* head = NULL;
    char buffer[256];

    // Четене ред по ред
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Разделяне на реда на отделни "токени" (низове) според интервали, табулация и нов ред
        char *token = strtok(buffer, " \t\n");
        while (token != NULL) {
            // Преобразуване на низа към цяло число
            int num = (int)strtol(token, NULL, 10);
            append(&head, num);
            token = strtok(NULL, " \t\n");
        }
    }
    fclose(file);
    return head;
}
void writeListToFile(Node* head, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Грешка при отваряне на файла за запис");
        exit(EXIT_FAILURE);
    }
    Node *temp = head;
    while (temp != NULL) {
        fprintf(file, "%d ", temp->data);
        temp = temp->next;
    }
    fclose(file);
}
void splitEvenOdd(Node* head, Node** evenList, Node** oddList) {
    while (head != NULL) {
        if (head->data % 2 == 0) {
            append(evenList, head->data);
        } else {
            append(oddList, head->data);
        }
        head = head->next;
    }
}
// Функция за сливане на два сортирани списъка (подфункция за merge sort)
Node* sortedMerge(Node* a, Node* b) {
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    Node* result = NULL;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Функция за намиране на средния елемент на списъка
Node* getMiddle(Node* head) {
    if (head == NULL)
        return head;
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Реализация на merge sort за свързан списък
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    // Намиране на средата
    Node* middle = getMiddle(head);
    Node* nextOfMiddle = middle->next;

    // Разделяне на списъка на две части
    middle->next = NULL;

    // Рекурсивно сортиране на двете половини
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextOfMiddle);

    // Сливане на двете сортирани половини
    Node* sortedList = sortedMerge(left, right);
    return sortedList;
}

// Функция за освобождаване на паметта за свързания списък
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(void) {
    const char* inputFilename = "input.txt";
    const char* evenFilename = "even.txt";
    const char* oddFilename = "odd.txt";
    Node* head = readListFromFIle(inputFilename);
    Node* evenList = NULL;
    Node* oddList = NULL;
    splitEvenOdd(head, &evenList, &oddList);

    // Записване на четните и нечетните числа във файловете
    writeListToFile(evenList, evenFilename);
    writeListToFile(oddList, oddFilename);

    // Сортиране на оригиналния списък чрез merge sort
    head = mergeSort(head);

    // Записване на сортирания списък обратно във входния файл
    writeListToFile(head, inputFilename);

    // Освобождаване на заделената памет
    freeList(head);
    freeList(evenList);
    freeList(oddList);

    printf("Операциите са изпълнени успешно.\n");
    return 0;
}