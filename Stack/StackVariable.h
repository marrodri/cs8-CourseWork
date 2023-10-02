//
// Created by Marthel Rodriguez on 10/2/23.
//

#ifndef SPLIT_STACKVARIABLE_H
#define SPLIT_STACKVARIABLE_H

#include "../LinkedList/LinkedList.h"
template<typename T>
class StackVariable {
public:
    LinkedList<T> stack;
private:
    StackVariable();
    //pops the front node,
    void pop();
    //push a new node to the stack.
    void push(const T &data);
    //returns the total number of nodes in the stack.
    void size();
    //returns if the stack is empty or not.
    bool empty();
    //return the front node's data
    T &top();
    //using keyword: makes a private inherited function to a public one.

};

#include "StackVariable.cpp"
#endif //SPLIT_STACKVARIABLE_H
