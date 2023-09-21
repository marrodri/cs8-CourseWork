//
// Created by Marthel Rodriguez on 9/21/23.
//
#ifndef SPLIT_ARRAY_CPP
#define SPLIT_ARRAY_CPP
#include "Array.h"

template<typename T,int size>
void Array<T,size>::fill(T num) {
}

template<typename T,int size>
T &Array<T,size>::at(int pos) {
    return this->arr[pos];
}

template<typename T,int size>
void Array<T,size>::print() {

}
template<typename U, int size>
std::ostream &operator<<(std::ostream &out, const Array<U,size> &arr){
    for(int i =0; i < size;i++){
        out << arr[i] << std::endl;
    }
    return out;
}

#endif //SPLIT_ARRAY_CPP