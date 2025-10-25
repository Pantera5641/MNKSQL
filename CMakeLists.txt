cmake_minimum_required(VERSION 4.0.0)

project(MNKSQL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_CXX_EXTENSIONS false)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)

file(GLOB_RECURSE SOURCES 
    "commands/*.cpp"
    "constants/*.cpp"
    "database/*.cpp" 
    "logic/*.cpp" 
    "utils/*.cpp" 
    "validators/*.cpp"
    "main.cpp"
)
add_executable(MNKSQL ${SOURCES})

file(GLOB COMMAND_DIRS "${CMAKE_SOURCE_DIR}/commands/*")
file(GLOB VALIDATOR_DIRS "${CMAKE_SOURCE_DIR}/validators/*")
file(GLOB UTILS_DIRS "${CMAKE_SOURCE_DIR}/utils/*")

target_include_directories(MNKSQL PRIVATE
    ${COMMAND_DIRS}
    ${VALIDATOR_DIRS}
    ${UTILS_DIRS}
    ${CMAKE_SOURCE_DIR}/constants
    ${CMAKE_SOURCE_DIR}/database
    ${CMAKE_SOURCE_DIR}/logic
    )