cmake_minimum_required(VERSION 3.20)

add_library(lguma
"${CMAKE_CURRENT_SOURCE_DIR}/Vm.cpp"
# "${CMAKE_CURRENT_SOURCE_DIR}/Interpreter.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Ast.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Env.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Value.cpp"
)


target_include_directories(lguma
  PUBLIC 
  "${CMAKE_SOURCE_DIR}/include"
  "${CMAKE_SOURCE_DIR}/deps/Heap-Layers"
  )
