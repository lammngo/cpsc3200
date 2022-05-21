//
// Created by lolita kim on 5/12/22.
//
/**
 * Implementation invariants: *updated version of p2
 * PUBLIC METHODS:
 * - as the previous p2, when the gridFlea out of bound its state will be set to permanentlyDeactivated and it will be
 * shut down, obviously revive() is unavailable as well if the object is permanentlyDeactivated
 * - however, now, deactivated gridFlea can jump at most 1 jump outside the bound, and this jump MUST be no more than
 * z squares.
 * - new state was created, which is hasJump, and how this works is whenever the object is at permanentlyDeactivated and
 * it has not jumped yet, then that means the object is valid to have its first and final jump. After the jump, we need
 * to check the condition in which the jump has to be less than z squares by comparing the (count+p) with (size+z)
 * - every gridFlea only has ONE jump no matter how big the jump is, if the jump is less than the z squares (in which
 * satisfied the condition) the hasJump state will be changed to true and it will stop the gridFlea from making the second
 * jump outside the bound. if the jump is bigger than z squares, then it will return.
 * - getActiveStatus(): this function was added to keep the inActive status in check
 * PRIVATE METHOD:
 * - boundChecking(): this helper function will keep track of the permanentlyDeactivated state and very helpful for the
 * addition and subtraction overloaded operators where you add/subtract 2 gridFleas together so it's necessary to keep
 * track of the state for each gridFlea after the new move.
 *
 * OVERLOADED OPERATORS:
 * (+) ADDITIONS: *same idea with SUBTRACTIONS
 * - add gridFlea with an int: this basically move gridFlea with int steps
 * - add 2 gridFleas together:
 * + gridFlea MUST be active and not permanentlyDeactivated to be qualified. i used getActiveStatus()
 * and boundChecking() to do the work here as the guard checking.
 * + after adding 2 gridFleas together by adding x and y of the source object to x and y of the rhs object, we need to check
 * for the state of the object again in whether it went out of the bound and became inactive or permanentlyDeactivated or
 * not.
 *
 * (=) RELATIONS:
 * - comparing the values of 2 gridFleas, pretty straightforward. you only need to use the value() method to do this.
 */
#include "gridFlea.h"
#include <iostream>

using namespace std;

gridFlea::gridFlea() {
    this->x = INITIAL_X;
    this->y = INITIAL_Y;
    this->count = 0;
    this->energeticPoint = 0;
    this->activePoint = 0;
    this->size = 0;
    this->isEnergetic = true;
    this->isActive = true;
    this->permanentlyDeactivated = false;
}

gridFlea::gridFlea(int energeticPoint, int activePoint, int size) {
    this->x = INITIAL_X;
    this->y = INITIAL_Y;
    this->count = 0;
    this->energeticPoint = energeticPoint;
    this->activePoint = activePoint;
    this->size = size;
    this->isEnergetic = true;
    this->isActive = true;
    this->permanentlyDeactivated = false;
}

void gridFlea::move(int p) {
    int z = abs(p / 2);
    if (permanentlyDeactivated && !hasJumped) {
        x += p;
        y += p;
        count += p;
        hasJumped = true;
    } else if (!isActive) {
        return;
    }
    if (hasJumped && (count + p > size + z)) {
        return;
    }
    if (isEnergetic) {
        x += p;
        y += p;
        count += p;
    } else {
        x++;
        y++;
        count++;
    }
    isEnergetic = count < energeticPoint;
    isActive = count <= activePoint && count <= size;
    permanentlyDeactivated = count > size;
}

void gridFlea::revive() {
    if (isActive || permanentlyDeactivated) {
        return;
    }
    isActive = true;
    count = 0;
}

int gridFlea::value() const{
    if (permanentlyDeactivated) {
        return -1;
    } else if (!isActive) {
        return 0;
    } else {
        int change = abs(INITIAL_X - x) + abs(INITIAL_Y - y);
        return (reward - count) * size * change;
    }
}

bool gridFlea::getActiveStatus() const {
    return isActive;
}

void gridFlea::reset() {
    if (isActive || permanentlyDeactivated) {
        return;
    }
    x = INITIAL_X;
    y = INITIAL_Y;
    isEnergetic = true;
    isActive = true;
    count = 0;
}

bool gridFlea::boundChecking() const {
    return abs(x) > size || abs(y) > size;
}

gridFlea gridFlea::operator+(int rhs) const {
    gridFlea temp(*this);
    temp.move(rhs);
    return temp;
}

gridFlea gridFlea::operator+=(int rhs){
    move(rhs);
    return *this;
}

gridFlea gridFlea::operator-(int rhs) const {
    gridFlea temp(*this);
    temp.move(-rhs);
    return temp;
}

gridFlea gridFlea::operator-=(int rhs) {
    move(-rhs);
    return *this;
}

gridFlea &gridFlea::operator++() { // move the gridFlea by 1
    move(1);
    return *this;
}

gridFlea gridFlea::operator++(int ) {
    gridFlea oldFlea(*this);
    this->move(1);
    return oldFlea;
}

/**
 * Post-condition:
 * - The overloaded operators in which adding or subtracting the 2 gridFleas together will add or subtract elements
 * that encapsulated inside gridFlea (x and y) with another x and y of the second gridFlea, which means it is not adding
 * or subtracting 2 gridFlea values, thus, the final results would be slightly off due to the formula of calculating
 * the value of gridFlea (value() method).
 * - When using these operands, especially the subtraction ones, make sure to assume the negative(-) sign before the final
 * results and treat it as the object moving backwards (since you're doing subtraction, which mean the object will move
 * backwards p squares), and it actually did move backwards, however, since the gridFlea value() function always return
 * positive values, it is needed to add the subtraction sign before the return new gridFlea value to imply that
 * gridFlea is moving backwards. (i did implement this in the client file under the subtraction tests for gridFleas)
 *
 */
gridFlea gridFlea::operator+(const gridFlea &rhs) const {
    gridFlea temp(*this);
    if(!temp.getActiveStatus() || boundChecking()){
        return temp;
    }
    temp.x += rhs.x;
    temp.y += rhs.y;
    return temp;
}

gridFlea &gridFlea::operator+=(const gridFlea &rhs) {
    if(!getActiveStatus() || boundChecking()){
        return *this;
    }
    x += rhs.x;
    y += rhs.y;
    return *this;
}

gridFlea gridFlea::operator-(const gridFlea &rhs) const {
    gridFlea temp(*this);
    if(!temp.getActiveStatus() || boundChecking()){
        return temp;
    }
    temp.x -= rhs.x;
    temp.y -= rhs.y;
    return temp;
}

gridFlea &gridFlea::operator-=(const gridFlea &rhs) {
    if(!getActiveStatus() || boundChecking()){
        return *this;
    }
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

bool gridFlea::operator==(gridFlea &rhs) const{
    return this->value() == rhs.value();
}

bool gridFlea::operator!=(gridFlea &rhs) const{
    return this->value() != rhs.value();
}

bool gridFlea::operator>(gridFlea &rhs) const{
    return this->value() > rhs.value();
}

bool gridFlea::operator<(gridFlea &rhs) const{
    return this->value() < rhs.value();
}

bool gridFlea::operator>=(gridFlea &rhs) const{
    return this->value() >= rhs.value();
}

bool gridFlea::operator<=(gridFlea &rhs) const{
    return this->value() <= rhs.value();
}
