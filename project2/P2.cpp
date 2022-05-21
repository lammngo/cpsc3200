#include <iostream>
#include "inFest.h"

using namespace std;

const int NUM_INFESTS = 10;

inFest **createInfests() {
    inFest **infests = new inFest *[NUM_INFESTS];
    for (int i = 0; i < NUM_INFESTS; i++) {
        int num_gen = rand() % 10 + 1;
        int len = rand() % 10 + 1;
        infests[i] = new inFest(num_gen, len);
    }
    return infests;
}

void deleteInfests(inFest **infests) {
    for (int i = 0; i < NUM_INFESTS; i++) {
        delete infests[i];
    }
    delete[] infests;
}

void printCallByValue(inFest infest){
    cout << "Min value: " << infest.minValue() << endl;
    cout << "Max value: " << infest.maxValue() << endl;
}

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

int main(int argc, char *argv[]){
    inFest **infests = createInfests();
    cout << "*** Creating " << NUM_INFESTS << " infest objects ***" << endl;
    cout << endl;

    for(int i = 0; i < NUM_INFESTS; i++){
        run(*infests[i], i + 1);
    }
    deleteInfests(infests);
}
