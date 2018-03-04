set(SOURCE_FILES core/translator.cpp)

add_library(yzionalization MODULE ${SOURCE_FILES})

target_include_directories(yzionalization PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

