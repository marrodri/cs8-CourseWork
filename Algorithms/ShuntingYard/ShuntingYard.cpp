//
// Created by Marthel Rodriguez on 10/10/23.
//

#include "ShuntingYard.h"
ShuntingYard::ShuntingYard(){}

void ShuntingYard::pushOpToStack(std::string Op){
    //
}

std::string ShuntingYard::popOpFromStack(){
    //NOTE: stack.top() is the same as stack.back when its a vector object.
    std::string op = stack.back();
    stack.pop_back();
    return op;
}

//void ShuntingYard::pushValueToQueue(std::string value){
//    //
//}

bool ShuntingYard::isHigherPrecedence(char op1, char op2){

    //op1 top of the stack
    //op2 current op from the list.

    // op1 is / or  *, and op2 is + or -, then send true for the swap.
    //compare both ops. if op1 has a higher precendece than op2.
    //return true. otherwise return false.
    // PEMDAS
//    if(op2=='('){
//        return true;
//    }
    if(op1 == op2){
        return true;
    }
    if((op1 == '*' && op2=='/') ||(op1 == '/' && op2=='*')){
        return true;
    }
    if ((op1 == '/' || op1 == '*') && (op2=='+' || op2 =='-')){
        return true;
    }
    if((op1 == '-' && op2=='+') ||(op1 == '+' && op2=='-')){
        return true;
    }
    return false;
}

bool ShuntingYard::isNumber(std::string value) {
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


bool ShuntingYard::isOperator(char opValue) {
    const char ops[] = {'+', '-', '/', '*', '(', ')'};
    for (char op: ops) {
        if (opValue == op) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> operatorSplitter(const std::string &infixOp){
    //split the infixOp to a vector of strings.
    std::vector<std::string> splitInfixOp;
    int j =0, n =0;
    for(int i = 0; i< infixOp.size(); i++){
        if (isdigit(infixOp[i]) && infixOp[i] != '\0') {
            std::string num;
            n =0;
            j = i;
            while(isdigit(infixOp[j]) && infixOp[j]!= '\0'){
                j++;
                n++;
            }
            std::string numberStr = infixOp.substr(i, n);
            splitInfixOp.emplace_back(numberStr);
            i =j;
        }
        if (!isdigit(infixOp[i]) && infixOp[i] != '\0'){
            splitInfixOp.emplace_back(std::string(1,infixOp[i]));
        }
    }
    return splitInfixOp;

}

//format "1+2*(3/2)"
//split the te
std::string ShuntingYard::convertInfixToPostfix(const std::string &infixStr){
    //split the string to a vector of values
    std::vector<std::string> infixVector = operatorSplitter(infixStr);
    std::string finalQueue;
    std::cout <<"splitted infix: ";
    for(std::string &infixVal:infixVector){
        std::cout << infixVal <<" ";
    }
    std::cout << "\n";

    //Checkpoint view here.
    for (std::string value : infixVector) {
        //if its a number,push it to the queue right away.
        if (isNumber(value)) {
            queue.push(value);
        }
        //else if its an operator.
        else if(isOperator(value[0])){
            //if the stack is empty, push op to stack
            if(stack.empty()) {
                stack.push_back(value);
            }
            else{
                //else if is an ).
                if (value[0] == ')'){
                    //keep popping ops to the queue.
                    //till a '(' is founded in the stack.
                    while (!stack.empty() && stack.back()[0] != '(') {
                        if(stack.size()== 1 && stack.back()[0] != '('){
                            return std::string("Error infix no passed correctly.");
                        }
                        queue.push(popOpFromStack());
                    }

                    popOpFromStack();
//                    queue.push(popOpFromStack());
                }
                //check if the current operator has a higher importance.
                else{
                    //check for precedence.
                    while(isHigherPrecedence(stack.back()[0], value[0]) && !stack.empty()){
                        queue.push(popOpFromStack());
                    }
                    //otherwise, just push the op to the stack.
                    stack.push_back(value);
                }
            }
        }
    }
    //at the end, iterate the stack to pop the remaining ops.
    // if an  '(' appears in the stack, return an error message.
    while(!stack.empty()){
        if(stack.back()[0] != '(') {
            queue.push(popOpFromStack());
        }
        else{
            return std::string("Error infix no passed correctly.");
        }
    }
    //otherwise return the new created queue.



    while(!queue.empty()){
        std::string new_s = queue.front();
        finalQueue += std::string(new_s);
        queue.pop();
        if(!queue.empty()){
            finalQueue += " ";
        }
    }
    return finalQueue;
    //concatenate the queue to a string and return the new string.
}




