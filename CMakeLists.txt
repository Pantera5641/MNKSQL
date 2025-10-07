cmake_minimum_required(VERSION 3.20)
project(MNKSQL)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")
file(GLOB_RECURSE SOURCES "logic/*.cpp" "commands/*.cpp" "content/*.cpp" "database/*.cpp" "database/templates/*.cpp" "*.cpp")
add_executable(MNKSQL ${SOURCES})

