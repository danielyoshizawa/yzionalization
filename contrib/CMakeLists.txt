cmake_minimum_required(VERSION 3.3)

project(yzionalization_contrib)

set(SOURCE main.cpp)

add_executable(contrib ${SOURCE})

target_include_directories(contrib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(contrib PUBLIC yzionalization)
