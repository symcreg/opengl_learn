cmake_minimum_required(VERSION 3.28)
project(opengl_learn)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)
#file(GLOB project_file glad.c main.cpp)
#add_executable(opengl_learn ${project_file})

add_executable(opengl_learn glad.c main.cpp)

target_link_libraries(opengl_learn glfw)
