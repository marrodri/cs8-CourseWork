//
// Created by Marthel Rodriguez on 10/2/23.
//

#include "StackVariable.h"


template<typename T>
StackVariable<T>::StackVariable() {

}

template<typename T>
void StackVariable<T>::pop() {
    return stack.pop_front();
}

template<typename T>
void StackVariable<T>::push(const T &data) {
    return stack.push_front();
}

template<typename T>
T &StackVariable<T>::top() {
    return stack.front();
}

template<typename T>
void StackVariable<T>::size() {
    return stack.size();
}

template<typename T>
bool StackVariable<T>::empty() {
    return stack.empty();
}
