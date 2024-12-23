cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 11)
project(raycasting VERSION 0.1.0 LANGUAGES C CXX)

include_directories(src)

find_package(SDL2 REQUIRED HINTS "C:\\SDL2\\SDL2-2.30.8\\x86_64-w64-mingw32")
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES
    "*.cpp"
    "*.hpp"
    "src/*.cpp"
    "src/*.hpp"
    "src/math/*.cpp"
    "src/math/*.hpp"
    "src/entities/*.cpp"
    "src/entities/*.hpp"
    "src/rendering/*.cpp"
    "src/rendering/*.hpp"
)

add_executable(raycasting ${SOURCES})

target_link_libraries(raycasting ${SDL2_LIBRARIES})