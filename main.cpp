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

    float time;
    clock_t t1, t2;

    t1 = clock();

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
        std::vector<ArrayPoint> lambdasContainer;  // Will store ArrayPoint after making lambdas

        getOptimizedData(fileFlow, optimizedData);    // We store the lines on the container
        ArrayPoint arrayPoint(optimizedData.size());  // Creation of the ArrayPoint containing all the points from the file

        createPointFromOD(&optimizedData, &arrayPoint);// Creation of the Points and inserting on the array
        arrayPoint.makeDistanceCumulee(); // Cumulated distance calcul for each point

        lambdasCreation(&arrayPoint, &lambdasContainer); // Making lambdas groups, depending on the frequency
        displayLambdas(&lambdasContainer);
        arrayPoint.quickSort();
        //arrayPoint.displayArray();

        fileFlow.close();
        // =============================================================================================================
    }
    else // If an error occured during file opening
    {
        // Display error message
        View::errorOpenFile(filePath);
    }

    t2 = clock();
    time = (float) (t2-t1) / CLOCKS_PER_SEC;

    std::cout << "\n\nExec : " << time << std::endl;

    return 0;
}