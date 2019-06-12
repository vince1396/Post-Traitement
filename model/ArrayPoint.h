//
// Created by vincent on 23/05/19.
//

#ifndef POST_TRAITEMENT_ARRAYPOINT_H
#define POST_TRAITEMENT_ARRAYPOINT_H

#include "../headers/Point.h"

class ArrayPoint {

public:

    // =================================================================================================================
    explicit ArrayPoint(int max);
    // =================================================================================================================
    int getNbElem() const;
    Point getPoint(int indice);
    int getMax();
    // =================================================================================================================
    void insert(const Point& point);
    void displayArray();
    void makeDistanceCumulee();
    // =================================================================================================================
    void quickSort();
    void recQuickSort(int left, int right);
    double medianOf3(int left, int right);
    void swap(int dex1, int dex2);
    int partitionIt(int left, int right, double pivot);
    void insertionSort(int left, int right);

private:

    int mMax;
    int mNbElem;
    Point *mArray;
    double mRssi;
};

#endif //POST_TRAITEMENT_ARRAYPOINT_H