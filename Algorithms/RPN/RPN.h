//
// Created by Marthel Rodriguez on 10/10/23.
//

#ifndef SPLIT_RPN_H
#define SPLIT_RPN_H
#include <string>
#include <stack>
#include <iostream>
//Reverse Polish Notation Calculator
class RPN {
private:
    std::stack<double> stack;

public:
    double calculatePostFix(std::string &postFixOp);

    double doOperation(double left, double right, char op);

};


#endif //SPLIT_RPN_H
