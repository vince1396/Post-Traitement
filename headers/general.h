//
// Created by vincent on 09/05/19.
//

#include "Point.h"
#include "../model/ArrayPoint.h"
#include <vector>

#ifndef POST_TRAITEMENT_FUNCTIONS_H
#define POST_TRAITEMENT_FUNCTIONS_H

#endif //POST_TRAITEMENT_FUNCTIONS_H

double calculDistance(double long1, double lat1, double long2, double lat2);
double convertDegreesToRadians(double degrees);
void lambdasCreation(ArrayPoint *arrayPoint, std::vector<ArrayPoint> *vector);
void displayLambdas(std::vector<ArrayPoint> *vector);
void getLambdasByFour(std::vector<ArrayPoint> *lambdasContainer, std::vector<ArrayPoint> *fourLambdas);
void makeMediane(std::vector<ArrayPoint> *fourLambdas, ArrayPoint *arrayMediane);