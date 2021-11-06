cmake_minimum_required(VERSION 3.20)
project(dsa VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(dsa
        main.cpp
        common/Algorithm.cpp
        common/Common.cpp
        lc/LC6.cpp
        lc/LC10.cpp
        lc/LC33.cpp
        lc/LC34.cpp
        lc/LC46.cpp
        lc/LC64.cpp
        lc/LC69.cpp
        lc/LC76.cpp
        lc/LC77.cpp
        lc/LC81.cpp
        lc/LC88.cpp
        lc/LC94.cpp
        lc/LC135.cpp
        lc/LC142.cpp
        lc/LC144.cpp
        lc/LC145.cpp
        lc/LC146.cpp
        lc/LC167.cpp
        lc/LC215.cpp
        lc/LC221.cpp
        lc/LC225.cpp
        lc/LC268.cpp
        lc/LC300.cpp
        lc/LC347.cpp
        lc/LC413.cpp
        lc/LC416.cpp
        lc/LC435.cpp
        lc/LC452.cpp
        lc/LC455.cpp
        lc/LC524.cpp
        lc/LC542.cpp
        lc/LC547.cpp
        lc/LC695.cpp
        of/OF5.cpp
        of/OF6.cpp
        of/OF10_I.cpp
        of/OF42.cpp
        of/OF46.cpp
        of/OF47.cpp
        of/OF48.cpp
        of/OF60.cpp
        test/AlgorithmTests.cpp
        test/CommonTests.cpp)

target_include_directories(dsa PRIVATE common)

enable_testing()
find_package(GTest 1.10.0 REQUIRED)
target_link_libraries(dsa PRIVATE
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main)
gtest_discover_tests(dsa)