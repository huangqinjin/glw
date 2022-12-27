cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)
add_executable(test_window test_window.cpp)
target_link_libraries(test_window PRIVATE glw::glw Eigen3::Eigen)


if(GLW_IMGUI)
    add_executable(test_imgui test_imgui.cpp)
    target_link_libraries(test_imgui PRIVATE glw::glw)
    target_compile_definitions(test_imgui PRIVATE GLW_IMGUI_FONTS="${imgui_SOURCE_DIR}/misc/fonts/")
endif()
