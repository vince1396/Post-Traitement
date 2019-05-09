cmake_minimum_required(VERSION 3.14)
project(Post_Traitement)

set(CMAKE_CXX_STANDARD 14)

add_executable(Post_Traitement main.cpp core/functions.cpp headers/functions.h model/Point.cpp headers/Point.h)