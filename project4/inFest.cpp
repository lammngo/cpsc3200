//
// Created by lolita kim on 5/12/22.
//
/* Implementation invariants: - for class designers
 *
 * - implementation choices:
 * + the users only has access to the public methods inside inFest class, they have no idea about the gridFlea existence
 * + all the gridFlea variables and methods are protected from the users
 * + values in 3 variables of each gridFlea subObject are not stored, computed upon request
 * + p (the parameter in the move() function) can either be a positive or negative integer
 * + every gridFlea subObjects encapsulated in an inFest will only move upward diagonally (on both x-axis and y-axis)
 * with positive values gained in return.
 * + after each move, an inactiveCount will keep track of the state of the subObjects in whether they are inactive
 * or not. If the value return as -1(indicated subObject is permanently deactivated), increment the inactiveCount;
 * otherwise, if the value return as 0(indicated subObject is inactive but still inside the grid), REVIVE the subObjects
 * and decrement the inactiveCount. If more than half of the subObjects are inactive or permanently deactivated,
 * RESET the subObjects.
 * + this inFest class also supports client queries as to the minimum value acquired from a value() call across all
 * gridFlea subObjects, the maximum value acquired from a value() call across all gridFlea subObjects.
 *
 *
 * - private method implementation:
 * 1. values_generator(): (will explain more in details in why I used these arithmetic formulas to generate data in the
 * pre-conditions segment)
 * + takes in 2 parameters x and num, in which basically 2 random numbers that were passed from the
 * parameterized constructor in order to populate data using arithmetic formulas.
 * + this method will return a new gridFlea subObject with 3 new values: energeticPoint(= num--), activePoint(= num*2)
 * and gridSize(=num*10) as their variables.
 * - the gridFlea subObject after returned from the values_generator() method will be put in the
 * inFest array(fleaArray) respectively.
 *
 * - public methods implementation:
 * 1. move(int p):
 * + takes in p steps from the users, it will trigger the move() method on every gridFlea subObjects that were
 * encapsulated in the fleaArray. For example, if you call move(2) and passed in an array size of 5, the method will
 * make those 5 gridFlea subObjects in a fleaArray each moves 5 steps and return their values accordingly.
 * + it also checks for the inactiveCount after each move and respond to the count accordingly by determining on whether
 * the subObject must be considered as deactivated (value got returned by -1) -> increment the count by 1,
 * or it was considered as inactive but still inside the grid (value got returned by 0) -> REVIVE a subObject and decrement
 * the inactiveCount. If more than half of the subObjects are inactive or deactivated (inactiveCount > size/2) -> RESET
 * all gridFlea subObjects.
 * 2. minValue():
 * + if fleaArray only contains 1 element, return that value
 * + since the local variable 'min' is initially set to fleaArray[0], if fleaArray does not have any objects,
 * it will just return the min, in this case, nothing.
 * + if fleaArray has more than 2 objects, comparing min with the next object in the fleaArray, if min > the next one ->
 * return min as the next one.
 * 3. maxValue(): (fairly the same as the minValue() method described above)
 * + if fleaArray only contains 1 element, return that value
 * + since the local variable 'max' is initially set to fleaArray[0], if fleaArray does not have any objects,
 * it will just return the max, in this case, nothing.
 * + if fleaArray has more than 2 objects, comparing max with the next object in the fleaArray, if max < the next one ->
 * return max as the next one.
 * 4. appendArray(gridFlea gridObj):
 * + Create a new array with the source array size + 1
 * + assign/append each value from the source array over
 * + save the last index/space for the new object which was passed in as parameters, in this case, a gridFlea.
 * + delete the source pointer that was pointing to the old/source array
 * + assign the pointer to the new array in order to prevent memory leaks.
 *
 * - OVERLOADED OPERATORS:
 * ? why don't you need the pre-increment and post-increment inside infest
 * this is because if you have a look at how i designed my codes, the base-line of having a pre and post is to add to
 * infest 1 single gridFlea, but since i already had that operator, it would be a redundant if we add on these 2 operators.
 * + all the relations operators were overloaded from gridFlea by comparing values between 2 gridFleas in each infest object.
 * + the comparing values part was implemented inside gridFlea, obviously.
 * + then when we want to call the function in infest, we can just simply use the loop to loop through each infest object.
 *
 * - public copy constructors, move semantics and destructor implementation:
 * 1. copy constructor:
 * + creates a new fleaArray object called newFlea
 * + set the size and inactiveCount of the original fleaArray to newFlea
 * + using the for-loop to copy each gridFlea subObjects over to the newFlea
 * 2. copy assignment:
 * + delete the pointer of the original fleaArray
 * + using the same technique as the copy constructor to construct a newFlea and copy each gridFlea subObjects over
 * 3. move constructor:
 * + construct newFlea and copy the size and inactiveCount from the original fleaArray over
 * + set the pointer that was pointing to the fleaArray to nullptr
 * 4. move assignment:
 * + if the pointers of both newFlea and fleaArray are pointing to the different addresses, then do the followings:
 * delete the old fleaArray, copy things overs and set the old pointer to nullptr using the move constructor method
 * described above.
 * + if the 2 pointers are pointing to the same address, do nothing!
 * 5. destructor:
 * + delete the old fleaArray and its data
 */
#include "inFest.h"
#include <iostream>
#include "gridFlea.h"

using namespace std;


inFest::inFest(const inFest& newFlea) {
    size = newFlea.size;
    fleaArray = new gridFlea[newFlea.size];
    for(unsigned i = 0; i < newFlea.size; i++){
        fleaArray[i] = newFlea.fleaArray[i];
    }
}

inFest &inFest::operator=(const inFest& newFlea) {
    if(this != &newFlea){
        delete[] fleaArray;
        size = newFlea.size;
        fleaArray = new gridFlea[newFlea.size];
        size = newFlea.size;
        for(unsigned i = 0; i < newFlea.size; i++) {
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
/* Pre-conditions:
 * + totalObject MUST be a non-negative integer => infest size also need to be unsigned type
 */
inFest::inFest(unsigned num_generator, unsigned totalObject) {
    size = totalObject;
    fleaArray = new gridFlea[size];
    for (unsigned i = 0; i < size; i++){
        fleaArray[i] = values_generator(int(i), num_generator);
    }
}

/* Pre-condition:
 * 1. values_generator(int x, unsigned num):
 * - x must be integers, it can either be positive or negative integers
 * - num must be unsigned because later on it will be dependency injected in gridFlea as size, and since size is non-negative
 * integer, this also makes num a non-negative one.
 * - the arithmetic formulas for 3 variables (energeticPoint, activePoint and gridSize) has to be generated based on
this rule: the formula has to be in ascending order, which mean the formula that used to calculate for the energeticPoint
 * has to return the smallest value, next is activePoint, and finally, gridSize will have the biggest return value
 * formula. The reason is the activePoint has to be bigger than the energeticPoint for obvious reasons, you don't
 * want your car to stop running before it's tired. *I hope that my analogy makes sense:)* It is also apparent that you
 * want to make your gridSize the biggest comparing to the energeticPoint and the activePoint.
 * 2. move(int p):
 * - the gridFlea subObjects MUST BE in active state in order to move p steps.
 * - the values returned for each gridFlea subObjects MUST BE different as those objects are distinct.
 * 3. minValue() and maxValue():
 * - a fleaArray should not be empty if you want the function to return some values.
 */

/* Post-condition:
 * 1. values_generator(int x, int num):
 * - num wil become (num + x) as part of the arithmetic generator (this is to make each gridFlea subObjects distinct)
 * - energeticPoint, activePoint and gridSize will be changed to num++, num*2 and num*10 respectively.
 * 2. move(int p):
 * - gridFlea subObjects will move to a certain number of steps depending on the p the users passed in
 * - inactiveCount will be incremented by 1 if any gridFlea subObjects inside the fleaArray was permanently deactivated,
 * otherwise, it will be decremented by 1 if any gridFlea subObjects inside the fleaArray was inactive but revived.
 * - gridFlea subObjects inside the fleaArray will be reset if over half number of the objects were
 * inactive or deactivated.
 * 3. move assignment:
 * - the pointer that pointing to the old array MUST point to nullptr after you moved/swapped the pointers between it
 * with the new constructed array.
 */
gridFlea inFest::values_generator(int x, unsigned num) {
    // bound number of gridFlea objects
    num = num + x;
    int energeticPoint = num++;
    int activePoint = num*2;
    int gridSize = num*10;

    return gridFlea(energeticPoint, activePoint, gridSize);
}

void inFest::move(int p) {
    int inactiveCount = 0;
    for(unsigned i = 0; i < size; i++){
        fleaArray[i].move(p);
        if(fleaArray[i].value() == -1){ //permanently deactivated
            inactiveCount++;
        } else if(fleaArray[i].value() == 0){
            // inactive but still inside the grid? revive
            fleaArray[i].revive();
            inactiveCount--;
        }
        if(inactiveCount > int(size/2)){ //change state? reset
            fleaArray[i].reset();
        }
    }
}
int inFest::minValue() {
    int min = fleaArray[0].value();
    for (unsigned i = 1; i < size; i++){
        if(min > fleaArray[i].value())
            min = fleaArray[i].value();
    }
    return min;
}
int inFest::maxValue() {
    int max = fleaArray[0].value();
    for (unsigned i = 1; i < size; i++){
        if(max < fleaArray[i].value())
            max =  fleaArray[i].value();
    }
    return max;
}

int inFest::getValue() {
    int sum = 0;

    for (unsigned i = 0; i < size; i++)
    {
        sum += fleaArray[i].value();
    }

    return sum;
}

int inFest::getSize() const
{
    return this->size;
}
void inFest::appendArray(gridFlea gridObj) {
    gridFlea *newArray = new gridFlea[size + 1];
    for (unsigned i = 0; i < size; i++){
        newArray[i] = fleaArray[i];
    }
    newArray[size] = gridObj;
    delete fleaArray;
    fleaArray = newArray;
    size++;
}


inFest inFest::operator+(const inFest &rhs) const {
    inFest temp(*this);
    for(unsigned i = 0; i < rhs.size; i++){
        temp.appendArray(rhs.fleaArray[i]);
        temp.size++;
    }
    return temp;
}

inFest &inFest::operator+=(const inFest &rhs) {
    for(unsigned i = 0; i < rhs.size; i++){
        this->appendArray(rhs.fleaArray[i]);
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

bool inFest::operator>(const inFest &rhs) const{
    for (unsigned i = 0; i < size; i++){
        if(fleaArray[i] > rhs.fleaArray[i]) return true;
    }
    return false;
}

bool inFest::operator<(const inFest &rhs) const{
    for (unsigned i = 0; i < size; i++){
        if(fleaArray[i] < rhs.fleaArray[i]) return true;
    }
    return false;
}
bool inFest::operator==(const inFest &rhs) const{
    for (unsigned i = 0; i < size; i++){
        if(fleaArray[i] == rhs.fleaArray[i]) return true;
    }
    return false;
}

bool inFest::operator!=(const inFest &rhs) const{
    for (unsigned i = 0; i < size; i++){
        if (fleaArray[i] != rhs.fleaArray[i]) return true;
    }
    return false;
}

bool inFest::operator>=(const inFest &rhs) const{
    for (unsigned i = 0; i < size; i++){
        if(fleaArray[i] >= rhs.fleaArray[i]) return true;
    }
    return false;
}

bool inFest::operator<=(const inFest &rhs) const {
    for (unsigned i = 0; i < size; i++){
        if(fleaArray[i] <= rhs.fleaArray[i]) return true;
    }
    return false;
}



