//
// Created by Marthel Rodriguez on 10/23/23.
//

#ifndef SPLIT_BINARYSEARCHTREE_H
#define SPLIT_BINARYSEARCHTREE_H

#include "../../LinkedList/Node.h"
#include <iostream>
template<typename T>
class BinarySearchTree {
private:
    Node<T> *root;
    int size;
    // -node->prev: left, node->next: right.
    // -each node has its own depth.
    // -the three has its max depth.
    // -check more about the depth of the trees.

    //breath order
    //dfs
    //bfs

    //balance tree function().

    //terms to search:
    // - full tree.
    // - complete tree.
    //NOTE: these are completely different terms.!!
    Node<T> * addNodeToTree(Node<T> *node,const  T &val);
    Node<T> *createNode(const T &item);


    /**
     * private traversal functions
     **/
    void    postorderIterator(void(*f)(T& data), Node<T> *curr);
    void    preorderIterator(void(*f)(T& data), Node<T> *curr);
    void    inorderIterator(void(*f)(T& data), Node<T> *curr); //DONE
    Node<T> *remove(Node<T> *curr, T data);
public:
    BinarySearchTree();

    /**
     * base tree function.
     **/
    void addValueToTree(const T &item);
    int getSize(); //TODO
    int getDepth(); //TODO

    /**
     * queue algorithms
     **/
    /**
    * bst header from dave smith class
    **/
    void breathFirstOrderTraversal();
    void depthFirstOrderTraversal();

    /**
     * tree iterators.
     **/
    void inorderIterator(void(*f)(T& data));
    void postorderIterator(void(*f)(T& data));
    void preorderIterator(void(*f)(T& data));

    /**
     * remove node.
     **/
    void remove(T data);

    /*if is leaf, delete
     * --otherwise, node has 1 child; swap with child.
     *    then call remove(child);
     * --else node has z children;swap with
     *    next successor. call remove under successor.
     * **/
};

//   --kuaijie = "see you soon";
#include "BinarySearchTree.cpp"
#endif //SPLIT_BINARYSEARCHTREE_H
