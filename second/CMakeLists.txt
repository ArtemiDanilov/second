cmake_minimum_required(VERSION 3.1)

project(second)

set(second_SRC main.cpp CRat.cpp autotest.cpp)
set(second_HDR CRat.hpp Header.hpp)

#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${second_SRC} ${second_HDR})