//
// Created by Marthel Rodriguez on 9/21/23.
//

#ifndef SPLIT_FILEREADER_H
#define SPLIT_FILEREADER_H

#include <fstream>
template<typename T>
class FileReader {
private:
    //test.
    static std::ifstream &fin;
    T var;
public:
    //test.
    static std::string getFileContents(const std::string filename);
    static T getNext(const std::string &filename);
    static void quit();
};

#include "FileReader.cpp"
#endif //SPLIT_FILEREADER_H
