//
// Created by Marthel Rodriguez on 10/10/23.
//

#ifndef SPLIT_NODEREVERSEITERATOR_H
#define SPLIT_NODEREVERSEITERATOR_H
#include "Node.h"
template<typename T>
class NodeReverseIterator {
private:
    Node<T> *current;
public:
    //    NodeIterator();
    NodeReverseIterator(Node<T>*current = nullptr); // one line code

    /**
    * postfix: ++int
    * ++x -> increment x; return x;
    */
    NodeReverseIterator<T> operator++(int); //two lines

    /**
     * prefix: int++
     * x++ -> copy x; then increment x;
     * then return copy.
     */
    NodeReverseIterator<T> &operator++(); //one line or two line

    /*
     * decrementors*/
    NodeReverseIterator<T> operator--(int); //
    NodeReverseIterator<T> &operator--(); //

    //deference
    T &operator *();


    NodeReverseIterator<T> operator+=(int add);
    NodeReverseIterator<T> operator-=(int subtract);
    NodeReverseIterator<T> operator+(int add);

    const T &operator*() const;

    template<typename U>
    friend bool operator!=(const NodeReverseIterator<U> &rhs, const NodeReverseIterator<U> &lhs);

    template<typename U>
    friend bool operator==(const NodeReverseIterator<U> &rhs, const  NodeReverseIterator<U> &lhs);
};

#include "NodeReverseIterator.cpp"
#endif //SPLIT_NODEREVERSEITERATOR_H
