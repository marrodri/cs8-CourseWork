//
// Created by Marthel Rodriguez on 10/3/23.
//

#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator() {

}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++(int) {
    return NodeIterator<T>();
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++() {
    return NodeIterator<T>();
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--(int) {
    return NodeIterator<T>();
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--() {
    return NodeIterator<T>();
}

template<typename T>
T &NodeIterator<T>::operator*() {
    return <#initializer#>;
}

template<typename T>
bool NodeIterator<T>::operator!=(const T &data) {
    return false;
}

template<typename T>
void NodeIterator<T>::setCurrentNode() {

}

template<typename T>
T &NodeIterator<T>::getData() {
    return <#initializer#>;
}

template<typename T>
void NodeIterator<T>::getNext() {

}

template<typename T>
void NodeIterator<T>::getPrevious() {

}
