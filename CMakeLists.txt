cmake_minimum_required(VERSION 3.12)
project(201808)

set(CMAKE_CXX_STANDARD 11)
include_directories(./gtest/include)
link_directories(./gtest/lib)
set(LIBRARIES
        gtest
        pthread)

set(SOURCE_FILES main.cpp CodeforcesWorldFinals.cpp main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})