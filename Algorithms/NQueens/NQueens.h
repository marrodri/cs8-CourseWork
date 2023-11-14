//
// Created by Marthel Rodriguez on 10/17/23.
//

#ifndef SPLIT_NQUEENS_H
#define SPLIT_NQUEENS_H

#include <vector>
#include <iostream>
class NQueens {
private:
    std::vector<std::vector<char>> board;
    std::vector<int> globalArray;
    int numOfQueens;

    void initGlobalArray(int k);

public:
    //constructor, it initializes the board.

    NQueens();
    NQueens(int n);
    bool isPlaceValid(int x, int y);
    void solveNQueens(int n);
    void printBoard();
};


#endif //SPLIT_NQUEENS_H
