//
// Created by vincent on 09/05/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../headers/functions.h"
#include "../headers/Point.h"

// Place virtual cursor at the first line to process
void goToDataStart(std::ifstream& fileFlow, std::string& line)
{
    while(getline(fileFlow, line))
    {
        if(line == "[DATA]")
        {
            getline(fileFlow, line);
            break;
        }
    }
}

// Push into a vector every lines that does not contain a '?'
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
    int j = 0;
    for(const auto & i : vector)
    {
        j++;

        std::string string;
        int cursor = 0;
        int cursor2;

        cursor2 = i.find(':', cursor);
        int hour = std::stoi(i.substr(0, cursor2));
        string = i.substr(cursor2+1);

        cursor2 = string.find(':', cursor);
        int minute = std::stoi(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find('.', cursor);
        int second = std::stoi(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        int ms = std::stoi(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double mLong = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double lat = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double f1 = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double f2 = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double f3 = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double f4 = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double f5 = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        cursor2 = string.find(';', cursor);
        long double f6 = std::stod(string.substr(0, cursor2));
        string = string.substr(cursor2+1);

        //Point point(hour, minute, second, ms, mLong, lat, f1, f2, f3, f4, f5, f6);
        Point point(hour, minute, second, ms, mLong, lat, f1, f2, f3, f4, f5, f6);
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