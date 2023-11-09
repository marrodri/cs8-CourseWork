//
// Created by Marthel Rodriguez on 11/7/23.
//

#ifndef SPLIT_BTREE_H
#define SPLIT_BTREE_H
#include <vector>
#include <iostream>
#include <string>
//Check the text for learning more about BTrees.

template<typename T, int MAX=2>
class BTree {
public:
    int data_count =0;
    int child_count =0;
    int size = MAX;
    T data[MAX+1];
    BTree<T> * subset[MAX+2];
};


//bring the max to 4 when need to test the firstGet indepth

#endif //SPLIT_BTREE_H
