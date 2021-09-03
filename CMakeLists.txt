cmake_minimum_required(VERSION 3.20)
project(dsa VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(dsa
        main.cpp
        of/OF5.cpp
        of/OF6.cpp)

target_include_directories(dsa PRIVATE common)

enable_testing()
find_package(GTest 1.10.0 REQUIRED)
target_link_libraries(dsa PRIVATE
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main)
gtest_discover_tests(dsa)