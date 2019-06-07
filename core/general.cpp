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

const double pi = 3.14159265358979323846;
const double rayonTerre = 6356.7523;
const double lambda800  = 3.75; // Mètres
const double lambda900  = 3.33; // Mètres
const double lambda1800 = 1.67; // Mètres
const double lambda2100 = 1.43; // Mètres
const double lambda2300 = 1.30; // Mètres
const double lambda2600 = 1.12; // Mètres

double calculDistance(double xA, double yA, double xB, double yB)
{
    xA = convertDegreesToRadians(xA);
    xB = convertDegreesToRadians(xB);
    yA = convertDegreesToRadians(yA);
    yB = convertDegreesToRadians(yB);

    double deltaPhi = yB - yA;
    double deltaLambda = xB - xA;

    double a = sin(deltaPhi/2) * sin(deltaPhi/2)
               + cos(xA) * cos(xB)
               * sin(deltaLambda/2) * sin(deltaLambda/2);

    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double d = rayonTerre * c;

    return d;
}

double convertDegreesToRadians(double degrees)
{
    double radians = degrees * (pi/180);

    return radians;
}

void lambdasCreation(ArrayPoint *arrayPoint, std::vector<ArrayPoint> *vector)
{
    double limit = lambda800;
    std::vector<Point> tempPoint;

    for(int i = 0; i < arrayPoint->getMax(); i++)
    {
        /*std::cout << arrayPoint->getMax() << std::endl;
        std::cout << limit << std::endl;
        std::cout << tempPoint.size() << std::endl;
        std::cout << arrayPoint->getPoint(i).getDistanceMetre() << "\n" << std::endl;*/
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
    for(auto & i : *vector)
    {
        i.getPoint(0).displayPoint();
    }
}