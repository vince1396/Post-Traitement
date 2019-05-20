//
// Created by vincent on 09/05/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

void createPoint(std::vector<std::string>& vector, std::vector<Point>& pointTab)
{
    for(const auto & i : vector)
    {
        int sizeV = 12;
        std::string rawData[sizeV];

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



void displayAllPoints(std::vector<Point>& vector)
{
    for(auto & i : vector)
    {
        i.displayPoint();
    }
}