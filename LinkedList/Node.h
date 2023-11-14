//
// Created by Marthel Rodriguez on 9/26/23.
//

#ifndef SPLIT_NODE_H
#define SPLIT_NODE_H


//doubly linked list.
template<typename T>
struct Node {
    T data;
    Node<T> *previous = nullptr, *next = nullptr;
};

#endif //SPLIT_NODE_H
