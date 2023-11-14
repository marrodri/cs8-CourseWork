//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SPLIT_BTREENODE_H
#define SPLIT_BTREENODE_H

template<typename T, int MAX=2>
struct BTreeNode {
        int data_count = 0;
        int child_count = 0;
        int size = MAX;
        T data[MAX+1];
        BTreeNode<T> * subset[MAX+2];
};

#endif //SPLIT_BTREENODE_H
