//
// Created by lolita kim on 5/12/22.
//

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
public:
    gridFlea();
    gridFlea(int energeticPoint, int activePoint, int size);
    void move(int p);
    void revive();
    int value();
    void reset();
    bool getActiveStatus();
};


#endif //PROJECT4_GRIDFLEA_H
