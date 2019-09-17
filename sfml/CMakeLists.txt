cmake_minimum_required(VERSION 3.7)

project(primer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)

#we add the executable of the program
add_executable(primer
main.cpp
)

target_link_libraries(primer sfml-system sfml-window sfml-graphics sfml-audio sfml-network )
