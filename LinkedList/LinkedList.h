//
// Created by Marthel Rodriguez on 9/25/23.
//

#ifndef SPLIT_LINKEDLIST_H
#define SPLIT_LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include "NodeIterator.h"
//template function
template<typename T>
class LinkedList {
private:
    Node<T> *head = nullptr, *tail=nullptr;
    //_name for preventing overlap with size();
    int _size = 0;

    /*
     * Private Class functions
     * */
    Node<T> *createNode(const T& item);
    void addFirstNode(const T& item);
    void push_front(Node<T>* item);
    void push_back(Node<T> * item);
    void insertAfter(Node<T> * ref, const T& afterThis);
    void insertBefore(Node<T> * ref, const T& beforeThis);
    void incrementListFromHead();

//    void remove();

    //rule pf thumb: if a function is just used inside the class, make it private!!!!
public:
    /**
     * *constructors
     * */
    LinkedList();

    /**
     * iterator (this is new!!!)
     * */
    typedef  NodeIterator<T> iterator;
//    typedef  ConstNodeIterator<T> const_iterator;
//    typedef  NodeReverseIterator<T> reverse_iterator;
    iterator begin(); //return NodeIterator(head);
    iterator end(); //return NodeIterator(tail);
    iterator begin() const; //return NodeIterator(head);
    iterator end() const; //return NodeIterator(tail);
//    const_iterator cbeing(); // return a const NodeIterator(head);
//    const_iterator cend();  // return a const NodeIterator(tail);
//      reverse_iterator rbegin();  //
//      reverse_iterator rend();    //

     /**
     * Class Functions
     **/
    void push_front(const T& item); //add item to the front of the list
    void push_back(const T& item); //add item to the back of the list.
    void remove(const T& item); //remove first instance of the item in the list.
    void pop_front(); //remove the node located in the front of the list.
    void pop_back(); //remove the node located in the back of the list.
    void insertAfter(const T& ref, const T& afterThis);  //
    void insertBefore(const T& ref, const T& beforeThis); //

    Node<T> *find(const T& ref);

    /**
     * Getters
     **/
    int size(); //returns the size of the list.
    const T& front() const; //returns the reference of the item in the front
    const T& back() const; //returns the reference of the item in the back
    bool empty();
    //const at beggining: the returned item cannot be modified.
    //const at end: no instruction inside the function that will modify any of the member variables.

    /**
     * Printers
     **/
    void printListFromHead() const;
    void printListFromTail() const;

    /**
     * operator overload
     **/
    template<typename S>
    friend std::ostream &operator<<(std::ostream &out, const LinkedList<S> &list);

    /**
     * big 3 operators
     * */
    ~LinkedList();
    LinkedList(const LinkedList<T> &linkedList);
    LinkedList<T> &operator=(const LinkedList<T> &linkedList);

};

#include "LinkedList.cpp"

#endif //SPLIT_LINKEDLIST_H

