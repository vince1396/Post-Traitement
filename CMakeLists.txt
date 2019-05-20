cmake_minimum_required(VERSION 3.14)
project(Post_Traitement)

set(CMAKE_CXX_STANDARD 14)

add_executable(Post_Traitement main.cpp core/general.cpp headers/general.h model/Point.cpp headers/Point.h core/rawFile.cpp headers/rawFile.h model/View.cpp headers/View.h core/optimizedTxtFile.cpp headers/optimizedTxtFile.h)