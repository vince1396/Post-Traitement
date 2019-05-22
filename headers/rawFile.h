//
// Created by vincent on 20/05/19.
//

#include "Point.h"

#ifndef POST_TRAITEMENT_RAWFILE_H
#define POST_TRAITEMENT_RAWFILE_H

#endif //POST_TRAITEMENT_RAWFILE_H

void goToDataStart(std::ifstream& fileFlow, std::string& line);
void excludeNullData(std::ifstream &fileFlow, std::string &line, std::vector<std::string> &lineTab);
void createPointFromRaw(std::vector<std::string>& vector, std::vector<Point>& pointTab);