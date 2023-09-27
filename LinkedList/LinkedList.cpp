//
// Created by Marthel Rodriguez on 9/25/23.
//


#ifndef SPLIT_LINKEDLIST_CPP
#define SPLIT_LINKEDLIST_CPP

#include "LinkedList.h"


template<typename T>
Node<T> *LinkedList<T>::createNode(const T &item) {
    return new Node{data:item};
}

template<typename T>
void LinkedList<T>::addFirstNode(const T &item) {
    Node<T> *newNode =createNode(item);
    this->head = newNode;
    this->tail = newNode;
    _size++;
}

template<typename T>
void LinkedList<T>::push_front(Node<T> *item) {
    //set item->next to the head.
    item->next = head;
    //then head-> previous is connected to newNode.
    head->previous = item;
    //then set newNode = head.
    item = head;
    _size++;
}

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

template<typename T>
void LinkedList<T>::insertAfter(Node<T> *ref, const T &afterThis) {
    Node<T> *walker = head;
    Node<T> *tmpNode;
    //What to do when the afterThis is located at head or tail.
    while(walker && walker->data != afterThis){
        walker = walker->next;
    }
    //if afterThis doesn't exist stop the logic and give a message to the user.
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
    //what to do for adding if the goal exists at head or tail.
    Node<T> *walker = head;
    Node<T> *tmpNode;

    //search the node.
    while(walker && walker->next->data != beforeThis){
        walker = walker->next;
    }
    //what to do when no beforeThis exists..
    tmpNode = walker->next;
    walker->next = ref;
    ref->previous = walker;
    tmpNode->previous = ref;
    ref->next = tmpNode;
    _size++;
}

//template<typename T>
//void LinkedList<T>::remove() {
//    //
//}

template<typename T>
LinkedList<T>::LinkedList() {

}

template<typename T>
void LinkedList<T>::push_front(const T &item) {
    if(!tail || !head){
        addFirstNode(item);
        return ;
    }
    Node<T> *newNode = createNode(item);
    push_front(newNode);
    _size++;
}

template<typename T>
void LinkedList<T>::push_back(const T& item) {
    if (!tail || !head) {
        addFirstNode(item);
        return ;
    }
    Node<T> *newNode = createNode(item);
    push_front(newNode);
    _size++;
}

template<typename T>
void LinkedList<T>::remove(const T &item) {

}

template<typename T>
void LinkedList<T>::pop_front() {

}

template<typename T>
void LinkedList<T>::pop_back() {

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


#endif