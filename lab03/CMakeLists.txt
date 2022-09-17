cmake_minimum_required(VERSION 3.20)
project(lab03)

set(CMAKE_CXX_STANDARD 14)

add_library(lab03Lib include/CipherFiniteGammaHelper.h src/CipherFiniteGammaHelper.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main lab03Lib)

