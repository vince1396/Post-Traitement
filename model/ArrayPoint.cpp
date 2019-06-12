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
    this->ArrayPoint::mRssi = 0.0;
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
// =====================================================================================================================
void ArrayPoint::quickSort() {

    recQuickSort(0, mMax);
}

void ArrayPoint::recQuickSort(int left, int right) {

    int size = right-left+1;
    if(size < 10)
        insertionSort(left, right);
    else
    {
        double median = medianOf3(left, right);
        int partition = partitionIt(left, right, median);
        recQuickSort(left, partition-1);
        recQuickSort(partition+1, right);
    }
}

double ArrayPoint::medianOf3(int left, int right) {

    int center = (left+right)/2;

    if(mArray[left].getF1() > mArray[center].getF1())
        swap(left, center);

    if(mArray[left].getF1() > mArray[right].getF1())
        swap(left, right);

    if(mArray[center].getF1() > mArray[right].getF1())
        swap(center, right);

    swap(center, right-1);
    return mArray[right-1].getF1();
}

void ArrayPoint::swap(int dex1, int dex2) {

    Point temp = mArray[dex1];
    mArray[dex1] = mArray[dex2];
    mArray[dex2] = temp;
}

int ArrayPoint::partitionIt(int left, int right, double pivot) {

    int leftPtr = left;
    int rightPtr = right-1;

    while(true)
    {
        while (mArray[++leftPtr].getF1() < pivot)
            ;
        while (mArray[--rightPtr].getF1() > pivot)
            ;
        if(leftPtr >= rightPtr)
            break;
        else
            swap(leftPtr, rightPtr);
    }
    swap(leftPtr, rightPtr-1);
    return leftPtr;
}

void ArrayPoint::insertionSort(int left, int right) {

    int in, out;

    for(out = left+1; out <= right; out++)
    {
        Point temp = mArray[out];
        in = out;

        while(in > left && mArray[in-1].getF1() >= temp.getF1())
        {
            mArray[in] = mArray[in-1];
            --in;
        }

        mArray[in] = temp;
    }
}