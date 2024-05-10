cmake_minimum_required(VERSION 3.16)

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_C_COMPILER "gcc" )

project(JDataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

set(SOURCE_FILES
"src/main.cpp"
"include/LinkedList.hpp")

add_executable(JDataStructures ${SOURCE_FILES})
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
