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
        if(arrayPoint->getPoint(i).getDistanceMetre() >= limit || i > arrayPoint->getMax())
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
        std::cout << i.getNbElem() << std::endl;
        i.getPoint(0).displayPoint();
        j++;
    }
}

void getLambdasByFour(std::vector<ArrayPoint> *lambdasContainer, std::vector<ArrayPoint> *fourLambdas) {

    int controller = 0;
    std::vector<Point> temp;
    for(auto & i : *lambdasContainer)
    {
        if(controller == 3)
        {
            ArrayPoint arrayPoint(temp.size());
            for(const auto & k : temp)
            {
                arrayPoint.insert(k);
            }
            fourLambdas->push_back(arrayPoint);

            controller = 0;
            temp.clear();
        }
        else
        {
            for(int j = 0; j < i.getNbElem(); j++)
            {
                temp.push_back(i.getPoint(j));
            }
            controller++;
        }
    }
}

void makeMediane(std::vector<ArrayPoint> *fourLambdas, ArrayPoint *arrayMediane) {

    for(auto & i : *fourLambdas)
    {
        i.quickSort();
        arrayMediane->insert(i.calculMediane());
    }
}