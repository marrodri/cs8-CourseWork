//
// Created by Marthel Rodriguez on 11/8/23.
//

#include "functions.h"

/**
 * helper function: gets the index that belongs to the range of the input.
 * value should be less or equal to the next index to return its index.
 * otherwise, if the value is the highest among the data, return its size of
 * the data.
 **/
int firstGet(BTree<int> &bTree, int value) {
    if(value <= bTree.data[0]){
        return 0;
    }
    for(int i = 1; i < bTree.size && i < bTree.data_count;i++){
        if(bTree.data[i-1] < value && value <= bTree.data[i]){
            return i;
        }
    }
    //check for a final value.
    return (bTree.size);
}

/**
 * print tree from highest value to lowest value.
 **/
void printBTree(BTree<int> *tree){
    if(tree){
        //print the last subtree.
        printBTree(tree->subset[tree->size]);
        for(int i = tree->size - 1; i >=0;i--){
            //if(the index is in the range of data_count, print)
            if (i < tree->data_count){
                std::cout << tree->data[i] <<" ";
            }
            printBTree(tree->subset[i]);
        }
    }
}


/**
 * find function
 **/
int *find(BTree<int> *tree, int value){
    int i = firstGet(*tree, value);
    bool found = (value == tree->data[i]);
    if(found) {
        //if found is true, then return the address of data[i]
        return &tree->data[i];
    }
    //otherwhise, if this is a leafnode return null.
    else if (!tree->subset[i]) {
        return nullptr;
    }
    else {
        //otherwise again, return find(tree->subset[i]);
        return find(tree->subset[i],value);
    }
}

/**
 * insert function
 **/
void insertValue(BTree<int> *tree, int value) {
    //looseInsertRecursively to add the node.
    tree = looseInsertValue(tree, value);
    //then fix its excess to balance the tree.
    fixExcess(tree);

}

/**
 * fixExcess (currently is a stub funct);
 * */
void fixExcess(BTree<int> *tree){
    std::cout << "fixing excess logic\n";
    return ;
}


BTree<int> *looseInsertValue(BTree<int> *tree, int value) {
    int index = firstGet(*tree, value);
    bool found = (tree->data[index] == value);
    if (!found) {
        // if node is leaf
        if (tree->child_count == 0) {
            // insert the item. if the data is full, create a child, in the
            //right index, and add it in the new child.
            //
            if (tree->data_count < tree->size){


                //if the desired value is lower than the current value.
                //shift the current value to left, and add the desired
                //value to the current index.
                if( tree->data[index] > value){
                    tree->data[index+1] = tree->data[index];
                    tree->data[index] = value;
                }
                //another edge case added.
                else if(index == tree->size){
                    tree->data[tree->data_count] = value;
                }
                //otherwise just add it as how it is.
                else{
                    tree->data[index] = value;
                }
                tree->data_count++;
            }
            return tree;
        }else{
            return looseInsertValue(tree->subset[index],value);
        }
    }
    return tree;
}

/**
 * dummy treemaker
 * */
void makeTree(BTree<int> &tree) {
    //dummy tree based from pg 16.
    tree.data[0]=100;
    tree.data[1]=500;
    tree.data_count =2;
    tree.subset[0] = new BTree<int>;
    tree.subset[1] = new BTree<int>;
    tree.subset[2] = new BTree<int>;
    tree.child_count = 3;

    /**first depth level, left child*/
    BTree<int> *firstDepthLeftChildPointer = tree.subset[0];
    firstDepthLeftChildPointer->data[0]=50;
    firstDepthLeftChildPointer->data[1]=75;
    firstDepthLeftChildPointer->data_count=2;
    firstDepthLeftChildPointer->child_count=3;

    //3 child for the firstDepthLevel
    firstDepthLeftChildPointer->subset[0] = new BTree<int>;
    firstDepthLeftChildPointer->subset[1] = new BTree<int>;
    firstDepthLeftChildPointer->subset[2] = new BTree<int>;

    //second level children of firstDepthLeftChild.
    BTree<int> *leftSecondLevelFirstChild = firstDepthLeftChildPointer->subset[0];
    BTree<int> *leftSecondLevelSecondChild = firstDepthLeftChildPointer->subset[1];
    BTree<int> *leftSecondLevelThirdChild = firstDepthLeftChildPointer->subset[2];

    leftSecondLevelFirstChild->data[0] = 25;
    leftSecondLevelFirstChild->data_count=1;
    leftSecondLevelSecondChild->data[0]=60;
    leftSecondLevelSecondChild->data_count=1;
    leftSecondLevelThirdChild->data[0]=90;
    leftSecondLevelThirdChild->data_count=1;


    //firstDepthMidChildPointer
    BTree<int> *firstDepthMidChildPointer = tree.subset[1];
    firstDepthMidChildPointer->data[0]=200;
    firstDepthMidChildPointer->data_count=1;
    firstDepthMidChildPointer->child_count=2;


    //    2child for the firstDepthMidChildPointer
    firstDepthMidChildPointer->subset[0] = new BTree<int>;
    firstDepthMidChildPointer->subset[2] = new BTree<int>;

    //second level children of firstDepthMidChildPointer.
    BTree<int> *midSecondLevelFirstChild = firstDepthMidChildPointer->subset[0];
    BTree<int> *midSecondLevelThirdChild = firstDepthMidChildPointer->subset[2];

    midSecondLevelFirstChild->data[0] = 150;
    midSecondLevelFirstChild->data_count =1;
    midSecondLevelThirdChild->data[0]=250;
    midSecondLevelThirdChild->data_count=1;


    //firstDepthLeftChildPointer
    BTree<int> *firstDepthRightChildPointer = tree.subset[2];
    firstDepthRightChildPointer->data[0]=700;
    firstDepthRightChildPointer->data[1]=900;
    firstDepthRightChildPointer->data_count=2;
    firstDepthRightChildPointer->child_count=3;

    //3child for the thirdChild(1st level) right.
    firstDepthRightChildPointer->subset[0] = new BTree<int>;
    firstDepthRightChildPointer->subset[1] = new BTree<int>;
    firstDepthRightChildPointer->subset[2] = new BTree<int>;

    BTree<int> *rightSecondLevelFirstChild = firstDepthRightChildPointer->subset[0];
    BTree<int> *rightSecondLevelSecondChild = firstDepthRightChildPointer->subset[1];
    BTree<int> *rightSecondLevelThirdChild = firstDepthRightChildPointer->subset[2];

    rightSecondLevelFirstChild->data[0]=600;
    rightSecondLevelFirstChild->data_count = 1;
    rightSecondLevelSecondChild->data[0]=800;
    rightSecondLevelSecondChild->data_count=1;
    rightSecondLevelThirdChild->data[0]=1000;
    rightSecondLevelThirdChild->data_count=1;
    /**second depth Level*/
}
