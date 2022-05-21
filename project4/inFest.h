//
// Created by lolita kim on 5/12/22.
//
/* Class invariants:
 * - this inFest class generated an array that contains a desired number of distinct gridFlea objects by the clients.
 * - arithmetic generator populates a distinct sequence of number for each variable of each gridFlea object upon request.
 * - parameterized constructor takes in 2 arguments
 * - size (inFest array size) and inactiveCount (counter for inactive objects) may be changed
 * upon request after construction.
 * - clients can execute 3 functions: move(int p), minValue() and maxValue()
 *
 * Interface invariants:
 * - no default constructor because we are using double pointers and vectors in the driver functions, which mean there are
 * no objects invocations here.
 * - constructor will initialize all private members
 * - parameterized constructor, which takes in 2 integers parameters: num_generator (the number that you must
 * pass in so that the arithmetic generator of the class can use it to populate data for each gridFlea object);
 * totalObject (how many gridFlea objects that you want to store in the inFest array, in other words, the array size)
 *
 * - public copy constructors, move semantics and destructor:
 * 1. copy constructor: create a new inFest object that deep-copying all the data(variables, size, methods) from the original one.
 * 2. copy assignment: overloaded the source inFest object with the new one and delete the pointer that was pointing to it.
 * 3. move constructor: enables the resources owned by an original inFest object to be moved into another new inFest
 * object without copying.
 * 4. move assignment: transfers ownership from the original inFest object to the new one by swapping their pointers and
 * deleting the original object.
 * 5. destructor: destructs the InFest. The used array is deallocated and its memory is returned to heap.
 *
 * - assignment operators:
 * (+) ADDITION OPERATORS: (can also understand as APPENDING OPERATORS)
 * 1. inFest += (const inFest &rhs):
 *   appending the current infest object with the new infest that encapsulated an array of gridFleas. in other words, this
 *   operand will add multiple gridFleas to the current infest object.
 * 2. inFest += (const inFest &rhs) const:
 *   this operand will do the same functionality as the first one, but it will first produce the copy of the old infest object,
 *   then add multiple gridFleas to the new infest object and return it. the purpose of this operand is to prevent
 *   direct changes on the source infest object.
 * 3. inFest += (const gridFlea &rhs):
 *   appending the current infest object with one new single gridFlea. as a result, each source infest array will be
 *   appended one new gridFlea which was injected by the clients.
 * 4. inFest += (const gridFlea &rhs) const:
 *   this operand will do the same functionality as the first one, but it will first produce the copy of the old infest object,
 *   then add one single gridFleas to the new infest object and return it. the purpose of this operand is to prevent
 *   direct changes on the source infest object.
 *
 * - overloaded operators:
 * (=) RELATION OPERATORS: =, !=, <, >, <=, >=
 * whenever each operand was called, its function will trigger every gridFleas that were encapsulated in each infest
 * object. the operand will then compare the values of each gridFlea and return the results as boolean.
 * /// IMPORTANT NOTES ///
 * in order to use these relation operands in which comparing each gridFlea encapsulated inside the inFest object, we MUST
 * then override the operators between the gridFlea as well, and this will be illustrated more in the gridFlea.h file.
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
 * 4. getValue(): return the value of infest object
 * 5. getSize(): return the size of infest object
 * 6. appendArray(): create a new Array with size+1, and start appending each value from the source array, by doing this
 * there is no need to check for the size of the array that you want to append in because the method will always append
 * values from the starting index.
 */

#ifndef PROJECT4_INFEST_H
#define PROJECT4_INFEST_H
#include "gridFlea.h"


class inFest {
private:
    unsigned size;
    gridFlea* fleaArray;
    gridFlea values_generator(int num_generator, unsigned num);

public:
    inFest(unsigned x, unsigned totalObject);
    inFest(const inFest& newFlea); //copy constructor
    inFest& operator=(const inFest& newFlea); //copy assignment
    ~inFest(); //destructor
    inFest(inFest&& newFlea); //move constructor
    inFest &operator=(inFest&& newFlea); //move assignment

    inFest operator+(const inFest &rhs) const;
    inFest &operator+=(const inFest &rhs);
    inFest operator+(const gridFlea &rhs) const;
    inFest &operator+=(const gridFlea &rhs);

    bool operator<(const inFest &rhs) const;
    bool operator>(const inFest &rhs) const;
    bool operator==(const inFest &rhs) const;
    bool operator!=(const inFest &rhs) const;
    bool operator>=(const inFest &rhs) const;
    bool operator<=(const inFest &rhs) const;

    void appendArray(gridFlea gridObj);
    void move(int p);
    int minValue();
    int maxValue();
    int getValue();
    int getSize() const;
};


#endif //PROJECT4_INFEST_H
