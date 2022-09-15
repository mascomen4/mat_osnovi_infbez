cmake_minimum_required(VERSION 3.20)
project(lab01)

set(CMAKE_CXX_STANDARD 14)

add_library(lab01 src/CipherHelper.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main lab01)

