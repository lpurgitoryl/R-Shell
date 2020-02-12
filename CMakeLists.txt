cmake_minimum_required(VERSION 3.10)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
	src/main.cpp
    src/Parser.cpp
)
set(CMAKE_BUILD_TYPE Debug)
