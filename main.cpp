#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <math.h>
#include <iomanip>
#include "headers/general.h"
#include "headers/Point.h"
#include "headers/View.h"
#include "headers/optimizedTxtFile.h"

int main() {

    // ===================== VIEW ======================
    View::displayScriptStart();
    // =================================================

    // Absolute path of the file to process
    std::string const filePath("/home/vincent/CLionProjects/Post-Traitement/mesures/site2.txt");
    std::ifstream fileFlow(filePath, std::ios::in);


    // If file opening went well
    if(fileFlow)
    {
        // =============================================================================================================
        View::successOpenFile(filePath);

        std::vector<std::string> optimizedData;
        std::vector<Point> storedPoints;

        getOptimizedData(fileFlow, optimizedData);
        createPointFromOD(&optimizedData, &storedPoints);
        //displayVector(optimizedData);

        fileFlow.close();
        // =============================================================================================================
    }
    else // If an error occured during file opening
    {
        // Display error message
        View::errorOpenFile(filePath);
    }

    return 0;
}