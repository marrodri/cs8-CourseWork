//
// Created by Marthel Rodriguez on 10/2/23.
//

#ifndef SPLIT_STACK_CPP
#define SPLIT_STACK_CPP
#include "StackInheritance.h"


template<typename T>
StackInheritance<T>::StackInheritance() {

}

template<typename T>
void StackInheritance<T>::pop() {
    this->pop_front();
}

template<typename T>
void StackInheritance<T>::push(const T &data) {
    this->push_front(data);
}

template<typename T>
T &StackInheritance<T>::top() {
    this->front();
}

#endif //SPLIT_STACK_CPP