#pragma once

template<class T>class LinkedList{
    private:
    typedef struct Node{
        T data;
        struct Node * next;
        Node(const T& v) : data(v), next(nullptr) {}
    }Node;
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList();

    ~LinkedList();

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_front();
    int find(const T& value) const;
    void removeAt(int idx);
    void printLIst() const;

};
#include "LinkedList.tpp"
