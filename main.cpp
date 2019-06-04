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
#include "model/ArrayPoint.h"

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

        std::vector<std::string> optimizedData;       // Will contains each line of the optimized txt file
        getOptimizedData(fileFlow, optimizedData);    // We store the lines on the container

        ArrayPoint arrayPoint(optimizedData.size());  // Creation of the ArrayPoint
        createPointFromOD(&optimizedData, arrayPoint);// Creation of the Points and inserting on the array
        arrayPoint.makeDistanceCumulee();
        arrayPoint.displayArray();                    // Displaying all the points

        std::vector<ArrayPoint> arrayPointContainer;

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