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


//bool found. when data[i] == entry. and i is lower than size.

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



/**
 * array functions
 * */
 void shiftLeft(int *arr[]);
 void shiftRight(int *arr[]);


 //array functions to define.
 //split data: divide the array by 2, and take the first half ...
// insert:()
// remove:()

//bring the middle guy up, and keep the other data in the child.
//just use the same array functions from the library.

//
void removeValue(BTree<int> *tree, int target);
#endif //SPLIT_FUNCTIONS_H
