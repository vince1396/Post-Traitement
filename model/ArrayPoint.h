//
// Created by vincent on 23/05/19.
//

#ifndef POST_TRAITEMENT_ARRAYPOINT_H
#define POST_TRAITEMENT_ARRAYPOINT_H

#include "../headers/Point.h"

class ArrayPoint {

public:

    explicit ArrayPoint(int max);
    void insert(Point *point);

private:

    int nbElem;
    Point *arr[];

    int getNbElem() const;
    Point *const *getArr() const;
};

#endif //POST_TRAITEMENT_ARRAYPOINT_H