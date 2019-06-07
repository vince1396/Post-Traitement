//
// Created by vincent on 09/05/19.
//

#include "Point.h"
#include "../model/ArrayPoint.h"
#include <vector>

#ifndef POST_TRAITEMENT_FUNCTIONS_H
#define POST_TRAITEMENT_FUNCTIONS_H

#endif //POST_TRAITEMENT_FUNCTIONS_H

//void displayVector(std::vector<std::string>& vector);
//void displayAllPoints(std::vector<Point>& vector);
double calculDistance(double xA, double yA, double xB, double yB);
double convertDegreesToRadians(double degrees);
void lambdasCreation(ArrayPoint *arrayPoint, std::vector<ArrayPoint> *vector);
void displayLambdas(std::vector<ArrayPoint> *vector);
