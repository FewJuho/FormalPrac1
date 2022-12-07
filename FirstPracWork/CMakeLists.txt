cmake_minimum_required(VERSION 3.21)
project(formal)

add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run formal.cpp formal.h test.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
