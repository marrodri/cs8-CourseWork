//
// Created by Marthel Rodriguez on 10/3/23.
//

#ifndef SPLIT_QUEUE_H
#define SPLIT_QUEUE_H
#include "../LinkedList/LinkedList.h"

template<typename T>
class Queue {
private:
    //
    LinkedList<T> queue;
public:
    //
    Queue();
    void enqueue(const T& value);
    void dequeue();

    //getters
    T &front();
    T &rear();
    bool empty();
    /**
     * operator overload
     **/
    template<typename S>
    friend std::ostream &operator<<(std::ostream &out, const Queue<S> &queue);

    /**
     * big 3 operators
     * */
//    ~Queue();
    Queue(const Queue<T> &queueCopy);
    Queue<T> &operator=(const Queue<T> &passedQueue);
};

#include "Queue.cpp"

#endif //SPLIT_QUEUE_H
