cmake_minimum_required(VERSION 3.30)
project(lb6_2024_11_30_1)

set(CMAKE_CXX_STANDARD 26)

FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(lb6_2024_11_30_1 main.cpp)
