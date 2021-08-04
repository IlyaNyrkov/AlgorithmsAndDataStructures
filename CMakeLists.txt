cmake_minimum_required(VERSION 3.18)
project(Algorithm_and_data_structures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "-pthread  -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-pthread -Wall -Werror -Wpedantic -fprofile-arcs -ftest-coverage")

set (PROJECT_HEADERS
        )

set (PROJECT_SOURCES
        )

add_executable(DataStructuresAndAlgorithms main.cpp ${PROJECT_HEADERS} ${PROJECT_SOURCES})
enable_testing()
find_package(GTest REQUIRED)
include_directories(&{GTEST_INCLUDE_DIR})
message(${GTEST_LIBRARIES})

set (TEST_PROJECT_SOURCES
        )

add_executable(DataStructuresAndAlgorithmsTests
    run_all_tests.cpp
)

target_link_libraries(DataStructuresAndAlgorithmsTests ${GTEST_LIBRARIES})