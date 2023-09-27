//
// Created by Marthel Rodriguez on 9/21/23.
//

#ifndef SPLIT_ARRAY_H
#define SPLIT_ARRAY_H

#include <iostream>
#include <string>
//multiple template params. Is it possible to define a class.
//with with 1 required param and another with 3 required params.


//Answer:
//this is class polimorphism.
template<class T, int size>
class Array {
private:
    /*test:*/
public:
    T arr[size];
    void fill(T num);
    T &at(int pos);
    void print();


    template<typename U,int _size>
    friend std::ostream &operator<<(std::ostream &out, const Array<U,_size> &arr);
};


#include "Array.cpp"

#endif //SPLIT_ARRAY_H
