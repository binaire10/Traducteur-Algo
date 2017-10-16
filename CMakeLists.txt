cmake_minimum_required(VERSION 3.0)
project(Traducteur_Algo)

add_definitions(-Dundefined=0)
add_subdirectory(struct_algo)
include_directories("${PROJECT_SOURCE_DIR}/struct_algo")

add_executable(Traducteur_Algo main.cpp)
target_link_libraries(Traducteur_Algo struct_algo)
