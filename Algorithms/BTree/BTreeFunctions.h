//
// Created by Marthel Rodriguez on 11/8/23.
//

#ifndef SPLIT_BTREEFUNCTIONS_H
#define SPLIT_BTREEFUNCTIONS_H

#include "BTree.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>

typedef std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> dataMap;

void maketree(BTree<int> &tree, std::vector<int> data,
              std::vector<std::vector<int>> childData, int size);
void print(BTree<int>& tree, int depth);

void maketree(BTree<int> &tree, dataMap data, std::pair<int, int> current);
BTree<int> createTree();
void f();

#endif //SPLIT_BTREEFUNCTIONS_H
