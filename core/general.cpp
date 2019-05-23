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

// Display all data in a vector
void displayVector(std::vector<std::string>& vector)
{
    for(const auto & i : vector)
    {
        std::cout << i << std::endl;
    }
}

// Calls Point::displayPoints methods on each Point object contained in a vector
void displayAllPoints(std::vector<Point>& vector)
{
    for(auto & i : vector)
    {
        i.displayPoint();
    }
}

double calculDistance(double xA, double yA, double xB, double yB)
{
    double AB = sqrt(pow(xB - xA, 2)) + sqrt(pow(yB - yA, 2));
    return AB;
}