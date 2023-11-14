//
// Created by Marthel Rodriguez on 10/16/23.
//

int calculateFibonacci(int num) {
    if(num == 0){
        return 0;
    }
    else if(num < 3){
        return 1;
    }
    return calculateFibonacci(num-2) + calculateFibonacci(num-1);
}
