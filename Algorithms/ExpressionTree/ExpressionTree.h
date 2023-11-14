//
// Created by Marthel Rodriguez on 11/6/23.
//

#ifndef SPLIT_EXPRESSIONTREE_H
#define SPLIT_EXPRESSIONTREE_H
#include "TreeNode.h"
#include <string>
#include <stack>
#include "../ShuntingYard/ShuntingYard.h"

class ExpressionTree {
private:
    //inline:
    inline static std::string postfixExpresion;
    static void shuntingYard(std::string infixExpresion);
    static TreeNode* initializeTree();
    static double postOrder(TreeNode* node);
    static double evaluateExpression(char op, double leftValue, double rightValue);
public:
    static double evaluate(std::string &infixExpression);

};


#endif //SPLIT_EXPRESSIONTREE_H
