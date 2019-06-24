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

        std::vector<std::string> optimizedData;          // Will contains each line of the optimized txt file
        std::vector<ArrayPoint> lambdasContainer;        // Will store ArrayPoint after making lambdas
        std::vector<ArrayPoint> fourLambdas;

        getOptimizedData(fileFlow, optimizedData);       // We store the lines in the container
        ArrayPoint arrayPoint(optimizedData.size());     // Creation of the ArrayPoint containing all the points from the file

        createPointFromOD(&optimizedData, &arrayPoint);  // Creation of the Points and inserting on the array
        arrayPoint.makeDistanceCumulee();                // Cumulated distance calcul for each point

        lambdasCreation(&arrayPoint, &lambdasContainer); // Making lambdas groups, depending on the frequency
        getLambdasByFour(&lambdasContainer, &fourLambdas);

        ArrayPoint arrayMediane(fourLambdas.size());
        makeMediane(&fourLambdas, &arrayMediane);
        //arrayMediane.displayArray();

        std::string const path("/home/vincent/CLionProjects/Post-Traitement/mesures/result");
        std::ofstream writting(path, std::ios::out | std::ios::app);

        if(writting)
        {
            std::cout << "Starting writting..." << std::endl;

            for(int i = 0; i < arrayMediane.getNbElem(); i++)
            {
                writting
                << "\t Time \t"
                << "RSSI \t"
                << "Long \t"
                << "Lat \n\n"
                << i
                << " -| "
                << "\t"
                << arrayMediane.getPoint(i).getHour()
                << ":"
                << arrayMediane.getPoint(i).getMinute()
                << ":"
                << arrayMediane.getPoint(i).getSecond()
                << "\t"
                << arrayMediane.getPoint(i).getF1()
                << "\t"
                << arrayMediane.getPoint(i).getLong()
                << "\t"
                << arrayMediane.getPoint(i).getLat()
                << "\n";
            }
            writting.close();
        }
        else
        {
            std::cerr << "Error writting" << std::endl;
        }

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