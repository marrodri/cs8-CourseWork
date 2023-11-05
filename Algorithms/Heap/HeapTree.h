//
// Created by Marthel Rodriguez on 11/1/23.
//

#ifndef SPLIT_HEAPTREE_H
#define SPLIT_HEAPTREE_H
#include <vector>
#include <initializer_list>

/**
 * Description:
 * - a balance binary tree where the root holds
 * the largest value. and every parent
 * is greater than its children.
 *
 * - use heap for priority queues.
 *
 * - 12, 20, 37, 75, 67, 28, 32, 01, 45.
 *
 * -
 * */

/**
 * - kinda works as a level order tree when pushing
 * and when popping,
 *
 * -
 *
 * -
 *
 **/
template<typename T>
class HeapTree {
private:
    // -this will be used as a priority queue.
    std::vector<T> data;

    //stop when parent if >= child.
    ///otherwise, swap with parent
    ///reheapifyUp(parentIndex), for push.
    void reheapifyUp(int childIndex);

    /**
     * stop when parent is greater than both children.
     * otherwsie, swap parent w/greater child
     * reheapifyDown(greaterChild), for pop()
     * */
    void reheapifyDown(int parentIndex);

    /**
     * getIndex methods
     * */
    int getParentIndex(int childIndex); /// (childIndex - 1) / 2
    int getLeftChildIndex(int parentIndex); /// (2 * parentIndex) + 1
    int getRightChildIndex(int parentIndex); /// 2 * parentIndex + 2
    int getGreaterChildIndex(int parentIndex); ///

public:
    HeapTree();
    HeapTree(const std::initializer_list<T>& list);

    /**
     *
     **/


    //add data to end of vector, reheapifyUp(child);
    void push(const T&item);
    void pop(); //swap with root and back of vector, then reheapifyDown.


    /**
     * getters
     **/
    T& top();
    int size();
    bool empty();

    //if parent >= child: stop.
    //else swap to move up. swap w/ parent
    // - reheapify (parent): this also need to be
    //   private.

    // - parent. this should be a private.
    void printHeap();
};

#include "HeapTree.cpp"


#endif //SPLIT_HEAPTREE_H
