//
// Created by Marthel Rodriguez on 9/20/23.
//

#include "String.h"

//String::String(){}
//String::String(std::string str){
////    this = &str;
//}

std::vector<String> String::split(char delimeter) {
    int i = 0;
    int idx;
    std::string str = *this;
    std::vector<String> listOfStrings;
    idx = this->find(delimeter, 0);
    while(idx != std::string::npos){
        if (str[idx] == delimeter || !str[idx]) {
            //check that there's a lot of whitespaces that needs to be skipped.
            if (idx - i != 0) {
                std::string substr = this->substr(i, (idx - i) + 1);
                listOfStrings.emplace_back(substr);
            }
            i = idx + 1;
            idx = idx + 1;
        }
        idx = this->find(delimeter, idx);
    }
    if(idx - i != 0){
        std::string substr = str.substr(i,(idx-i));
        listOfStrings.emplace_back(substr);
    }
    return (listOfStrings);
}

String::String(const char *c): std::string(c) {

}
String::String(std::string c): std::string(c) {

}




