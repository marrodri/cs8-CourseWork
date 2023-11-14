
//#include <iostream>
#include "Algorithms/TeddyBearPicnic/TeddyBearPicnic.h"


int main() {
    TeddyBearPicnic teddyBearPicnic;

    //   bear(250) is true (as shown above)
//   bear(42) is true
//   bear(84) is true
//   bear(53) is false
//   bear(41) is false
    int a = 250;
    int b = 42;
    int c = 84;
    int d = 53;
    int e = 41;

    //done!
    std::cout << "teddy(" <<a << "):" << teddyBearPicnic.bears(a) <<"\n";
    std::cout << "teddy(" <<b << "):" << teddyBearPicnic.bears(b) <<"\n";
    std::cout << "teddy(" <<c << "):" << teddyBearPicnic.bears(c) <<"\n";
    std::cout << "teddy(" <<d << "):" << teddyBearPicnic.bears(d) <<"\n";
    std::cout << "teddy(" <<e << "):" << teddyBearPicnic.bears(e) <<"\n";
}
