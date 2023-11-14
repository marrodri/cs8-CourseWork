#include <iostream>
#include "Algorithms/BTree/BTree.h"
#include "Algorithms/BTree/functions.h"

int main(){
    BTree<int> bt;
    bt.makeTree();
    bt.printBTree();

//checkpoint see if the bt has data added
//from maketree.

//    int *ptr = find(bt,2000);
    int a = 90;
    std::cout << "finding 90:\n";
    int *ptr = bt.find(a);
    std::cout << "ptr: " << ptr<<"\n";
if(ptr){
        *ptr = 80;
    }
    bt.printBTree();

    //values that work, 999, 24, 249
    //values 850, 160, 2000 are not being properly added, b/c 0s are putted.

    //found the bug, it's related to firstGet().
    // it goes between dataSize and dataCount.
    //this is probably the common problem that barkeshley mentioned, that
    //once trying to add a value that is very high, it's not putted properly.
    //THIS IS GOOD TO GO :)
    int b=2000;
    bt.insertValue( b);
    //this is not added. probably with fixExcess will fix the problem.
    //as it just only adds values but not children to even out the tree.
    bt.insertValue(999);
    bt.insertValue(850);
    bt.insertValue(24);

    bt.printBTree();
    return 0;


    return 0;
}
