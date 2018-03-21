set(SOURCE_FILES
            core/translator.cpp
            core/reader.cpp
    )

add_library(yzionalization SHARED ${SOURCE_FILES})

target_include_directories(yzionalization PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(tests)
add_subdirectory(test_code)
