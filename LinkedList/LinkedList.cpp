//
// Created by Marthel Rodriguez on 9/25/23.
//


#ifndef SPLIT_LINKEDLIST_CPP
#define SPLIT_LINKEDLIST_CPP

#include "LinkedList.h"


/**
 * LinkedList Private functions
 * */

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
    //TODO:What to do when the afterThis is located at head or tail.
    while(walker && walker->data != afterThis){
        walker = walker->next;
    }
    //TODO:if afterThis doesn't exist stop the logic and give a message to the user.
    tmpNode = walker->next ;
    walker->next = ref;
    ref->previous = walker;
    tmpNode->previous = walker;
    ref->next = tmpNode;
    _size++;
}

//Base logic done.
template<typename T>
void LinkedList<T>::insertBefore(Node<T> *ref, const T &beforeThis) {
    //TODO:what to do for adding if the goal exists at head or tail.
    Node<T> *walker = head;
    Node<T> *tmpNode;

    //TODO:search the node.
    while(walker && walker->next->data != beforeThis){
        walker = walker->next;
    }
    //TODO:what to do when no beforeThis exists.
    tmpNode = walker->next;
    walker->next = ref;
    ref->previous = walker;
    tmpNode->previous = ref;
    ref->next = tmpNode;
    _size++;
}

template<typename T>
void LinkedList<T>::remove(const T &item) {
    //
//    Node<T> *n = find(item);
//    delete(n);
}

/**
 * LinkedList Public Functions
 **/

template<typename T>
LinkedList<T>::LinkedList() {

}

template<typename T>
void LinkedList<T>::push_front(const T &item) {
    if(!head){
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
    push_front(newNode);

}

//template<typename T>
//void LinkedList<T>::remove(const T &item) {
//
//}

template<typename T>
void LinkedList<T>::pop_front() {
    Node<T> *tmpNode = this->head;
    head = head->next;
    head->previous = nullptr;
    delete(tmpNode);
}

template<typename T>
void LinkedList<T>::pop_back() {
    Node<T> *tmpNode = this->tail;
    tail = tail->previous;
    tail->next = nullptr;
    delete(tmpNode);
}

template<typename T>
void LinkedList<T>::insertAfter(const T &ref, const T &afterThis) {

}

template<typename T>
void LinkedList<T>::insertBefore(const T &ref, const T &beforeThis) {

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

/*
 * Printing functions*/
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

#endif