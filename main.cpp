#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include "headers/functions.h"
#include "headers/Point.h"

int main() {

    // ===================== VIEW ======================
    std::cout << "\n=====================" <<  std::endl;
    std::cout << "Script starting..." <<       std::endl;
    std::cout << "===================== \n" << std::endl;
    // =================================================

    // Absolute path of the file to process
    std::string const filePath("/home/vincent/CLionProjects/Post-Traitement/mesures/mesure1.asc");

    // Opening file in read mode
    std::ifstream fileFlow(filePath.c_str(), std::ios::in);

    // If file opening went well
    if(fileFlow)
    {
        // =============================================================================================================
        std::cout << "| - File opened with success ("+ filePath +") \n" << std::endl;

        std::string line;
        std::vector<std::string> lineTab(1);

        goToDataStart(fileFlow, line);
        excludeNullData(fileFlow, line, lineTab);
        displayVector(lineTab);

        Point test{};

        fileFlow.close();
        // =============================================================================================================
    }
    else // If an error occured during file opening
    {
        // Display error message
        std::cerr << "| - File couldn't be opened ("+filePath+")" << std::endl;
    }

    return 0;
}