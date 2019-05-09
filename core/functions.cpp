//
// Created by vincent on 09/05/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../headers/functions.h"

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