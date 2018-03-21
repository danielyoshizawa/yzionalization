cmake_minimum_required(VERSION 3.0)

project(yzionalization)

set(CMAKE_CXX_STANDARD 11)

add_library(catch INTERFACE)
target_include_directories(catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/catch)

enable_testing()

add_subdirectory(src)
add_subdirectory(contrib)
