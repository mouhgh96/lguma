cmake_minimum_required(VERSION 3.20)

project(Lguma VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/apps")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/Heap-Layers")
