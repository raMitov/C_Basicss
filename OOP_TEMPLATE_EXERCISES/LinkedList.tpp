#include "LinkedList.h"
#include <new>
    template<typename T>
    LinkedList<T>::LinkedList()
    : head(nullptr), tail(nullptr), size(0) {}

    template<typename T>
    LinkedList<T>::~LinkedList() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    size = 0;
    }
    template<typename T>
    void LinkedList<T>::push_back(const T& value){
        Node* newNode = new Node(value);
         if (!tail) {
        head = tail = newNode;
        } else {
        tail->next = newNode;
        tail = newNode;
        }
        ++size;

    }
    template<typename T>
    void LinkedList<T>::push_front(const T& value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if(!tail) tail = head;
        ++size;
    }
    template<typename T>
    void LinkedList<T>::pop_front(){
        if(!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        if(!head) tail = nullptr;
    }
    template<typename T>
    int LinkedList<T>::find(const T& value) const{
        nt idx = 0;
        for (Node* cur = head; cur; cur = cur->next, ++idx) {
            if (cur->data == value) return idx;
        }
        return -1;

    }
    template <typename T>
    void LinkedList<T>::removeAt(int idx){
        if (idx < 0 || idx >= size) return;
        if (idx == 0) { pop_front(); return; }
         Node* cur = head;
         for (int i = 0; i < idx - 1; ++i) cur = cur->next;
         Node* toDelete = cur->next;
         cur->next = toDelete->next;
         if (toDelete == tail) tail = cur;
         delete toDelete;
        --size;

    }
    template <typename T>
    void LinkedList<T>::printLIst() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }