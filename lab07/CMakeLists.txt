cmake_minimum_required(VERSION 3.20)
project(lab07)

set(CMAKE_CXX_STANDARD 14)

add_library(primeNumsLib ../lab05/src/PrimeNumbersHelper.cpp ../lab05/inlcude/PrimeNumbersHelper.h)
include_directories(../lab05/include)

add_library(lab07 src/DicreteLogarithmHelper.cpp include/DicreteLogarithmHelper.h)
target_link_libraries(lab07 primeNumsLib)

add_executable(main src/main.cpp)
