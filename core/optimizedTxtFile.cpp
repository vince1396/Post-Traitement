//
// Created by vincent on 20/05/19.
//

#include <string>
#include <vector>
#include <fstream>
#include "../headers/optimizedTxtFile.h"

void getOptimizedData(std::ifstream &fileFlow, std::vector<std::string> &vector)
{
    std::string line;

    while(getline(fileFlow, line))
    {
        vector.push_back(line);
    }
}