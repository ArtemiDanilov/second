cmake_minimum_required(VERSION 3.2)

project(second)

set(SECOND_SRC main.cpp CRat.cpp autotest.cpp)
set(SECOND_HDR CRat.hpp Header.hpp)

#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${SECOND_SRC} ${SECOND_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 /std:c++14")