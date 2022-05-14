//
// Created by lolita kim on 5/12/22.
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

int gridFlea::value() {
    if (permanentlyDeactivated) {
        return -1;
    } else if (!isActive) {
        return 0;
    } else {
        int change = abs(INITIAL_X - x) + abs(INITIAL_Y - y);
        return (reward - count) * size * change;
    }
}

bool gridFlea::getActiveStatus() {
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
