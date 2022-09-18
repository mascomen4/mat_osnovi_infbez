cmake_minimum_required(VERSION 3.20)
project(lab04)

set(CMAKE_CXX_STANDARD 14)

add_library(lab04 src/GCDHelder.cpp include/GCDHelder.h)

add_executable(main main.cpp)
target_link_libraries(main lab04)