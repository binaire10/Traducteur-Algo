cmake_minimum_required(VERSION 3.0)
project(tokenizer)
enable_testing()

add_definitions(-Dundefined=0)
add_subdirectory(struct_algo)
include_directories("${PROJECT_SOURCE_DIR}/struct_algo")
add_subdirectory(tokenizer)
include_directories("${PROJECT_SOURCE_DIR}/tokenizer")

set(CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif ()

add_executable(tokenizer main.cpp)
add_executable(test_convertion test_convertion.cpp)
add_executable(test_equals_type test_equalstype.cpp)
target_link_libraries(tokenizer struct_algo)
target_link_libraries(test_convertion struct_algo)
target_link_libraries(test_equals_type struct_algo)
target_link_libraries(tokenizer tokenizer)

add_test(conversion_scalarType_check test_convertion)
add_test(equals_scalarType_check test_equals_type)
