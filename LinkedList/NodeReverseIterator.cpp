//
// Created by Marthel Rodriguez on 10/10/23.
//

#ifndef SPLIT_NODEREVERSEITERATOR_CPP
#define SPLIT_NODEREVERSEITERATOR_CPP
#include "NodeReverseIterator.h"

template<typename T>
NodeReverseIterator<T>::NodeReverseIterator(Node<T>*current):current(current){
    this->current = current;
} // one line code

/**
* postfix: ++int
* ++x -> increment x; return x;
*/
template<typename T>
NodeReverseIterator<T> NodeReverseIterator<T>::operator++(int){
    NodeReverseIterator<T> copy(current);
    current = current->previous;
    return copy;
}

/**
 * prefix: int++
 * x++ -> copy x; then increment x;
 * then return copy.
 */
template<typename T>
NodeReverseIterator<T> &NodeReverseIterator<T>::operator++(){
    this->current = current->previous;
    return *this;
} //one line or two line

/**
 * decrementors
 **/
template<typename T>
NodeReverseIterator<T> NodeReverseIterator<T>::operator--(int){
    NodeReverseIterator<T> copy(current);
    current = current->next;
    return copy;
}

template<typename T>
NodeReverseIterator<T> &NodeReverseIterator<T>::operator--(){
    this->current = current->next;
    return *this;
}


/**
 * deferencing objects
 * */
template<typename T>
T &NodeReverseIterator<T>::operator *(){
    return current->data;
}

template<typename T>
const T &NodeReverseIterator<T>::operator*() const{
    return current->data;
}


template<typename T>
NodeReverseIterator<T> NodeReverseIterator<T>::operator+=(int add){
    for(int i =0; i < add;i++){
        current++;
    }
    return current;
}

template<typename T>
NodeReverseIterator<T> NodeReverseIterator<T>::operator-=(int subtract){
    for(int i =0; i < subtract;i++){
        current--;
    }
    return current;
}

template<typename T>
NodeReverseIterator<T> NodeReverseIterator<T>::operator+(int add){
    for(int i =0; i < add;i++){
        current++;
    }
    return current;
}

template<typename U>
bool operator!=(const NodeReverseIterator<U> &rhs, const NodeReverseIterator<U> &lhs){
    return (rhs.current != lhs.current);
}

template<typename U>
bool operator==(const NodeReverseIterator<U> &rhs, const  NodeReverseIterator<U> &lhs){
    return (rhs.current == lhs.current);
}


#endif
