cmake_minimum_required(VERSION 3.1)
project(glw)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-pedantic -Wall)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

file(GLOB SOURCE_FILES *.cpp)
add_library(glw ${SOURCE_FILES})

include_directories(${OpenGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})
target_link_libraries(glw ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})