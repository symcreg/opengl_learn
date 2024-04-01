cmake_minimum_required(VERSION 3.28)
project(opengl_learn)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(opengl_learn glad.c main.cpp
        include/shader.h
        include/stb_image.h
        include/stb_image.cpp)

target_link_libraries(opengl_learn glfw)
