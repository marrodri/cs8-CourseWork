//
// Created by Marthel Rodriguez on 10/10/23.
//

#include "RPN.h"

bool isNumber(std::string value){
    for (int i = 0; i < value.size(); i++){
        if((value[i] == '-' || value[i]=='.') && value[i+1] != '\0'){
            continue;
        }
        if(!std::isdigit(value[i])){
            return false;
        }
    }
    return true;
}

std::vector<std::string> stringSplit(std::string &str, char delimeter){
    std::vector<std::string> splitString;
    int i =0;
    int space_pos = 0;
    std::string substr;
    int length =0;

    while((space_pos = str.find(' ',i)) != -1){
        length = space_pos - i;
        substr = str.substr(i, length);
        splitString.push_back(substr);
        i += length + 1;
    }
    return splitString;
}
double RPN::doOperation(double left, double right, char op){
    double result = 0;
    switch(op){
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
        case '-':
            result = left - right;
            break;
        default:
            result = left + right;
            break;
    }
    return result;
}

int RPN::calculatePostFix(std::string &postFixOp){
    std::cout << "calculatePostFix called\n";
    double number=0;
    double leftNum=0;
    double rightNum=0;
    std::vector<std::string> splitPostFix = stringSplit(postFixOp, ' ');
    std::cout << "printing splitPostFix\n";
    for (std::string &op: splitPostFix) {
        if(isNumber(op)){
            number = std::stod(op);
            stackInt.push(number);
        }
        else{
            rightNum = stackInt.top();
            stackInt.pop();
            leftNum = stackInt.top();
            stackInt.pop();
            number = doOperation(leftNum, rightNum, op[0]);
            stackInt.push(number);
        }
    }
    return number;
}

double RPN::calculatePostFixDouble(std::string postFixOp){}
