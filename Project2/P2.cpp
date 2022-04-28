//
// Created by lolita kim on 4/11/22.
//
#include "inFest.h"
#include <iostream>

using namespace std;

int main(){
    inFest j1(3, 5);
    inFest j2(j1); //copy constructor
    j1.move(2);
    cout << "Min value of j1 is: " << j1.minValue() << endl;
    cout << "Max value of j1 is: " << j1.maxValue() << endl;
    j2.move(3);
    inFest j3(2, 6);
    j3.move(4);
    inFest j4(std::move(j3)); //move assignment

    return 0;
}
