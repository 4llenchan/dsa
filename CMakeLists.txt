cmake_minimum_required(VERSION 3.20)
project(dsa VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(dsa
        main.cpp
        common/Algorithm.cpp
        common/Common.cpp
        lc/LC10.cpp
        lc/LC135.cpp
        lc/LC455.cpp
        of/OF5.cpp
        of/OF6.cpp
        of/OF10_I.cpp
        of/OF42.cpp
        of/OF46.cpp
        of/OF47.cpp
        of/OF48.cpp
        of/OF60.cpp
        test/AlgorithmTests.cpp)

target_include_directories(dsa PRIVATE common)

enable_testing()
find_package(GTest 1.10.0 REQUIRED)
target_link_libraries(dsa PRIVATE
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main)
gtest_discover_tests(dsa)