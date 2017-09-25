cmake_minimum_required(VERSION 3.1)

find_package(OpenGL REQUIRED)
add_executable(test_widget test_widget.cpp)
target_include_directories(test_widget PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(test_widget PRIVATE glw::glw ${OPENGL_LIBRARIES})