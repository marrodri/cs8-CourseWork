//
// Created by Marthel Rodriguez on 11/1/23.
//

#ifndef SPLIT_HEAPTREE_CPP
#define SPLIT_HEAPTREE_CPP

#include "HeapTree.h"
#include <iostream>
template<typename T>
HeapTree<T>::HeapTree() {

}

template<typename T>
HeapTree<T>::HeapTree(const std::initializer_list<T> &list) {
    for(const T& item : list){
        push(item);
    }
}




/**
 * heap main methods
 * */
template<typename T>
void HeapTree<T>::push(const T&item) {
    //push to the back of the priority queue.
    data.push_back(item);
    //then check if it reheapifyUp or not.
    std::cout << "item pushed, see if it can reheapifyUp:" << item <<"\n";
    //check if the bottom, which is the child index, is lower than
    //the parent, that must go up, because its smaller than parent.
    reheapifyUp(data.size() -1);
}


template<typename T>
void HeapTree<T>::pop() {
    //move the back to the front.
    data[0] = data[data.size()-1];
    data.pop_back();
}


/**
 * private heap methods
 **/

template<typename T>
void HeapTree<T>::reheapifyUp(int childIndex) {
    int parentIndex = getParentIndex(childIndex);
    T tmpData;
    //TODO: build the reheapifyUp funct that is recursive.
    //bottom is the back of the vector.
    if(data[childIndex] <= data[parentIndex]){
        return ;
    }
    else{
        //swap with parent. reheapify with parent index.
        tmpData = data[childIndex];
        data[childIndex] = data[parentIndex];
        data[parentIndex] = tmpData;
        reheapifyUp(parentIndex);
    }
}

template<typename T>
void HeapTree<T>::reheapifyDown(int parentIndex) {
    //TODO: build the reheapifyDown funct that is recursive.

}

/**
 * getters
 * */

template<typename T>
T &HeapTree<T>::top() {
    return data.front();
}

template<typename T>
int HeapTree<T>::size() {
    return data.size();
}

template<typename T>
bool HeapTree<T>::empty() {
    return data.empty();
}


/**
* getIndex methods
* */
template<typename T>
int HeapTree<T>::getParentIndex(int childIndex) {
    /// (childIndex - 1) / 2
    return (childIndex - 1)/2;
}

template<typename T>
int HeapTree<T>::getLeftChildIndex(int parentIndex) {
    /// 2 * parentIndex + 1
    return (2* parentIndex) + 1;
}

template<typename T>
int HeapTree<T>::getRightChildIndex(int parentIndex) {
    /// 2 * parentIndex + 2
    return (2 * parentIndex) + 2;
}

template<typename T>
int HeapTree<T>::getGreaterChildIndex(int parentIndex) {
    int leftChildIndex = getLeftChildIndex(parentIndex);
    int rightChildIndex = getRightChildIndex(parentIndex);
    if (data[leftChildIndex] >= data[rightChildIndex]) {
        return leftChildIndex;
    }
    else{
        return rightChildIndex;
    }
}

/**
 * helper function
 * */
 template<typename T>
 void HeapTree<T>::printHeap() {
     for(T elem:data){
         std::cout << elem <<" ";
     }
     std::cout << "\n";
 }

#endif