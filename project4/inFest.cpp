//
// Created by lolita kim on 5/12/22.
//
#include "inFest.h"
#include <iostream>
#include "gridFlea.h"

using namespace std;


inFest::inFest(const inFest& newFlea) {
    size = newFlea.size;
    fleaArray = new gridFlea[newFlea.size];
    for(int i = 0; i < newFlea.size; i++){
        fleaArray[i] = newFlea.fleaArray[i];
    }
}

inFest &inFest::operator=(const inFest& newFlea) {
    if(this != &newFlea){
        delete[] fleaArray;
        size = newFlea.size;
        fleaArray = new gridFlea[newFlea.size];
        size = newFlea.size;
        for(int i = 0; i < newFlea.size; i++) {
            fleaArray[i] = newFlea.fleaArray[i];
        }
    }
    return *this;
}

inFest::~inFest() {
    delete[] fleaArray;
}

inFest::inFest(inFest &&newFlea) {
    size = newFlea.size;
    fleaArray = newFlea.fleaArray;
    newFlea.size = 0;
    newFlea.fleaArray = nullptr;
}

inFest &inFest::operator=(inFest &&newFlea) {
    if(this != &newFlea){
        delete[] this->fleaArray;
        size = newFlea.size;
        fleaArray = newFlea.fleaArray;
        newFlea.size = 0;
        newFlea.fleaArray = nullptr;
    }
    return *this;
}
inFest::inFest(int num_generator, int totalObject) {
    size = totalObject;
    fleaArray = new gridFlea[size];
    for (int i = 0; i < size; i++){
        fleaArray[i] = values_generator(i, num_generator);
    }
}

gridFlea inFest::values_generator(int x, int num) {
    // bound number of gridFlea objects
    num = num + x;
    int energeticPoint = num++;
    int activePoint = num*2;
    int gridSize = num*10;

    return gridFlea(energeticPoint, activePoint, gridSize);
}

void inFest::move(int p) {
    int inactiveCount = 0;
    for(int i = 0; i < size; i++){
        fleaArray[i].move(p);
        if(fleaArray[i].value() == -1){ //permanently deactivated
            inactiveCount++;
        } else if(fleaArray[i].value() == 0){
            // inactive but still inside the grid? revive
            fleaArray[i].revive();
            inactiveCount--;
        }
        if(inactiveCount > size/2){ //change state? reset
            fleaArray[i].reset();
        }
    }
}
int inFest::minValue() {
    int min = fleaArray[0].value();
    for (int i = 1; i < size; i++){
        if(min > fleaArray[i].value())
            min = fleaArray[i].value();
    }
    return min;
}
int inFest::maxValue() {
    int max = fleaArray[0].value();
    for (int i = 1; i < size; i++){
        if(max < fleaArray[i].value())
            max =  fleaArray[i].value();
    }
    return max;
}

void inFest::appendArray(gridFlea gridObj) {
    gridFlea *newArray = new gridFlea[size + 1];
    for (int i = 0; i < size; i++){
        newArray[i] = fleaArray[i];
    }
    newArray[size] = gridObj;

    delete fleaArray;
    fleaArray = newArray;
}


inFest inFest::operator+(const inFest &rhs) const {
    inFest temp(*this);
    for(int i = 0; i < rhs.size; i++){
        temp.appendArray(rhs.fleaArray[i]);
    }
    return temp;
}

inFest &inFest::operator+=(const inFest &rhs) {
    for(int i = 0; i < rhs.size; i++){
        appendArray(rhs.fleaArray[i]);
    }
    return *this;
}
inFest inFest::operator+(const gridFlea &rhs) const{
    inFest temp(*this);
    temp.appendArray(rhs);
    return temp;
}
inFest &inFest:: operator+=(const gridFlea &rhs){
    appendArray(rhs);
    return *this;
}
inFest & inFest::operator++() {
    return *this;
}

inFest inFest::operator++(int x) {
    inFest oldFlea = *this;
    this->appendArray(values_generator(x, size));
    return oldFlea;
}




