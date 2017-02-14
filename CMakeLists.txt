cmake_minimum_required(VERSION 3.6)
project(Kozrum)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Header.cpp src/Header.h src/Section.cpp src/Section.h)
add_executable(Kozrum ${SOURCE_FILES})