//
// Created by Marthel Rodriguez on 10/10/23.
//

#ifndef SPLIT_CONSTNODEITERATOR_H
#define SPLIT_CONSTNODEITERATOR_H
#include "Node.h"
#include <iterator>

template<typename T>
class ConstNodeIterator : public std::iterator<std::bidirectional_iterator_tag, T>   {
private:
    const Node<T> *current;
    //hide the walker, and iterate through the list without exposing the node.
public:
    ConstNodeIterator(const Node<T>*current = nullptr); // one line code
    /**
    * postfix: ++int
    * ++x -> increment x; return x;
    */
    const ConstNodeIterator<T> operator++(int) const; //two lines

    /**
     * prefix: int++
     * x++ -> copy x; then increment x;
     * then return copy.
     */
    ConstNodeIterator<T> &operator++(); //one line or two line

    /*
     * decrementors*/
    const ConstNodeIterator<T> operator--(int) const; //
    ConstNodeIterator<T> &operator--() const; //

    //deference
//    T &operator *();

    /**TODOs*/
    ConstNodeIterator<T> operator+=(int add);
    ConstNodeIterator<T> operator-=(int subtract);
    ConstNodeIterator<T> operator+(int add);

    const T &operator*() const;

    /**DONE*/
    template<typename U>
    friend bool operator!=(const ConstNodeIterator<U> &rhs, const ConstNodeIterator<U> &lhs);

    template<typename U>
    friend bool operator==(const ConstNodeIterator<U> &rhs, const  ConstNodeIterator<U> &lhs);
};


#endif //SPLIT_CONSTNODEITERATOR_H
