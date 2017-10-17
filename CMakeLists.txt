cmake_minimum_required(VERSION 3.0)
project(Traducteur_Algo)

add_definitions(-Dundefined=0)
add_subdirectory(struct_algo)
include_directories("${PROJECT_SOURCE_DIR}/struct_algo")

set(CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif ()

add_executable(Traducteur_Algo main.cpp)
target_link_libraries(Traducteur_Algo struct_algo)
