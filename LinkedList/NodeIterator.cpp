//
// Created by Marthel Rodriguez on 10/3/23.
//

#ifndef SPLIT_NODEITERATOR_CPP
#define SPLIT_NODEITERATOR_CPP

#include "NodeIterator.h"

//template<typename T>
//NodeIterator<T>::NodeIterator() {
//
//}

template<typename T>
NodeIterator<T>::NodeIterator(Node<T> *current) : current(current){
    this->current = current;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++(int) {
    NodeIterator<T> copy(current);
    current = current->next;
    return copy;
}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator++() {
    current = current->next;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--(int) {
    NodeIterator<T> copy(current);
    current = current->previous;
    return copy;
}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator--() {
    current = current->previous;
    return *this;
}

template<typename T>
T &NodeIterator<T>::operator*() {
    return current->data;
}



template<typename T>
const T &NodeIterator<T>::operator*() const{
    return current->data;
}

template<typename T>
bool NodeIterator<T>::operator!=(const T &data) {
    return (current->data != data);
}

//add list
template<typename T>
NodeIterator<T> NodeIterator<T>::operator+=(int add){
    for(int i =0; i < add; i++){
        current++;
    }
    return current;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator-=(int subtract){
    for(int i =0; i < subtract; i++){
        current--;
    }
    return current;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator+(int add){
    for(int i =0; i < add; i++){
        current++;
    }
    return current;
}

template<typename U>
bool operator!=(const NodeIterator<U> &rhs, const  NodeIterator<U> &lhs){
    //compare address, not data
    return (rhs.current != lhs.current);
}

template<typename U>
bool operator==(const NodeIterator<U> &rhs, const NodeIterator<U> &lhs){
    return (rhs.current == lhs.current);
}

#endif

