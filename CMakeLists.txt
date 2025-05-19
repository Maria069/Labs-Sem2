cmake_minimum_required(VERSION 3.23)

set(project "lab6")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp
        Application.cpp)

set(${project}_HEADERS
        Application.h)

add_subdirectory(MyVector)
add_subdirectory(MyPolynomial)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} MyVector)
target_link_libraries(${project} MyPolynomial)