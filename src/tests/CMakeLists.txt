set(SOURCE
        ../core/reader.cpp
        reader_test.cpp)

set(EN_EN_INPUT_FILE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/input/en_en.txt")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/etc/path.in.h path.h @ONLY)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(yzionalization_test ${SOURCE})

target_include_directories(yzionalization_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                                        ${CMAKE_CURRENT_SOURCE_DIR}/../
        )

target_link_libraries(yzionalization_test PRIVATE catch)

add_test(yzionalization_test yzionalization_test)
