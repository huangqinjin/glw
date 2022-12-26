cmake_minimum_required(VERSION 3.8)
project(glw)

find_package(glfw3 3.2 REQUIRED)

add_library(glw src/window.cpp)
add_library(glw::glw ALIAS glw)

target_include_directories(glw PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_compile_features(glw PUBLIC cxx_std_11)
target_link_libraries(glw PRIVATE glfw)

if(NOT DEFINED BUILD_TESTING OR BUILD_TESTING)
    add_subdirectory(test)
endif()
