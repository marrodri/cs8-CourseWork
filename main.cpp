#include <iostream>
#include "Split Algorithm/String.h"

std::vector<std::string> split(std::string &str, char delimeter){
    int i = 0;
    int idx;
    std::vector<std::string> listOfStrings;
    idx = str.find(delimeter, 0);
    while(idx != std::string::npos){
        if (str[idx] == delimeter || !str[idx]) {
            //check that there's a lot of whitespaces that needs to be skipped.
            std::string substr = str.substr(i,(idx-i)+1);
            listOfStrings.push_back(substr);
            i = idx+1;
            idx = idx+1;
        }
        idx = str.find(delimeter, idx);
    }
    std::string substr = str.substr(i,(idx-i));
    listOfStrings.push_back(substr);
    return (listOfStrings);
}

int main() {
    std::cout << "Hello world" << std::endl;
    std::string s = "hello world";

    int idx = s.find('e', 2);
    if (idx != std::string::npos) {

    }
//    //running function locally.
//    std::string str = "my    dog   ate   a   lot   of    food";
//    std::vector<std::string>  strings = split(str, ' ');

    //running function from a class. (good so far!)
    String new_str = "   my    dog    ate   a    lot   of   food";
    std::vector<String>  strings = new_str.split();

    for(int i =0; i < strings.size();i++){
        std::cout << i <<") "<< strings[i] <<"\n";
    }



    std::string h = s.substr(0, 4);
    return 0;
}

