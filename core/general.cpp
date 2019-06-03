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

// Display all data in a vector
/*void displayVector(std::vector<std::string>& vector)
{
    for(const auto & i : vector)
    {
        std::cout << i << std::endl;
    }
}*/

// Calls Point::displayPoints methods on each Point object contained in a vector
/*void displayAllPoints(std::vector<Point>& vector)
{
    for(auto & i : vector)
    {
        i.displayPoint();
    }
}*/

double calculDistance(double xA, double yA, double xB, double yB)
{
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
    double radians = degrees * pi/180;

    return radians;
}