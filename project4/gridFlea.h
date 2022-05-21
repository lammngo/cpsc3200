//
// Created by lolita kim on 5/12/22.
//
/** Interface invariants: *updating new changes only
 *
 * PUBLIC & PRIVATE METHODS:
 * - an gridFlea object was added a permanentlyDeactivated state check, this boolean will ensure that whenever the gridFlea
 * went out of bound, it will have one chance to jump outside of the bound.
 * - along with the permanentlyDeactivated state check, i also added a boundChecking() method to facilitate the overloaded
 * operators down the way.
 * - there is a small chance inside the gridFlea move() function that is whenever gridFlea is out of bound, it will trigger
 * the permanentlyDeactivated state check but this time instead of shutting it down, deactivated gridFlea can jump one more
 * step outside of the bound with less than z steps away from the bound.
 *
 * OVERLOADED OPERATORS:
 * - gridFlea can be added by a desired number of steps (int), this basically means how many steps that you want your gridFlea to move
 * - you can also add or subtract 2 gridFleas together
 * - you can compare the 2 gridFleas
 * - gridFlea has pre-increment and post-increment supported, these 2 methods basically move gridFlea up by 1.
 *
 */

#ifndef PROJECT4_GRIDFLEA_H
#define PROJECT4_GRIDFLEA_H

class gridFlea {
private:
    int x, y, count;
    int size, energeticPoint, activePoint;
    bool isEnergetic, isActive, permanentlyDeactivated;
    bool hasJumped = false;
    int reward = 69;
    int INITIAL_X = 0;
    int INITIAL_Y = 0;
    bool boundChecking() const;
public:
    gridFlea();
    gridFlea(int energeticPoint, int activePoint, int size);
    void move(int p);
    void revive();
    int value() const;
    void reset();
    bool getActiveStatus() const;

    gridFlea operator+(int rhs) const;
    gridFlea operator+=(int rhs);
    gridFlea operator-(int rhs) const;
    gridFlea operator-=(int rhs);
    gridFlea &operator++();
    gridFlea operator++(int );

    gridFlea operator+(const gridFlea &rhs) const;
    gridFlea &operator+=(const gridFlea &rhs);
    gridFlea operator-(const gridFlea &rhs) const;
    gridFlea &operator-=(const gridFlea &rhs);

    bool operator<(gridFlea &rhs) const;
    bool operator>(gridFlea &rhs) const;
    bool operator==(gridFlea &rhs) const;
    bool operator!=(gridFlea &rhs) const;
    bool operator>=(gridFlea &rhs) const;
    bool operator<=(gridFlea &rhs) const;

};
#endif //PROJECT4_GRIDFLEA_H
