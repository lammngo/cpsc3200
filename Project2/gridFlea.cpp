//
// Created by lolita kim on 4/11/22.
//

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
}
void gridFlea::move(int p) {
    if (!isActive)
    {
        return;
    }
    if (isEnergetic)
    {
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
}

void gridFlea::revive() {
    if (isActive || count > size)
    {
        return;
    }
    isActive = true;
    count = 0;
}

int gridFlea::value() {
    if (!isActive && count > size)
    {
        return -1;
    } else if (!isActive && count <= size)
    {
        return 0;
    }
    else
    {
        int change = abs(INITIAL_X - x) + abs(INITIAL_Y - y);
        return (reward - count) * size * change;
    }
}

void gridFlea::reset() {
    if (isActive || count > size)
    {
        return;
    }
    x = INITIAL_X;
    y = INITIAL_Y;
    isEnergetic = true;
    isActive = true;
    count = 0;
}
