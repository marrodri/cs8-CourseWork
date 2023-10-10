//
// Created by Marthel Rodriguez on 10/3/23.
//

#ifndef SPLIT_NODEITERATOR_H
#define SPLIT_NODEITERATOR_H

#include "Node.h"
#include <iterator>
template<typename T>
class NodeIterator: public std::iterator<std::bidirectional_iterator_tag, T> {
private:
 Node<T> *current;
 //hide the walker, and iterate through the list without exposing the node.
public:
    NodeIterator(Node<T>*current = nullptr); // one line code
    /**
    * postfix: ++int
    * ++x -> increment x; return x;
    */
    NodeIterator<T> operator++(int); //two lines

    /**
     * prefix: int++
     * x++ -> copy x; then increment x;
     * then return copy.
     */
    NodeIterator<T> &operator++(); //one line or two line

    /*
     * decrementors*/
    NodeIterator<T> operator--(int); //
    NodeIterator<T> &operator--(); //

    //deference
    T &operator *();

    /**TODOs*/
    NodeIterator<T> operator+=(int add);
    NodeIterator<T> operator-=(int subtract);
    NodeIterator<T> operator+(int add);

    const T &operator*() const;


    /**DONE*/
    template<typename U>
    friend bool operator!=(const NodeIterator<U> &rhs, const NodeIterator<U> &lhs);

    template<typename U>
    friend bool operator==(const NodeIterator<U> &rhs, const  NodeIterator<U> &lhs);

    //!= operator.
    bool operator!=(const T& data);
};

#include "NodeIterator.cpp"


#endif //SPLIT_NODEITERATOR_H
