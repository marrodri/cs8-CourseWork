//
// Created by Marthel Rodriguez on 10/23/23.
//

#ifndef SPLIT_BINARYSEARCHTREE_H
#define SPLIT_BINARYSEARCHTREE_H

#include "../../LinkedList/Node.h"
#include <iostream>
#include <queue>
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
    //dfs.
    //bfs.

    //balance tree function().

    //terms to search:
    // - full tree.
    // - complete tree.
    //NOTE: these are completely different terms.!!

    /**
     * private helper methods
     **/
    Node<T> *createNode(const T &item);

    /**
     * private recursive BST functions
     * */
    Node<T> *addNodeToTree(Node<T> *node,const  T &val);
    bool    search(Node<T> *curr, const T &item);
    Node<T> *remove(Node<T> *curr, T data);


    /**
     * private traversal recursive functions
     **/
    void    postorderIterator(void(*f)(T& data), Node<T> *curr);
    void    preorderIterator(void(*f)(T& data), Node<T> *curr);
    void    inorderIterator(void(*f)(T& data), Node<T> *curr); //DONE
    void    breathFirstOrderTraversal(void(*f)(T& data), Node<T> *curr);
public:
    BinarySearchTree();

    /**
     * public BST functions.
     **/
    void addValueToTree(const T &item);
    int getSize(); //TODO. Last
    int getDepth(); //TODO. Last
    void remove(T data);
    bool search(const T &item);

    /**
     * tree iterators.
     **/
    void inorderIterator(void(*f)(T& data));
    void postorderIterator(void(*f)(T& data));
    void preorderIterator(void(*f)(T& data));
    void breathFirstOrderTraversal(void(*f)(T& data)); //TODO IMPORTANT

    /**
     * big 3 TODO IMPORTANT
     * */
//     copy constructor (use preorder traversal)
//      destructor (use postorder traversal)
//      assignment operator
};

//   --kuaijie = "see you soon";
#include "BinarySearchTree.cpp"
#endif //SPLIT_BINARYSEARCHTREE_H
