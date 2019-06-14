//
// Created by vincent on 09/05/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#include "../headers/general.h"
#include "../headers/Point.h"

const double pi = 4.0*atan(1.0);
const double rayonTerre = 6356.7523;
const double lambda800  = 3.75; // Mètres
const double lambda900  = 3.33; // Mètres
const double lambda1800 = 1.67; // Mètres
const double lambda2100 = 1.43; // Mètres
const double lambda2300 = 1.30; // Mètres
const double lambda2600 = 1.12; // Mètres

double calculDistance(double long1, double lat1, double long2, double lat2)
{
    double dLong1 = convertDegreesToRadians(long1);
    double dLong2 = convertDegreesToRadians(long2);
    double dLat1 =  convertDegreesToRadians(lat1);
    double dLat2 =  convertDegreesToRadians(lat2);

    double dLat = (dLat2) - (dLat1);
    double dLong = (dLong2) - (dLong1);

    double a = pow(sin((dLat)/2.0),2.0)
               + pow(sin((dLong)/2.0),2.0)
               * cos((dLat1))
               * cos((dLat2));

    double c = 2.0 * asin(sqrt((a)));

    double d = rayonTerre * (c);

    return d;
}

double convertDegreesToRadians(double degrees)
{
    double radians = (degrees) * (M_PI/180);

    return radians;
}

void lambdasCreation(ArrayPoint *arrayPoint, std::vector<ArrayPoint> *vector)
{
    double limit = lambda800;
    std::vector<Point> tempPoint;

    for(int i = 0; i < arrayPoint->getMax(); i++)
    {
        if(arrayPoint->getPoint(i).getDistanceMetre() >= limit || i == arrayPoint->getMax())
        {
            ArrayPoint grappe(tempPoint.size());
            for(const auto & j : tempPoint)
            {
                grappe.insert(j);
            }
            vector->push_back(grappe);
            tempPoint.clear();
            tempPoint.resize(0);
            tempPoint.push_back(arrayPoint->getPoint(i));
            limit += lambda800;
        }
        else
        {
            tempPoint.push_back(arrayPoint->getPoint(i));
        }
    }
}

void displayLambdas(std::vector<ArrayPoint> *vector)
{
    int j = 1;
    for(auto & i : *vector)
    {
        std::cout << j << std::endl;
        i.getPoint(0).displayPoint();
        j++;
    }
}

void medianeFromLambdas(std::vector<ArrayPoint> *vector) {

    unsigned int tempSize = 0;
    for(int i = 0; i < vector->size(); i + 4)
    {
        for(int j = 0;  j < 3; j++)
        {
            tempSize += vector->at(i + j).getMax();
        }
        ArrayPoint arrayPoint(tempSize);
    }
}