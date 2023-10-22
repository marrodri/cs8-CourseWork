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
    std::stack<double> stackInt;
    std::stack<double> stackDouble;

public:
    int calculatePostFix(std::string &postFixOp);
    double calculatePostFixDouble(std::string postFixOp);

    double doOperation(double left, double right, char op);
    double calculateValueDouble(int op1, int op2);

};


#endif //SPLIT_RPN_H
