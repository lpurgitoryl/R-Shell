CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

ADD_EXECUTABLE(rshell
	src/main.cpp
    src/Parser.cpp
)

#ADD_EXECUTABLE(test.o
 #   unit_tests/parser_vector_test.cpp
  #  src/Parser.cpp
    #src/main.cpp
#)

#TARGET_LINK_LIBRARIES(test.o gtest)
#TARGET_COMPILE_DEFINITIONS(test.o PRIVATE gtest_disable_pthreads=ON)