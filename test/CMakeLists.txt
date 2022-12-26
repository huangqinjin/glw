cmake_minimum_required(VERSION 3.8)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Eigen3 REQUIRED)
add_executable(test_window test_window.cpp)
target_link_libraries(test_window PRIVATE glw::glw Eigen3::Eigen GLEW::GLEW OpenGL::GL)
