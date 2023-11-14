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
}

/**
 * private helpers
 **/

template<typename T>
Node<T> *BinarySearchTree<T>::createNode(const T &item) {
    Node<T> *newNode = new Node<T>;
    newNode->data = item;
    return newNode;
}

/**
 * binary search tree functions
**/

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

//public method
template<typename T>
bool BinarySearchTree<T>::search(const T &item) {
    return search(root, item);
}

//private method
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
 * bst iterator
**/
template<typename T>
void BinarySearchTree<T>::iterateBinaryTree(void (*f)(T &), TreeTraversalEnum treeTraversal) {
    switch(treeTraversal){
    case PREORDER:
        preorderIterator(f, root);
        break;
    case POSTORDER:
        postorderIterator(f, root);
        break;
    case INORDER:
        inorderIterator(f, root);
        break;
    default:
        breathFirstOrderTraversal(f, root);
        break;
    }
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
                postorderIterator(f,curr->previous);
            }

            if (curr->next) {
                postorderIterator(f,curr->next);
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
                preorderIterator(f,curr->previous);
            }
            if (curr->next) {
                preorderIterator(f,curr->next);
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
void BinarySearchTree<T>::breathFirstOrderTraversal(void (*f)(T &), Node<T> *root) {
    std::queue<Node<T>*> queue;
    Node<T> *current;
    if (!root){
        return ;
    }
    if (!root->next && !root->previous) {
        f(root->data);
        return ;
    }
    queue.push(root);
    while(!queue.empty()){
        current = queue.front();
        queue.pop();
        f(current->data);
        if(current->previous){
            queue.push(current->previous);
        }
        if(current->next){
            queue.push(current->next);
        }
    }
}



/**
 * big 3 helper functions
 * */

template<typename T>
Node<T> *BinarySearchTree<T>::preorderTreeCopy(Node<T> *node){
    //TODO: create the preorderCopyTree
    Node<T> *newNode = new Node<T>;
    if (!node->previous && !node->next) {
        newNode->data = node->data;
        return  newNode;
    }
    if(node) {
        {
            newNode->data = node->data;
            if (node->previous) {
                newNode->previous=preorderTreeCopy(node->previous);
            }
            if (node->next) {
                newNode->next=preorderTreeCopy(node->next);
            }
        }
    }
    return newNode;
}


template<typename T>
void BinarySearchTree<T>::postorderTreeDestructor(Node<T> *node) {
    if(node){
        if (!node->previous && !node->next) {
            node->data = 0;
            delete(node);
            node= nullptr;
            return ;
        }
        else {
            {
                if (node->previous) {
                    postorderTreeDestructor(node->previous);
                }

                if (node->next) {
                    postorderTreeDestructor(node->next);
                }
                node->data = 0;
                delete(node);
                node= nullptr;
            }
        }
    }
}

/**
 * operator overload.
 * */

template<typename T>
BinarySearchTree<T> &BinarySearchTree<T>::operator+=(const T&data){
    this->addNodeToTree(root,data);
    return *this;
}

/**
 * big 3 methods
 * */
//copy constructor.
template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &binarySearchTree) {
    *this = binarySearchTree;
}

template<typename T>
void deleteNode(Node<T> &node){
    delete(node);
    node = nullptr;

}
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
//    postorderIterator(deleteNode,root);
    if(root){
        postorderTreeDestructor(root);
    }
    this->root = nullptr;
    this->size =0;
}

template<typename T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree<T> &binarySearchTree) {
//    this->~BinarySearchTree();
    //use preorder traversal for copying the bst.
    this->root = preorderTreeCopy(binarySearchTree.root);
    this->size = binarySearchTree.size;
    return *this;
}

#endif
