cmake_minimum_required(VERSION 3.20)
project(lab06)

set(CMAKE_CXX_STANDARD 14)

include_directories(../lab04/include)
#add_library(gcdLib ../lab04/src/GCDHelder.cpp ../lab04/include/GCDHelder.h)

add_library(lab06 src/NumberDecompositionHelper.cpp src/NumberDecompositionHelper.h)
target_link_libraries(lab06)

add_executable(main main.cpp)
target_link_libraries(main)