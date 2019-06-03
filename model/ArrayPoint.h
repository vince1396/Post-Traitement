//
// Created by vincent on 23/05/19.
//

#ifndef POST_TRAITEMENT_ARRAYPOINT_H
#define POST_TRAITEMENT_ARRAYPOINT_H

#include "../headers/Point.h"

class ArrayPoint {

public:

    explicit ArrayPoint(int max);
    void insert(const Point& point);

    void displayArray();
    void makeDistanceCumulee();

private:

    int mMax;
    int mNbElem;
    Point *mArray;

    int getNbElem() const;
};

#endif //POST_TRAITEMENT_ARRAYPOINT_H