//
// Created by lolita kim on 4/11/22.
//

/* Class invariants:
 * - this inFest class generated an array that contains a desired number of distinct gridFlea objects by the clients.
 * - arithmetic generator populates a distinct sequence of number for each variable of each gridFlea object upon request.
 * - parameterized constructor takes in 2 arguments
 * - size (inFest array size) and inactiveCount (counter for inactive objects) may be changed
 * upon request after construction.
 * - clients can execute 3 functions: move(int p), minValue() and maxValue()


 * Interface invariants:
 * - no default constructor
 * - constructor will initialize all private members
 * - parameterized constructor, which takes in 2 integers parameters: num_generator (the number that you must
 * pass in so that the arithmetic generator of the class can use it to populate data for each gridFlea object);
 * totalObject (how many gridFlea objects that you want to store in the inFest array, in other words, the array size)
 *
 * - public copy constructors, move semantics and destructor:
 * 1. copy constructor: create a new inFest object that copy all the data(variables, size, methods) from the original one.
 * 2. copy assignment: overloaded the original inFest object with the new one and delete the pointer that is pointing to it.
 * 3. move constructor: enables the resources owned by an original inFest object to be moved into another new inFest
 * object without copying.
 * 4. move assignment: transfers ownership from the original inFest object to the new one by swapping their pointers and
 * deleting the original object.
 * 5. destructor: delete an original inFest array
 *
 * - public methods:
 * 1. move():
 * + trigger move() for all gridFlea objects encapsulated in inFest array and make them move to
 * a specific number of squares depends on its state.
 * + respond consistently (reset or revive) when more than half of its gridFlea subObjects
 * are inactive or deactivated.
 * + if the value() return -1, that means object is permanently deactivated (inactive and outside the grid),
 * otherwise, if it returns 0, that means object is inactive but still inside the grid (it is a reverse version
 * of deactivated), thus, the class does not have any deactivated bool type variable.
 * 2. minValue(): return the gridFlea object with the smallest value amongst all other subObjects that were stored
 * inside the inFest array.
 * 3. maxValue(): return the gridFlea object with the biggest value amongst all other subObjects that were stored inside
 * the inFest array.
 */

#ifndef PROJECT2_INFEST_H
#define PROJECT2_INFEST_H
#include "gridFlea.h"


class inFest {
private:
    int size, inactiveCount;
    gridFlea* fleaArray;
    gridFlea values_generator(int num_generator, int num);

public:
    inFest(int x, int totalObject);
    inFest(const inFest& newFlea); //copy constructor
    inFest& operator=(const inFest& newFlea); //copy assignment
    ~inFest(); //destructor

    inFest(inFest&& newFlea); //move constructor
    inFest &operator=(inFest&& newFlea); //move assignment

    void move(int p);
    int minValue();
    int maxValue();
};


#endif //PROJECT2_INFEST_H
