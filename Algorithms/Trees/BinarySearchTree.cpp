//
// Created by Marthel Rodriguez on 10/23/23.
//
#ifndef SPLIT_BINARYSEARCHTREE_CPP
#define SPLIT_BINARYSEARCHTREE_CPP

#include "BinarySearchTree.h"

/**
 * constructors
 **/

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
    size = 0;
    /**
     * -
     * -
     * -
     * -
     **/
}

/**
 * private helpers
 * */
template<typename T>
Node<T> *BinarySearchTree<T>::createNode(const T &item) {
    Node<T> *newNode = new Node<T>;
    newNode->data = item;
    return newNode;
}

/**
 * binary search tree functions
 * */

//public method
template<typename T>
void BinarySearchTree<T>::addValueToTree(const T &item) {
    root = addNodeToTree(root,item);
    size++;
}

//private method
template<typename T>
Node<T> *BinarySearchTree<T>::addNodeToTree(Node<T> *node,const T &val) {
    if (!node) {
        return createNode(val);
    }
    else if (node->data > val) {
        // curr->previous is curr->left;
        std::cout << "going left!\n";
        node->previous= addNodeToTree(node->previous, val);
    }
    else {
        // curr->next is curr->right;
        std::cout << "going right!\n";
        node->next= addNodeToTree(node->next, val);
    }
    return node;
}


//public method
template<typename T>
void BinarySearchTree<T>::remove(T data) {
//    root=
    root=remove(root, data);
    size--;
}

//private method
template<typename T>
Node<T> *BinarySearchTree<T>::remove(Node<T> *curr, T data){
    T tmpVal;
    if(!curr){
        return nullptr;
    }
    if (curr->data == data) {
        if (!curr->previous && !curr->next) {
            delete(curr);
            curr = nullptr;
            return curr;
        }else{
            //swap
            if(curr->next) {
                //swap with left children;
                //tmpVal is child.
                tmpVal = curr->next->data;
                //now child has the value to delete.
                curr->next->data = curr->data;
                //now curr has
                curr->data = tmpVal;
                curr->next = remove(curr->next, data);
            }
            else if(curr->previous) {
                //swap with left children;
                //swap with left children;
                //tmpVal is child.
                tmpVal = curr->previous->data;
                //now child has the value to delete.
                curr->previous->data = curr->data;
                //now curr has
                curr->data = tmpVal;
                curr->previous = remove(curr->previous, data);
            }
        }
    }
    else{
        if(curr->data < data){

            curr->next = remove(curr->next, data);
        }
        else {
            curr->previous = remove(curr->previous, data);
        }
    }
    return curr;
}

//TODO public method
template<typename T>
bool BinarySearchTree<T>::search(const T &item) {
    return search(root, item);
}

//TODO: private method
template<typename T>
bool BinarySearchTree<T>::search(Node<T> *curr, const T &item) {
    bool isFounded = false;
    if(curr->data == item){
        return true;
    }
    if (!curr->previous && !curr->next) {
        return false;
    }
    if(curr) {
        {
//            isFounded = search(curr, item);
            if (curr->previous && !isFounded) {
                isFounded = search(curr->previous, item);
            }
            if (curr->next && !isFounded) {
                isFounded = search(curr->next, item);
            }
        }
    }
    return isFounded;
}


/**
 * bst traversal functions
**/

template<typename T>
void BinarySearchTree<T>::postorderIterator(void(*f)(T& data)) {
    std::cout << "calling infix traversal tree\n";
    this->postorderIterator(f, root);
}

template<typename T>
void BinarySearchTree<T>::preorderIterator(void(*f)(T& data)) {
    std::cout << "calling infix traversal tree\n";
    this->preorderIterator(f, root);
}

template<typename T>
void BinarySearchTree<T>::inorderIterator(void(*f)(T& data)) {
    std::cout << "calling infix traversal tree\n";
    this->inorderIterator(f, root);
}


/*
 * binary search tree algorithms
 * */

template<typename T>
void BinarySearchTree<T>::breathFirstOrderTraversal(void(*f)(T& data)) {
    breathFirstOrderTraversal(f, root);
}




/**
 * private traversal functions
 **/

template<typename T>
void BinarySearchTree<T>::postorderIterator(void(*f)(T& data), Node<T> *curr) {
    if (!curr->previous && !curr->next) {
        f(curr->data);
        return ;
    }
    if(curr) {
        {
            if (curr->previous) {
                postfixIterator(f,curr->previous);
            }

            if (curr->next) {
                postfixIterator(f,curr->next);
            }
            f(curr->data);
        }
    }
}

template<typename T>
void BinarySearchTree<T>::preorderIterator(void(*f)(T& data), Node<T> *curr) {
    if (!curr->previous && !curr->next) {
        f(curr->data);
        return ;
    }
    if(curr) {
        {
            f(curr->data);
            if (curr->previous) {
                prefixIterator(f,curr->previous);
            }
            if (curr->next) {
                prefixIterator(f,curr->next);
            }
        }
    }
}

template<typename T>
void BinarySearchTree<T>::inorderIterator(void(*f)(T& data), Node<T> *curr) {
    if (!curr->previous && !curr->next) {
        f(curr->data);
        return ;
    }
    if(curr) {
        {
            if (curr->previous) {
                inorderIterator(f,curr->previous);
            }
            f(curr->data);
            if (curr->next) {
                inorderIterator(f,curr->next);
            }
        }
    }
}

template<typename T>
void BinarySearchTree<T>::breathFirstOrderTraversal(void (*f)(T &), Node<T> *curr) {

}



/*if is leaf, delete
     * --otherwise, node has 1 child; swap with child.
     *    then call remove(child);
     * --else node has z children;swap with
     *    next successor. call remove under successor.
     * **/



#endif
