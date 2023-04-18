cmake_minimum_required(VERSION 3.24.2)

project(SWAP)

include_directories(include)

add_executable(swap_cmake main.cpp src/Swap.cpp)