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


    linkedList.push_front(a);
    linkedList.push_front(b);
    linkedList.push_front(c);
    linkedList.push_front(d);
    linkedList.push_front(e);

    linkedList.printListFromHead();
    linkedList.printListFromTail();




}

