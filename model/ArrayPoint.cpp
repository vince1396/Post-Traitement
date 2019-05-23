//
// Created by vincent on 23/05/19.
//

#include "ArrayPoint.h"

ArrayPoint::ArrayPoint(int max) {

    ArrayPoint::nbElem = max;
}

int ArrayPoint::getNbElem() const {
    return nbElem;
}

Point *const *ArrayPoint::getArr() const {
    return arr;
}

void ArrayPoint::insert(Point *point) {

    ArrayPoint::arr[nbElem] = point;
    nbElem++;
}