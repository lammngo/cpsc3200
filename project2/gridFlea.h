/* revision 2:
 * - added no-argument constructor in gridFlea class
 * - added guard checking if reset is called on a permanently deactivated object (in which checked for the object state
 * in whether it is inactive or permanently deactivated)
 */
#ifndef PROJECT2_GRIDFLEA_H
#define PROJECT2_GRIDFLEA_H

class gridFlea {
private:
    int x, y, count;
    int size, energeticPoint, activePoint;
    bool isEnergetic, isActive;
    int reward = 69;
    int INITIAL_X = 0;
    int INITIAL_Y = 0;
public:
    gridFlea();
    gridFlea(int energeticPoint, int activePoint, int size);
    void move(int p);
    void revive();
    int value();
    void reset();
};


#endif //PROJECT2_GRIDFLEA_H
