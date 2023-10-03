//
// Created by Marthel Rodriguez on 10/3/23.
//

#ifndef SPLIT_NODEITERATOR_H
#define SPLIT_NODEITERATOR_H

#include "Node.h"

template<typename T>
class NodeIterator{
private:
 Node<T> *current;
 //hide the walker, and iterate through the list without exposing the node.
public:
    void setCurrentNode();
    T &getData();
    void getNext();
    void getPrevious();

    /**
     * int x=5;
     * int *p = &x;
     *
     * */
}




#endif //SPLIT_NODEITERATOR_H
