//
// Created by vincent on 23/05/19.
//

#include <iostream>
#include "ArrayPoint.h"
#include "../headers/general.h"

// =====================================================================================================================
ArrayPoint::ArrayPoint(int max) {

    this->mNbElem = 0;
    this->ArrayPoint::mMax = max;
    this->ArrayPoint::mArray = new Point[max];
    this->ArrayPoint::mArray[0].setDistanceCumulee(0.0);
}
// =====================================================================================================================
int ArrayPoint::getNbElem() const {
    return this->mNbElem;
}

Point ArrayPoint::getPoint(int i) {

    Point point = mArray[i];
    return point;
}

int ArrayPoint::getMax() {

    return this->mMax;
}
// =====================================================================================================================
void ArrayPoint::insert(const Point &point) {

    this->mArray[this->mNbElem] = point;
    this->mNbElem++;
}

void ArrayPoint::displayArray() {

    for(int i = 0; i < this->mMax; i++)
    {
        this->mArray[i].displayPoint();
    }
}

void ArrayPoint::makeDistanceCumulee() {

    for(int i = 0; i < this->mMax; i++)
    {
        double xA = this->mArray[i].getLong();
        double yA = this->mArray[i].getLat();
        double xB = this->mArray[i+1].getLong();
        double yB = this->mArray[i+1].getLat();
        double distance = calculDistance(xA, yA, xB, yB);
        double dc = (distance) + this->mArray[i].getDistanceCumulee();
        this->mArray[i+1].setDistanceCumulee(dc);
    }
}

