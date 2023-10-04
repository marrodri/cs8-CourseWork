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
    NodeIterator();
    NodeIterator(Node<T>*current = nullptr); // one line code
    /**
    * postfix: ++int
    * ++x -> increment x; return x;
    */
    NodeIterator<T> &operator++(int); //two lines

    /**
     * prefix: int++
     * x++ -> copy x; then increment x;
     * then return copy.
     */
    NodeIterator<T> operator++(); //one line or two line

    /*
     * decrementors*/
    NodeIterator<T> operator--(int); //
    NodeIterator<T> &operator--(); //


    //deference
    T &operator *();
    const T &operator*();


    //getters.
    /**
     * return the iterator pointing to the
     * beggining of the list.
    */
    T &begin();

    /**
     * return the iterator pointing to the
     * end of the list.
     */
    T&end();

    //!= operator.
    bool operator!=(const T& data);

//    void setCurrentNode();
//    T &getData();
//    void getNext();
//    void getPrevious();
}




#endif //SPLIT_NODEITERATOR_H
