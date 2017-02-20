#include "MyStack.h"
#include "Coordinate.h"

template <class T>
MyStack<T>::MyStack(): size(0), head(NULL) {
}

template <class T>
MyStack<T>::~MyStack() {
    Node* to_delete = this->head;
    while (to_delete != NULL) {
        this->head = to_delete->next;
        delete to_delete;
        to_delete = this->head;
    }
}

template <class T>
void MyStack<T>::push(T& t) {
    this->head = new Node(t, this->head);
    this->size ++;
}

template <class T>
void MyStack<T>::pop() {
    Node* to_delete = this->head;
    this->head = this->head->next;
    delete to_delete;
    this->size --;
}

template <class T>
T& MyStack<T>::top() {
    return this->head->value;
}

template <class T>
size_t MyStack<T>::getSize() const {
    return this->size;
}

template <class T>
bool MyStack<T>::empty() const {
    return !this->size;
}

template <class T>
MyStack<T>::Node::Node(T& t, Node* node): value(t), next(node) {
}

template class MyStack < char >; 
template class MyStack < Coordinate >; 

