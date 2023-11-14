//
// Created by Marthel Rodriguez on 11/14/23.
//


#ifndef SPLIT_BTREE_CPP
#define SPLIT_BTREE_CPP
#include "BTree.h"


template<typename T, int MAX>
BTree<T, MAX>::BTree() {

}

/**
 * public methods
 * */

//dummy constructor tree.
template<typename T, int MAX>
void BTree<T, MAX>::makeTree() {
    //dummy tree based from pg 16.
    btRoot = new BTreeNode<int,MAX>;
    btRoot->data[0]=100;
    btRoot->data[1]=500;
    btRoot->data_count =2;
    btRoot->subset[0] = new BTreeNode<int>;
    btRoot->subset[1] = new BTreeNode<int>;
    btRoot->subset[2] = new BTreeNode<int>;
    btRoot->child_count = 3;

    /**first depth level, left child*/
    BTreeNode<int, MAX>* firstDepthLeftChildPointer = btRoot->subset[0];
    firstDepthLeftChildPointer->data[0]=50;
    firstDepthLeftChildPointer->data[1]=75;
    firstDepthLeftChildPointer->data_count=2;
    firstDepthLeftChildPointer->child_count=3;

    //3 child for the firstDepthLevel
    firstDepthLeftChildPointer->subset[0] = new BTreeNode<int>;
    firstDepthLeftChildPointer->subset[1] = new BTreeNode<int>;
    firstDepthLeftChildPointer->subset[2] = new BTreeNode<int>;

    //second level children of firstDepthLeftChild.
    BTreeNode<int> *leftSecondLevelFirstChild = firstDepthLeftChildPointer->subset[0];
    BTreeNode<int> *leftSecondLevelSecondChild = firstDepthLeftChildPointer->subset[1];
    BTreeNode<int> *leftSecondLevelThirdChild = firstDepthLeftChildPointer->subset[2];

    leftSecondLevelFirstChild->data[0] = 25;
    leftSecondLevelFirstChild->data_count=1;
    leftSecondLevelSecondChild->data[0]=60;
    leftSecondLevelSecondChild->data_count=1;
    leftSecondLevelThirdChild->data[0]=90;
    leftSecondLevelThirdChild->data_count=1;


    //firstDepthMidChildPointer
    BTreeNode<int, MAX> *firstDepthMidChildPointer = btRoot->subset[1];
    firstDepthMidChildPointer->data[0]=200;
    firstDepthMidChildPointer->data_count=1;
    firstDepthMidChildPointer->child_count=2;

    //    2child for the firstDepthMidChildPointer
    firstDepthMidChildPointer->subset[0] = new BTreeNode<int>;
    firstDepthMidChildPointer->subset[2] = new BTreeNode<int>;

    //second level children of firstDepthMidChildPointer.
    BTreeNode<int> *midSecondLevelFirstChild = firstDepthMidChildPointer->subset[0];
    BTreeNode<int> *midSecondLevelThirdChild = firstDepthMidChildPointer->subset[2];

    midSecondLevelFirstChild->data[0] = 150;
    midSecondLevelFirstChild->data_count =1;
    midSecondLevelThirdChild->data[0]=250;
    midSecondLevelThirdChild->data_count=1;

    //firstDepthLeftChildPointer
    BTreeNode<int> *firstDepthRightChildPointer =  btRoot->subset[2];
    firstDepthRightChildPointer->data[0]=700;
    firstDepthRightChildPointer->data[1]=900;
    firstDepthRightChildPointer->data_count=2;
    firstDepthRightChildPointer->child_count=3;

    //3child for the thirdChild(1st level) right.
    firstDepthRightChildPointer->subset[0] = new BTreeNode<int>;
    firstDepthRightChildPointer->subset[1] = new BTreeNode<int>;
    firstDepthRightChildPointer->subset[2] = new BTreeNode<int>;

    BTreeNode<int> *rightSecondLevelFirstChild = firstDepthRightChildPointer->subset[0];
    BTreeNode<int> *rightSecondLevelSecondChild = firstDepthRightChildPointer->subset[1];
    BTreeNode<int> *rightSecondLevelThirdChild = firstDepthRightChildPointer->subset[2];

    rightSecondLevelFirstChild->data[0]=600;
    rightSecondLevelFirstChild->data_count = 1;
    rightSecondLevelSecondChild->data[0]=800;
    rightSecondLevelSecondChild->data_count=1;
    rightSecondLevelThirdChild->data[0]=1000;
    rightSecondLevelThirdChild->data_count=1;
    /**second depth Level*/
}

template<typename T, int MAX>
int BTree<T, MAX>::firstGet(BTreeNode<T> *btNode,T value) {
    if(value <= btNode->data[0]){
        return 0;
    }
    for(int i = 1; i < btNode->size && i < btNode->data_count;i++){
        if(btNode->data[i-1] < value && value <= btNode->data[i]){
            return i;
        }
    }
    //check for a final value.
    return (btNode->size);
}

template<typename T, int MAX>
void BTree<T, MAX>::printBTree() {
    //print the last subtree.
    printBTree(btRoot->subset[btRoot->size]);
    for (int i = btRoot->size - 1; i >= 0; i--) {
        //if(the index is in the range of data_count, print)
        if (i < btRoot->data_count) {
            std::cout << btRoot->data[i] <<" ";
        }
        printBTree(btRoot->subset[i]);
    }
    std::cout << std::endl;
}

template<typename T, int MAX>
T *BTree<T, MAX>::find(T value){
    return find(btRoot, value);
}

//private recursive find
template<typename T, int MAX>
T *BTree<T, MAX>::find(BTreeNode<T> *btChild,T value) {
    int i = firstGet(btChild, value);
    bool found = (value == btChild->data[i]);
    if(found) {
        //if found is true, then return the address of data[i]
        return &btChild->data[i];
    }
    //otherwhise, if this is a leafnode return null.
    else if (!btChild->subset[i]) {
        return nullptr;
    }
    else {
        //otherwise again, return find(tree->subset[i]);
        return find(btChild->subset[i],value);
    }
}


template<typename T, int MAX>
void BTree<T, MAX>::insertValue(T value) {
    btRoot = insertValue(btRoot, value);
}

/**
 * private recursive functions
 **/
template<typename T, int MAX>
void BTree<T, MAX>::printBTree(BTreeNode<T> *btChild) {
    if(btChild){
        //print the last subtree.
        printBTree(btChild->subset[btChild->size]);
        for(int i = btChild->size - 1; i >=0;i--){
            //if(the index is in the range of data_count, print)
            if (i < btChild->data_count) {
                std::cout << btChild->data[i] << " ";
            }
            printBTree(btChild->subset[i]);
        }
    }
}



template<typename T, int MAX>
BTreeNode<T> * BTree<T, MAX>::insertValue(BTreeNode<T> *btChild, T value) {
//looseInsertRecursively to add the node.
    btRoot = looseInsertValue(btChild, value);
    //then fix its excess to balance the tree.

//    fixExcess(bt);
    return btRoot;
}


template<typename T, int MAX>
BTreeNode<T> *BTree<T, MAX>::looseInsertValue(BTreeNode<T> *btChild, T value) {
    int index = firstGet(btChild, value);
    bool found = (btChild->data[index] == value);
    if (!found) {
        // if node is leaf
        if (btChild->child_count == 0) {
            // insert the item. if the data is full, create a child, in the
            //right index, and add it in the new child.
            if (btChild->data_count < btChild->size){
                //if the desired value is lower than the current value.
                //shift the current value to left, and add the desired
                //value to the current index.
                if(btChild->data[index] > value){
                    btChild->data[index+1] = btChild->data[index];
                    btChild->data[index] = value;
                }
                //another edge case added.
                else if(index == btChild->size){
                    btChild->data[btChild->data_count] = value;
                }
                //otherwise just add it as how it is.
                else{
                    btChild->data[index] = value;
                }
                btChild->data_count++;
            }
            return btChild;
        }else{
            btChild->subset[index] = looseInsertValue(btChild->subset[index],value);
        }
    }
    return btChild;
}



#endif