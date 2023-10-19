//
// Created by Marthel Rodriguez on 10/17/23.
//

#include "NQueens.h"


NQueens::NQueens() {

}

NQueens::NQueens(int n): numOfQueens(n), globalArray(n,-1) {
}

bool NQueens::isPlaceValid(int k, int i) {
    /**
     ** Returns true if a queen can be placed
     ** in k row and ith column. Otherwise
     ** it returns false. X[] is a global array.
     * */
    for (int j=0; j < k; j++) {
        //Two in the same column. //or in the same diagonal.
        if ((globalArray[j] == i) || (std::abs(globalArray[j] - i) == std::abs(j - k))) {
            return false;
        }
    }
    return true;
}

void NQueens::writeBoard() {
    printBoard();
}

//k = current Queen
void NQueens::solveNQueens(int k) {
    // use Backtrack, this procedure prints all
    // possible placements of n queens on an nxn
    // chessboard so that they are non-attacking.
    // i =0 ; row 1
    for (int i = 0; i < numOfQueens; i++) {
        if (isPlaceValid(k, i)) {
            globalArray[k] = i;
            // when k reaches the last row. print
            if (k == numOfQueens-1) {
                writeBoard();
                //return ;
            }
            else {
                // otherwise go to the next queen..
                solveNQueens(k+1);
               // return ;
            }
            globalArray[k] = -1;
        }
    }

}

void NQueens::printBoard() {
//       0,1,2,3,4,5,6 <-each space represent a row
//    X=[0,2,5,6,4,3,5] <-each num represent the col
    std::cout << "++++++++++++NEW_STATS++++++++++++\n";
    std::cout << "+++++++++++++++++++++++++++++++++\n";

    std::cout << "globalArray: ";
    std::cout << "[ ";
    for (int i = 0; i < globalArray.size(); i++){
        std::cout << globalArray[i] + 1 << ", ";
    }
    std::cout << " ]\n";
    std::cout << "========printing board===========\n";
    for (int i =0; i < globalArray.size();i++) {
        //row
        std::cout << "[";
        for (int j =0; j < globalArray.size();j++) {
            if(globalArray[i] == j)
                std::cout << 'Q';
            else
                std::cout <<  '_';
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "=================================\n";
    std::cout << "+++++++++++++++++++++++++++++++++\n\n";
}
