cmake_minimum_required(VERSION 3.1)
project(glw)

find_package(glfw3 3.2 REQUIRED)

file(GLOB SOURCE_FILES src/*.cpp)
add_library(${PROJECT_NAME} ${SOURCE_FILES})
add_library(glw::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_options(${PROJECT_NAME} PRIVATE -pedantic -Wall)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENTIONS OFF)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()
