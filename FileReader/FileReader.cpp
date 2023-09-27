//
// Created by Marthel Rodriguez on 9/21/23.
//

#ifndef SPLIT_FILEREADER_CPP
#define SPLIT_FILEREADER_CPP

#include "FileReader.h"


template<typename T>
std::string FileReader<T>::getFileContents(const std::string filename) {
    return std::string();
}

template<typename T>
T FileReader<T>::getNext(const std::string &filename) {
    return nullptr;
}

template<typename T>
void FileReader<T>::quit() {
}



#endif //SPLIT_FILEREADER_CPP