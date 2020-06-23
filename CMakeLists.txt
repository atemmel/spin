cmake_minimum_required(VERSION 3.10)
project(spin)
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "./*.cpp")
add_executable(spin main.cpp)
set_property(TARGET spin PROPERTY CXX_STANDARD 17)

#Optional:
#include_directories(include)
#target_link_libraries(lang LLVM)

