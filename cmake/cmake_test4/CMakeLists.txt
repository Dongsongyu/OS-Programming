cmake_minimum_required(VERSION 3.15)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB src ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib2)
link_libraries(calc)
add_executable(app ${src})
target_link_libraries(app calc)
