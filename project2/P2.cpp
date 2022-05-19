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
    
    void run(inFest &infest, int index){
    cout << "==========================================" << endl;
    cout << "<<< Object #" << index << " attempting to run 2 times >>>" << endl;
    infest.move(2);
    cout << "Min value: " << infest.minValue() << endl;
    cout << "Max value: " << infest.maxValue() << endl;
    cout << "<<< Object #" << index << " attempting to run 5 times >>>" << endl;
    infest.move(5);
    cout << "Min value: " << infest.minValue() << endl;
    cout << "Max value: " << infest.maxValue() << endl;
    cout << "==========================================" << endl;
    inFest copiedInfest = infest;
    cout << ">>> Created a copy of object #" << index << " <<<" << endl;
    cout << "Min value (og infest): " << infest.minValue() << endl;
    cout << "Max value (og infest): " << infest.minValue() << endl;
    cout << "Min value (copied infest): " << copiedInfest.minValue() << endl;
    cout << "Max value (copied infest): " << copiedInfest.minValue() << endl;

    cout << "=== Attempting to move both infest objects by 3 times ===" << endl;
    infest.move(3);
    cout << "Min value (og infest): " << infest.minValue() << endl;
    cout << "Max value (og infest): " << infest.minValue() << endl;
    copiedInfest.move(3);
    cout << "Min value (copied infest): " << copiedInfest.minValue() << endl;
    cout << "Max value (copied infest): " << copiedInfest.minValue() << endl;

    cout << "=== Attempting to move the og infest object by 4 times ===" << endl;
    infest.move(4);
    cout << "Min value: " << infest.minValue() << endl;
    cout << "Max value: " << infest.maxValue() << endl;

    cout << "=== Attempting to move the copied infest object by 2 times ===" << endl;
    copiedInfest.move(2);
    cout << "Min value: " << copiedInfest.minValue() << endl;
    cout << "Max value: " << copiedInfest.maxValue() << endl;

    cout << "Printing out the copied infest object called by value..." << endl;
    printCallByValue(copiedInfest);

    cout << "==========================================" << endl;
    cout << "~~~ Finished running object #" << index << " ~~~" << endl;
    cout << endl;
    }
    return 0;
}
