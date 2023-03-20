cmake_minimum_required(VERSION 3.21)
project(glw)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_RPATH_USE_ORIGIN ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(GLW_IMGUI "Integrate Dear ImGui" ON)
set(GLW_LIBRARY "SHARED" CACHE STRING "glw library type")
set_property(CACHE GLW_LIBRARY PROPERTY STRINGS SHARED STATIC OBJECT)

include(FetchContent)

find_package(glfw3 3.2 REQUIRED)

add_library(glw ${GLW_LIBRARY} src/window.cpp src/gl.cpp)
add_library(glw::glw ALIAS glw)

target_include_directories(glw PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_compile_features(glw PUBLIC cxx_std_14)
target_link_libraries(glw PRIVATE glfw)

if(BUILD_SHARED_LIBS OR GLW_LIBRARY STREQUAL "SHARED")
    if(WIN32)
        target_compile_definitions(glw PRIVATE [[GLW_API=__declspec(dllexport)]])
        target_compile_definitions(glw INTERFACE [[GLW_API=__declspec(dllimport)]])
    else()
        target_compile_definitions(glw PUBLIC [[GLW_API=__attribute__((visibility("default")))]])
    endif()
else()
    target_compile_definitions(glw PUBLIC GLW_API=)
endif()

if(GLW_IMGUI)
    FetchContent_Declare(imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG        master
    )

    FetchContent_Declare(implot
        GIT_REPOSITORY https://github.com/epezent/implot.git
        GIT_TAG        master
    )

    FetchContent_MakeAvailable(imgui implot)

    file(COPY_FILE ${imgui_SOURCE_DIR}/imgui.h ${PROJECT_SOURCE_DIR}/include/glw/imgui.h ONLY_IF_DIFFERENT)
    file(COPY_FILE ${implot_SOURCE_DIR}/implot.h ${PROJECT_SOURCE_DIR}/include/glw/implot.h ONLY_IF_DIFFERENT)
    file(CONFIGURE OUTPUT ${imgui_BINARY_DIR}/imgui_impl_opengl.cpp @ONLY CONTENT [[
        #include "imgui_impl_opengl3.h"
        #if !defined(IMGUI_IMPL_OPENGL_ES2) && !defined(IMGUI_IMPL_OPENGL_ES3)
          #include <glw/gl.h>
          #define IMGUI_IMPL_OPENGL_LOADER_CUSTOM
        #endif
        #include "imgui_impl_opengl3.cpp"
    ]])

    target_compile_definitions(glw PRIVATE GLW_IMGUI)
    target_include_directories(glw PRIVATE ${imgui_SOURCE_DIR} ${imgui_SOURCE_DIR}/backends)
    target_include_directories(glw PRIVATE ${implot_SOURCE_DIR})
    target_compile_definitions(glw PRIVATE [[IMGUI_IMPL_API=]] [[IMGUI_USER_CONFIG=<glw/imconfig.h>]])

    target_sources(glw PRIVATE
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${imgui_BINARY_DIR}/imgui_impl_opengl.cpp

        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp

        ${implot_SOURCE_DIR}/implot.cpp
        ${implot_SOURCE_DIR}/implot_items.cpp
        ${implot_SOURCE_DIR}/implot_demo.cpp
    )
endif()


if(NOT DEFINED BUILD_TESTING OR BUILD_TESTING)
    add_subdirectory(test)
endif()
