cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE_Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++14")

project(helloWorld) #project name

add_executable(hello main.cpp) # hello is executable name & main.cpp is source
