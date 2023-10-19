//
// Created by Marthel Rodriguez on 10/18/23.
//

#include "TeddyBearPicnic.h"


void TeddyBearPicnic::runTeddyBearPicnic(int n) {

}


// Postcondition: A true return value means that it is possible to win
// the bear game by starting with n bears. A false return value means that
// it is not possible to win the bear game by starting with n bears.
// Examples:
//   bear(250) is true (as shown above)
//   bear(42) is true
//   bear(84) is true
//   bear(53) is false
//   bear(41) is false
bool TeddyBearPicnic::bears(int n) {
    //number won;
    bool numberWon = false;
    if(n < 42){
        return false;
    }
    if (n == 42) {
        return true;
    }
    if((n % 2 == 0) && !numberWon){
        //  if ( n is even, return bears(n/2) )
        numberWon = bears(n/2);
    }
    if(((n % 3 == 0) || (n%4==0)) && !numberWon){
        //  if (n is div by 3 or 4, return bears(n%10 * ((n%100)/10))   )
        numberWon = bears( n -(n%10 * ((n%100)/10)));
    }
    if((n % 5 == 0) && !numberWon){
        //  if n is divisible by 5, return  bears(n-42)
        numberWon = bears(n-42);
    }
    return numberWon;
}
