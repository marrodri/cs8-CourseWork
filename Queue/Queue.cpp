//
// Created by Marthel Rodriguez on 10/3/23.
//
#ifndef SPLIT_QUEUE_CPP
#define SPLIT_QUEUE_CPP
#include "Queue.h"

/**
 * Constructor
 * */
template<typename T>
Queue<T>::Queue(){}

/**
 * Functions
 * */
template<typename T>
void Queue<T>::enqueue(const T &value) {
    queue.push_back(value);
}

template<typename T>
void Queue<T>::dequeue() {
    queue.pop_front();
}

template<typename T>
T &Queue<T>::front() {
    return queue.front();
}

template<typename T>
T &Queue<T>::rear() {
    return queue.back();
}

template<typename T>
bool Queue<T>::empty() {
    return false;
}

/**
 * operator  <<
 * */
template<typename T>
std::ostream &operator<<(std::ostream &out, const Queue<T> &queue){
    out << queue.queue;
    return out;
}

/**
 * Big 3
 * */

//template<typename T>
//Queue<T>::~Queue() {
//    delete *this;
//}

template<typename T>
Queue<T>::Queue(const Queue<T> &queueCopy) {
    *this = queueCopy;
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &passedQueue) {
        this->queue = passedQueue.queue;
        return *this;
}

#endif




