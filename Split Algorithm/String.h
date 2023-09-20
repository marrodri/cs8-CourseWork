//
// Created by Marthel Rodriguez on 9/20/23.
//

#ifndef SPLIT_STRING_H
#define SPLIT_STRING_H

#include <vector>
#include <string>
class String : public std::string{

public:
    String();
    String(const char *c);
    std::vector<String> split(char delimeter=' ');
    String(std::string c);
};

#endif //SPLIT_STRING_H
