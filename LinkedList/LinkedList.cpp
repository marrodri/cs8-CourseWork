//
// Created by Marthel Rodriguez on 9/25/23.
//

#ifndef SPLIT_LINKEDLIST_CPP
#define SPLIT_LINKEDLIST_CPP

#include "LinkedList.h"

/**
 * LinkedList Private functions
 * */
template<typename T>
Node<T> *LinkedList<T>::find(const T& ref){
    Node<T> *walker = head;
    while(walker && walker->data != ref){
        walker = walker->next;
    }
    return walker;
}

//done
template<typename T>
Node<T> *LinkedList<T>::createNode(const T &item) {
    Node<T> *newNode = new Node<T>;
    newNode->data = item;
    return newNode;
}

//done
template<typename T>
void LinkedList<T>::addFirstNode(const T &item) {
    Node<T> *newNode =createNode(item);
    this->head = newNode;
    this->tail = newNode;
    _size++;
}

//done
template<typename T>
void LinkedList<T>::push_front(Node<T> *item) {
    //set item->next to the head.
    item->next = head;
    //then head-> previous is connected to newNode.
    head->previous = item;
    //then set newNode = head.
     head =item;
    _size++;
}

//done
template<typename T>
void LinkedList<T>::push_back(Node<T> *item) {
    //set tail->next to item.
    tail->next = item;
    //set item->previous to tail.
    item->previous = tail;
    //set tail to item.
    tail = item;
    _size++;
}

//base logic done
template<typename T>
void LinkedList<T>::insertAfter(Node<T> *ref, const T &afterThis) {
    Node<T> *walker = head;
    Node<T> *tmpNode;
    walker = find(afterThis);
    if(!walker){
        std::cout << "no data has been founded in the linked list.\n";
        return ;
    }
    tmpNode = walker->next;
    walker->next = ref;
    ref->previous = walker;
    tmpNode->previous = ref;
    ref->next = tmpNode;
    _size++;
}

//Base logic done.
template<typename T>
void LinkedList<T>::insertBefore(Node<T> *ref, const T &beforeThis) {
    Node<T> *walker = find(beforeThis);
    Node<T> *tmpNode;
    if(!walker){
        std::cout << "target doesn't exist.\n";
        return ;
    }
    tmpNode = walker->previous;
    walker->previous = ref;

    ref->next = walker;

    ref->previous = tmpNode;
    tmpNode->next = ref;
    _size++;
}

template<typename T>
void LinkedList<T>::remove(const T &item) {
    Node<T> *n = find(item);
    delete(n);
    _size--;
}

/**
 * LinkedList Public Functions
 **/

template<typename T>
LinkedList<T>::LinkedList() {

}

template<typename T>
void LinkedList<T>::push_front(const T &item) {
    if(!head) {
        addFirstNode(item);
        return ;
    }
    Node<T> *newNode = createNode(item);
    push_front(newNode);
}

template<typename T>
void LinkedList<T>::push_back(const T& item) {
    if (!head) {
        addFirstNode(item);
        return ;
    }
    Node<T> *newNode = createNode(item);
    push_back(newNode);
}

template<typename T>
void LinkedList<T>::pop_front() {
    Node<T> *tmpNode = this->head;
    head = head->next;
    head->previous = nullptr;
    delete(tmpNode);
    _size--;
}

template<typename T>
void LinkedList<T>::pop_back() {
    Node<T> *tmpNode = this->tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete(tmpNode);
    _size--;
}

template<typename T>
void LinkedList<T>::insertAfter(const T &ref, const T &afterThis) {
    if(afterThis == tail->data){
        this->push_back(ref);
    }
    else{
        Node<T> *newNode = createNode(ref);
        this->insertAfter(newNode, afterThis);
    }
}

template<typename T>
void LinkedList<T>::insertBefore(const T &ref, const T &beforeThis) {
    if(beforeThis == head->data){
        this->push_front(ref);
    }
    else{
        Node<T> *newNode = createNode(ref);
        this->insertBefore(newNode, beforeThis);
    }
}

template<typename T>
int LinkedList<T>::size() {
    return _size;
}

template<typename T>
const T &LinkedList<T>::front() const {
    return head;
}

template<typename T>
const T &LinkedList<T>::back() const {
    return tail;
}

template<typename T>
bool LinkedList<T>::empty(){
    return (head == nullptr);
}

/**
 * Printing functions
 **/
template<typename T>
void LinkedList<T>::printListFromHead() const {
    Node<T> *walker;
    walker = head;
    std::cout << "Printing linked list from head\n";
    while(walker){
        std::cout << "[";
        std::cout << walker->data;
        std::cout << "]->";
        walker = walker->next;
    }
    std::cout << "nullptr\n";
    std::cout <<"==========================\n";
}

template<typename T>
void LinkedList<T>::printListFromTail() const {
    Node<T> *walker;
    walker = tail;
    std::cout << "Printing linked list from tail\n";
    while(walker){
        std::cout << "[";
        std::cout << walker->data;
        std::cout << "]->";
        walker = walker->previous;
    }
    std::cout << "nullptr\n";
    std::cout <<"==========================\n";
}

template<typename U> //Done.
std::ostream &operator<<(std::ostream &out, const LinkedList<U> &linkedList){
    Node<U> *walker = linkedList.head;
    while(walker){
        out << "[";
        out << walker->data;
        out << "]->";
        walker = walker->next;
    }
    out << "nullptr\n";
    return out;
}

#endif