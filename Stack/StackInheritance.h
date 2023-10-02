//
// Created by Marthel Rodriguez on 10/2/23.
//

#ifndef SPLIT_STACKINHERITANCE_H
#define SPLIT_STACKINHERITANCE_H

#include "../LinkedList/LinkedList.h"

template<typename T>
class StackInheritance : LinkedList<T> {
private:

public:
    StackInheritance();
    //pops the front node,
    void pop();
    //push a new node to the stack.
    void push(const T &data);
    //returns the total number of nodes in the stack.
    using LinkedList<T>::size;
    //returns if the stack is empty or not.
    using LinkedList<T>::empty;
    //return the front node's data
    T &top();
    //using keyword: makes a private inherited function to a public one.

    /**
     * things to consider with a linked list:
     * - stick with head as the top.
     * - push whether we push to end or beggining.
     * -
     * -
     * */
};
#include "StackInheritance.cpp"
#endif //SPLIT_STACKINHERITANCE_H
