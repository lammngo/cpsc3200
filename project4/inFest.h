//
// Created by lolita kim on 5/12/22.
//

#ifndef PROJECT4_INFEST_H
#define PROJECT4_INFEST_H
#include "gridFlea.h"


class inFest {
private:
    int size;
    gridFlea* fleaArray;
    gridFlea values_generator(int num_generator, int num);

public:
    inFest(int x, int totalObject);
    inFest(const inFest& newFlea); //copy constructor
    inFest& operator=(const inFest& newFlea); //copy assignment
    ~inFest(); //destructor
    inFest(inFest&& newFlea); //move constructor
    inFest &operator=(inFest&& newFlea); //move assignment

    inFest operator+(const inFest &rhs) const;
    inFest &operator+=(const inFest &rhs);
    inFest operator+(const gridFlea &rhs) const;
    inFest &operator+=(const gridFlea &rhs);
    inFest &operator++();
    inFest operator++(int x);
    gridFlea const &operator[](int index) const;


    void appendArray(gridFlea gridObj);
    void move(int p);
    int minValue();
    int maxValue();
};


#endif //PROJECT4_INFEST_H
