//
// Created by vincent on 09/05/19.
//

#include "Point.h"

#ifndef POST_TRAITEMENT_FUNCTIONS_H
#define POST_TRAITEMENT_FUNCTIONS_H

#endif //POST_TRAITEMENT_FUNCTIONS_H

void goToDataStart(std::ifstream& fileFlow, std::string& line);
void excludeNullData(std::ifstream &fileFlow, std::string &line, std::vector<std::string> &lineTab);
void displayVector(std::vector<std::string>& vector);
void createPoint(std::vector<std::string>& vector, std::vector<Point>& pointTab);
void displayAllPoints(std::vector<Point>& vector);