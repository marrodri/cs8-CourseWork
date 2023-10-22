//
// Created by Marthel Rodriguez on 10/10/23.
//

#ifndef SPLIT_SHUNTINGYARD_H
#define SPLIT_SHUNTINGYARD_H

#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
/*conversion to infix to postfix*/
class ShuntingYard {
private:
    std::vector<std::string> stack;
    std::queue<std::string> queue;

    void pushOpToStack(std::string);
    std::string popOpFromStack();
    void pushOpToQueue();
    bool isHigherPrecedence(char op1, char op2);

    bool isNumber(std::string value);

    bool isOperator(char opValue);
public:
    ShuntingYard();
     std::string convertInfixToPostfix(const std::string& infixStr);
};


#endif //SPLIT_SHUNTINGYARD_H
