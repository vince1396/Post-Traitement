//
// Created by vincent on 20/05/19.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../headers/rawFile.h"

/*
 * This file contains methods that can be use on the first step of the
 * Post-Processing process, meaning, the file that contains raw data (.asc), before
 * anything is done to them.
 */

// Place virtual cursor at the first line to process
void goToDataStart(std::ifstream& fileFlow)
{
    std::string line;

    while(getline(fileFlow, line))
    {
        if(line == "[DATA]")
        {
            getline(fileFlow, line);
            break;
        }
    }
}

/*
 * Push into a vector every lines that does not contain a '?'
 * Basically, we sort the data to keep only the lines where all the infos exist
 */
void excludeNullData(std::ifstream &fileFlow, std::string &line, std::vector<std::string> &lineTab)
{
    while(getline(fileFlow, line))
    {
        if(line.find('?') == std::string::npos)
        {
            lineTab.push_back(line);
        }
    }
}

/*
 * The first vector represents the raw lines of data after we sorted them.
 * The second vector is an empty vector in which we will stored each line after we transform it into a Point object
 */
void createPointFromRaw(std::vector<std::string>& vector, std::vector<Point>& pointTab)
{
    for(const auto & i : vector)
    {
        int sizeV = 12; // There is 12 fields in a Point object
        std::string rawData[sizeV]; //String tab

        std::string string = i;
        int cursor(0);
        int cursor2;

        for(int j(0); j < sizeV; j++)
        {
            std::string separator = ";";

            if(j == 0 || j == 1)
                separator = ":";

            if(j == 2)
                separator = ".";

            cursor2 = string.find(separator, cursor);
            rawData[j] = string.substr(0, cursor2);
            string = string.substr(cursor2+1);
        }

        Point point;

        point.setHour(std::stoi(rawData[0]));
        point.setMinute(std::stoi(rawData[1]));
        point.setSecond(std::stoi(rawData[2]));
        point.setMs(std::stoi(rawData[3]));
        point.setLong(std::stod(rawData[4]));
        point.setLat(std::stod(rawData[5]));
        point.setF1(std::stod(rawData[6]));
        point.setF2(std::stod(rawData[7]));
        point.setF3(std::stod(rawData[8]));
        point.setF4(std::stod(rawData[9]));
        point.setF5(std::stod(rawData[10]));
        point.setF6(std::stod(rawData[11]));

        pointTab.push_back(point);
    }
}