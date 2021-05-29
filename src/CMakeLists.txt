cmake_minimum_required(VERSION 3.20)

add_library(lua
"${CMAKE_CURRENT_SOURCE_DIR}/Vm.cpp")


target_include_directories(lua
  PUBLIC 
  "${CMAKE_SOURCE_DIR}/include"
  "${CMAKE_SOURCE_DIR}/deps/Heap-Layers"
  )
