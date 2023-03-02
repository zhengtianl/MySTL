cmake_minimum_required(VERSION 3.24)
project(MySTL)

set(CMAKE_CXX_STANDARD 11)

#文件目录
file(GLOB_RECURSE Container source/Container/*.cpp)
file(GLOB_RECURSE main_cpp source/*.cpp)
add_executable(MySTL Src/Container/main.cpp ${Container})
