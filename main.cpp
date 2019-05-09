#include <iostream>
#include <fstream>
#include <limits>

// Place virtual cursor at the first line to process
void goToDataStart(std::ifstream& fileFlow, std::string& line)
{
    while(getline(fileFlow, line))
    {
        if(line == "[DATA]")
        {
            std::getline(fileFlow, line);
            break;
        }
    }
}

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

    // If opening went well
    if(fileFlow)
    {
        // =============================================================================================================
        std::cout << "| - File opened with success ("+ filePath +") \n" << std::endl;

        std::string line;
        goToDataStart(fileFlow, line);
        std::cout << line << std::endl;

        fileFlow.close();
        // =============================================================================================================
    }
    else // If an error occured during file opening
    {
        // Display error message
        std::cerr << "| - File couldn't be opened" << std::endl;
    }

    return 0;
}