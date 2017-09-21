cmake_minimum_required(VERSION 3.1)
project(glw)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

add_library(glw::glfw3 INTERFACE IMPORTED GLOBAL)
set_property(TARGET glw::glfw3 PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${OpenGL_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})
set_property(TARGET glw::glfw3 PROPERTY INTERFACE_LINK_LIBRARIES ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})


file(GLOB SOURCE_FILES src/*.cpp)
add_library(${PROJECT_NAME} ${SOURCE_FILES})
add_library(glw::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_options(${PROJECT_NAME} PRIVATE -pedantic -Wall)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE glw::glfw3)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON CXX_EXTENTIONS OFF)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()
