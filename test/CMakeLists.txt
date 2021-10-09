cmake_minimum_required(VERSION 3.8)
project(test_widget)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Eigen3 REQUIRED)
add_executable(${PROJECT_NAME} test_widget.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE glw::glw Eigen3::Eigen GLEW::GLEW OpenGL::GL)
