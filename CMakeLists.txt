cmake_minimum_required(VERSION 2.6)
project(IZ_2)
 set(CMAKE_CXX_STANDARD 11)
 set((CMAKE_CXX_STANDARD_REQUIRED ON))
set((CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -ggdb3"))
set(LIB_SOURCE_FILES src/static_lib.cpp)
add_library(iz2_std_lib STATIC ${LIB_SOURCE_FILES})
add_executable(prog src/main.cpp)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(prog iz2_std_lib)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test/test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} -lpthread)

