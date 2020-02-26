CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

 set(CMAKE_BUILD_TYPE Debug)

ADD_EXECUTABLE(rshell
	src/main.cpp
    src/Parser.cpp
)


#ADD_EXECUTABLE(test
 #   unit_tests/parser_vector_test.cpp
  #  unit_tests/parser_vector_test2.cpp
  #  unit_tests/argbase_test.cpp
  #  src/Parser.cpp
#)


#TARGET_LINK_LIBRARIES(test gtest)
#TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

