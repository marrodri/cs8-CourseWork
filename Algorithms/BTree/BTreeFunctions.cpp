//
// Created by Marthel Rodriguez on 11/7/23.
//

#include "BTreeFunctions.h"
#include "BTree.h"

/**
 * btree functions
 * */

void maketree(BTree<int> &tree, std::vector<int> data,
              std::vector<std::vector<int>> childData, int size)
{
    for(int i=0; i<size; i++)
    {
        tree.data[i] = data[i];
        tree.subset[i] = new BTree<int>;
    }
    tree.subset[size] = new BTree<int>;
    for (int i = 0; i < size + 1; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            tree.subset[i]->data[j] = childData[i][j];
            tree.subset[i]->data_count = size;
            tree.subset[i]->child_count = 0;
        }
    }
    tree.data_count = size;
    tree.child_count = size + 1;

}
void maketree(BTree<int> &tree, dataMap data, std::pair<int, int> current)
{
    tree.data[0] = current.first;
    tree.data[1] = current.second;
    if(!data[current].empty())
    {
        tree.child_count = data[current].size();
        int i = 0;
        for(auto &p : data[current])
        {
            tree.subset[i] = new BTree<int>;
            maketree(*tree.subset[i++], data, p);
        }

    }

}
BTree<int> createTree()
{
    BTree<int> tree;
    maketree(tree, {50, 100}, {{25, 40}, {60, 80}, {150, 200}}, 2);
    maketree(*tree.subset[0], {25, 40}, {{5, 10}, {30, 35}, {45, 50}}, 2);
    maketree(*tree.subset[1], {60, 80}, {{44, 54}, {66, 77}, {88, 99}}, 2);
    maketree(*tree.subset[2], {150, 200}, {{120, 130}, {160, 170}, {205, 220}}, 2);
    return tree;
}
void f()
{
    dataMap data;
    BTree<int> tree;
    data[{50, 100}] = {{25, 40}, {60, 80}, {150, 200}};
    data[{25, 40}] = {{5, 10}, {30, 35}, {45, 50}};
    data[{60, 80}] = {{44, 54}, {66, 77}, {88, 99}};
    data[{150, 200}] = {{120, 130}, {160, 170}, {205, 220}};
    maketree(tree, data, {50, 100});
    print(tree, 1);
}

void print(BTree<int>& tree, int depth)
{
    if(tree.subset[tree.child_count-1] != nullptr)
        print(*tree.subset[tree.child_count-1], depth+1);
    for(int i=tree.data_count -1; i > -1; i--)
    {
        for(int i=0; i<depth; i++)
            std::cout << "\t";
        std::cout << tree.data[i] << std::endl;
        if(tree.subset[i] != nullptr)
            print(*tree.subset[i], depth+1);
    }

}
