#include <iostream>
#include "FileReader/FileReader.h"
#include "LinkedList/LinkedList.h"
int main(){
    LinkedList<int> linkedList;

    int a=1;
    int b=2;
    int c=3;
    int d=6;
    int e=7;

    int g=21;
    int ge=22;


    linkedList.push_front(a);
    linkedList.push_front(b);


    linkedList.printListFromHead();
    linkedList.printListFromTail();

    linkedList.push_back(g);
    linkedList.push_back(ge);


    linkedList.printListFromHead();
    linkedList.printListFromTail();
    /*GOOD SO FAR*/

    int lastElem = 40;
    linkedList.insertAfter(c,b); //3, Node(1);
    linkedList.insertAfter(d,g); //6, Node(21);
    linkedList.insertAfter(lastElem,ge); //6, Node(21);x

    std::cout << "LinkedList insertedAfter!!!\n";
    linkedList.printListFromHead();
    linkedList.printListFromTail();

    //list:  [2]->[3]->[1]->[21]->[6]->[22]->[40]->nullptr
    std::cout << "LinkedList insertBefore!!!\n";
    int beforeElemA = 30;
    int beforeElemB = 35;
    int beforeElemC = 33;
    int beforeElemD = 32;
    int noExist = 2000;
    int new3 = 90;
    //buggy here. Work on it.
    // ...->[30]->[1]->[]->...
    linkedList.insertBefore(beforeElemA, a);
    // ...->[35]->[30]->[1]->...
    linkedList.insertBefore(beforeElemB, beforeElemA);
    // ...->[33]->[2]->[]->...
    linkedList.insertBefore(beforeElemC, b);
    // ...->[32]->[40]->[]->...
    linkedList.insertBefore(beforeElemD, lastElem);
    linkedList.insertBefore(new3, lastElem);

    linkedList.printListFromHead();
    linkedList.printListFromTail();
    //Good so far. Now test to delete the params.

    //[32]->[90]->[40] removed
    linkedList.pop_back();
    linkedList.pop_back();
    linkedList.pop_back();


    linkedList.printListFromHead();
    linkedList.printListFromTail();
    //good sofar.

    //[33]->[2]->[3]->...
    linkedList.pop_front();
    linkedList.pop_front();
    linkedList.pop_front();

    linkedList.printListFromTail();
    linkedList.printListFromHead();


    std::cout << linkedList;

}

