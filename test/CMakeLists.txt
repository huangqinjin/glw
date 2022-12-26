cmake_minimum_required(VERSION 3.8)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Eigen3 REQUIRED)
add_executable(test_window test_window.cpp)
target_link_libraries(test_window PRIVATE glw::glw Eigen3::Eigen GLEW::GLEW OpenGL::GL)


if(GLW_IMGUI)
    add_executable(test_imgui test_imgui.cpp)
    target_link_libraries(test_imgui PRIVATE glw::glw GLEW::GLEW OpenGL::GL)
    target_compile_definitions(test_imgui PRIVATE GLW_IMGUI_FONTS="${imgui_SOURCE_DIR}/misc/fonts/")
endif()
