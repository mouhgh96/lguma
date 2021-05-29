cmake_minimum_required(VERSION 3.20)

add_executable(apps 
${CMAKE_CURRENT_SOURCE_DIR}/app.cpp)


target_include_directories(apps PUBLIC 
"${CMAKE_SOURCE_DIR}/include")

target_link_libraries(apps PUBLIC lua fmt)
