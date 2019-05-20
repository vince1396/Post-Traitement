//
// Created by vincent on 20/05/19.
//

#include <iostream>
#include "../headers/View.h"

void View::displayScriptStart() {

    std::cout << "\n=====================" <<  std::endl;
    std::cout << "Script starting..." <<       std::endl;
    std::cout << "===================== \n" << std::endl;
}

void View::successOpenFile(const std::string& filePath) {

    std::cout << "| - File opened with success ("+ filePath +") \n" << std::endl;
}

void View::errorOpenFile(const std::string& filePath) {

    std::cerr << "| - File couldn't be opened ("+filePath+")" << std::endl;
}
