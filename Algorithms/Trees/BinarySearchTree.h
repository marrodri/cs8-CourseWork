//
// Created by Marthel Rodriguez on 10/23/23.
//

#ifndef SPLIT_BINARYSEARCHTREE_H
#define SPLIT_BINARYSEARCHTREE_H

#include "../../LinkedList/Node.h"
#include <iostream>
#include <queue>

enum TreeTraversalEnum{ PREORDER, POSTORDER, INORDER, BREADTHORDER };

template<typename T>
class BinarySearchTree {
private:
    Node<T> *root;
    int size;

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
    Node<T> *preorderTreeCopy(Node<T> *node);
    void postorderTreeDestructor(Node<T> *node);

public:
    BinarySearchTree();

    /**
     * public BST functions.
     **/
    void addValueToTree(const T &item);
    int getSize(); //TODO. Last
    void remove(T data);
    bool search(const T &item);

    /**
     * tree iterators.
     **/
    void iterateBinaryTree(void(*f)(T& data), TreeTraversalEnum treeTraversal);

    /**
     * operator overload
     * */

    BinarySearchTree<T> &operator+=(const T &data);
    /**
     * big 3 TODO IMPORTANT
     * */
     //copy constructor (use preorder traversal)
     BinarySearchTree(const BinarySearchTree<T> &binarySearchTree);
     //destructor (use postorder traversal)
     ~BinarySearchTree();
     //assignment operator
     BinarySearchTree<T> &operator=(const BinarySearchTree<T> &binarySearchTree);
};

//   --kuaijie = "see you soon";
#include "BinarySearchTree.cpp"
#endif //SPLIT_BINARYSEARCHTREE_H
