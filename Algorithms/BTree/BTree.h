//
// Created by Marthel Rodriguez on 11/7/23.
//

#ifndef SPLIT_BTREE_H
#define SPLIT_BTREE_H
#include <vector>
#include <iostream>
#include <string>
//Check the text for learning more about BTrees.

#include "BTreeNode.h"
template<typename T, int MAX=2>
class BTree {
private:
//    int data_count =0;
//    int child_count =0;
//    int size = MAX;
//    T data[MAX+1];
//    BTree<T> * subset[MAX+2];
    BTreeNode<T,MAX> *btRoot;


    /**
     * private recursive functions
     * */
    T *find(BTreeNode<T> *btChild, T value);
    void printBTree(BTreeNode<T> *btChild);
    BTreeNode<T> *insertValue(BTreeNode<T> *btChild, T value);
    BTreeNode<T> *looseInsertValue(BTreeNode<T> *btChild, T value);
public:
    BTree();




    /**
     * migrated functions
     * **/
    void makeTree();
    int firstGet(BTreeNode<T> *btNode, T value);
    void printBTree();
    T *find(T value);
    void insertValue(T value);


    /**
     * TODOs:
     * */
    void fixExcess(BTreeNode<int> *tree);
    /**
     * array helper functions.
     * */


};


//bring the max to 4 when need to test the firstGet indepth
#include "BTree.cpp"
#endif //SPLIT_BTREE_H
