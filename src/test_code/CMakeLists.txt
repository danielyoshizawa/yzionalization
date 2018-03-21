set(SOURCE
        ../core/reader.cpp
        main.cpp)

add_executable(test_code ${SOURCE})

target_include_directories(test_code PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/
                                             ${CMAKE_CURRENT_SOURCE_DIR}/../core
        )

