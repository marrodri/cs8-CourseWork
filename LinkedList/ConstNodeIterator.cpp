//
// Created by Marthel Rodriguez on 10/10/23.
//

#ifndef SPLIT_NODEREVERSEITERATOR_CPP
#define SPLIT_NODEREVERSEITERATOR_CPP
#include "ConstNodeIterator.h"

template<typename T>
ConstNodeIterator<T>::ConstNodeIterator(const Node<T>*current):current(current){
    this->current = current;
} // one line code

/**
* postfix: ++int
* ++x -> increment x; return x;
*/
template<typename T>
const ConstNodeIterator<T> ConstNodeIterator<T>::operator++(int) const{
    ConstNodeIterator<T> copy(current);
    current = current->next;
    return copy;
}

template<typename T>
ConstNodeIterator<T> &ConstNodeIterator<T>::operator++(){
    current = current->next;
    return *this;
}

/*
 * decrementors*/
template<typename T>
const ConstNodeIterator<T> ConstNodeIterator<T>::operator--(int) const{
    ConstNodeIterator<T> copy(current) ;
    current = current->previous;
    return copy;
}

template<typename T>
ConstNodeIterator<T> &ConstNodeIterator<T>::operator--() const{
    current = current->previous;
    return *this;
}

/**TODOs*/
template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator+=(int add){
    for(int i =0; i < add;i++){
        current++;
    }
    return current;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator-=(int subtract){
    for(int i =0; i < subtract;i++){
        current--;
    }
    return current;
}

template<typename T>
ConstNodeIterator<T> ConstNodeIterator<T>::operator+(int add){
    for(int i =0; i < add;i++){
        current++;
    }
    return current;
}

template<typename T>
const T &ConstNodeIterator<T>::operator*() const{
    return *this;
}

/**DONE*/
template<typename U>
bool operator!=(const ConstNodeIterator<U> &rhs, const ConstNodeIterator<U> &lhs){
    return (rhs.current != lhs.current);
}

template<typename U>
bool operator==(const ConstNodeIterator<U> &rhs, const  ConstNodeIterator<U> &lhs){
    return rhs.current == lhs.current;
}


#endif
