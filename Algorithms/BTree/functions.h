//
// Created by Marthel Rodriguez on 11/8/23.
//

#ifndef SPLIT_FUNCTIONS_H
#define SPLIT_FUNCTIONS_H
#include <string>
#include <map>
#include <vector>
#include "BTree.h"

/**
 * done*/
void makeTree(BTree<int> &tree);
int firstGet(BTree<int> &tree, int value);
void printBTree(BTree<int> *tree);
int *find(BTree<int> *tree, int value);

/**
 * TODOs
 **/

//takes care of excess, calls looseInsert and inside.
//it will iterate looseInsert as many times as it wants.
//non-recursive function
void insertValue(BTree<int> *tree, int value);

//just inserts value, that's it, it's a recursive function
BTree<int> *looseInsertValue(BTree<int> *tree, int value);



//fixExcess: organize the tree in the proper way. check this in class.
void fixExcess(BTree<int> *tree);

//
void removeValue(BTree<int> *tree, int target);
#endif //SPLIT_FUNCTIONS_H
