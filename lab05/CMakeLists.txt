cmake_minimum_required(VERSION 3.20)
project(lab05)

set(CMAKE_CXX_STANDARD 14)

add_library(lab05 src/PrimeNumbersHelper.cpp inlcude/PrimeNumbersHelper.h)

add_executable(main main.cpp)
target_link_libraries(main lab05)
