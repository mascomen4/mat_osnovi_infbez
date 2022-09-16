cmake_minimum_required(VERSION 3.20)
project(lab02)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3)
add_library(lab02 src/CipherHelper2.cpp include/CipherHelper2.h)
target_link_libraries(lab02 Eigen3)

add_executable(main src/main.cpp)
target_link_libraries(main lab02)
