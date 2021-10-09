cmake_minimum_required(VERSION 3.8)
project(glw)

find_package(glfw3 3.2 REQUIRED)

add_library(${PROJECT_NAME} src/Widget.cpp)
add_library(glw::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
