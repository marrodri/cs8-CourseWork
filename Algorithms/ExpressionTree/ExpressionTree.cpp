//
// Created by Marthel Rodriguez on 11/6/23.
//

#include "ExpressionTree.h"


/**
 * console output debugging functions
 * */
void BfsPrintExpressionTree(TreeNode *root){
    std::queue<TreeNode*> queue;
    TreeNode *current;
    if (!root){
        return ;
    }
    if (!root->right && !root->left) {
        std::cout << current->data <<" ";
        return ;
    }
    queue.push(root);
    std::cout << "print expression tree BFS Traversal:\n";
    while(!queue.empty()){
        current = queue.front();
        queue.pop();
        std::cout << current->data <<" ";
        if(current->left){
            queue.push(current->left);
        }
        if(current->right){
            queue.push(current->right);
        }
    }
}

void ExpressionTree::shuntingYard(std::string infixExpresion) {
    ShuntingYard shuntingYard;
    postfixExpresion = shuntingYard.convertInfixToPostfix(infixExpresion);
}


double ExpressionTree::evaluate(std::string &infixExpression) {
//    shuntingYard(infixExpression);
    //tree is done!!!
    postfixExpresion = infixExpression;
    TreeNode *tree = initializeTree();
    double result = postOrder(tree);

    //TODO bring the postOrder evaluator for accomodating this final step.
    return result;
}

TreeNode* ExpressionTree::initializeTree() {
    std::stack<TreeNode*> nodes;
    for(const char & c: postfixExpresion){
        if(std::isdigit(c)){
            //push a new node to our stack.
            //emplace: create a node and give
            //its value to its nodeTree.
            TreeNode *newNode = new TreeNode;
            newNode->right = nullptr;
            newNode->left = nullptr;
            newNode->data = c;
            nodes.push(newNode);
        }
        else{
            TreeNode *t = new TreeNode;
            t->data = c; //t->data is op.
            t->right = nodes.top();
            nodes.pop();
            t->left = nodes.top();
            nodes.pop();
            nodes.push(t);
        }
    }
    BfsPrintExpressionTree(nodes.top()); //printer for debbuging
    return nodes.top();
}


double ExpressionTree::postOrder(TreeNode *node) {
    if (node) {
        if (!node->left && !node->right) {
            return (double)(node->data - '0');
        }
        if (!std::isdigit(node->data)) {
            return evaluateExpression(node->data, postOrder(node->left), postOrder(node->right));
        }
    }
}


double ExpressionTree::evaluateExpression(char op, double leftValue, double rightValue) {
    switch(op){
        case '-':
            return leftValue - rightValue;
        case '+':
            return leftValue + rightValue;
        case '/':
            return leftValue / rightValue;
        case '*':
            return leftValue * rightValue;
        default:
            break;
    }
    return 0;
}
