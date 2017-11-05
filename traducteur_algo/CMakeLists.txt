cmake_minimum_required(VERSION 3.0)
project(traducteur_algo)

add_definitions(-Dundefined=0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(PCRE2)
if(PCRE2_FOUND)
    include_directories(${PCRE2_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif ()

set(SOURCE_FILES
        TraducteurAlgo.cpp
        TraducteurAlgo.h
        ModuleTraduction.cpp
        ModuleTraduction.h
        regex.cpp
        regex.h TokenizerIterator.cpp TokenizerIterator.h)
add_library(traducteur_algo STATIC ${SOURCE_FILES})
