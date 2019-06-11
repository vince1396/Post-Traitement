//
// Created by vincent on 20/05/19.
//

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../headers/optimizedTxtFile.h"
#include "../model/ArrayPoint.h"

/*
 * This file contains methods that can be used on the second step of the
 * Post-Processing process, on a .txt file.
 */


/*
 * Methods that stores each line of the file in a vector
 */
void getOptimizedData(std::ifstream &fileFlow, std::vector<std::string> &vector)
{
    std::string line;

    while(getline(fileFlow, line))
    {
        vector.push_back(line);
    }
}

/*
 * We transform each line of a vector in a Point object and store them in another vector
 */
void createPointFromOD(std::vector<std::string> * vector, ArrayPoint *arrayPoint)
{
    for(const auto & i : *vector)
    {
        Point point;
        point.setHour(stoi(i.substr(1, 2)));
        point.setMinute(stoi(i.substr(4, 2)));
        point.setSecond(stoi(i.substr(7, 2)));

        std::string tab[3];
        std::string string = i.substr(i.find_first_of('\t'));
        string = string.substr(string.find_first_not_of('\t'));

        for(int j = 0; j < 3; j++)
        {
            if(j == 2)
                tab[j] = string;

            if(j < 2)
            {
                tab[j] = string.substr(0, string.find_first_of('\t'));
                string = string.substr(string.find_first_of('\t'));
                string = string.substr(string.find_first_not_of('\t'));
            }
        }

        point.setF1(stod(tab[0]));
        point.setLat(stod(tab[1]));
        point.setLong(stod(tab[2]));

        arrayPoint->insert(point);
    }
}