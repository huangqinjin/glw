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

    FetchContent_GetProperties(imgui)
    if(NOT imgui_POPULATED)
        FetchContent_Populate(imgui)
        file(COPY_FILE ${imgui_SOURCE_DIR}/imgui.h ${PROJECT_SOURCE_DIR}/include/glw/imgui.h ONLY_IF_DIFFERENT)
        file(READ ${imgui_SOURCE_DIR}/imconfig.h FILE_CONTENTS)
        file(WRITE ${PROJECT_SOURCE_DIR}/include/glw/imconfig.h "${FILE_CONTENTS}"
            "#define IMGUI_API GLW_API\n"
            "#define IMPLOT_API GLW_API\n"
        )
        file(READ ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp FILE_CONTENTS)
        string(REPLACE [["imgui_impl_opengl3_loader.h"]] "\n#else\n#include <glw/gl.h>" FILE_CONTENTS "${FILE_CONTENTS}")
        file(WRITE ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp "${FILE_CONTENTS}")
    endif()

    FetchContent_GetProperties(implot)
    if(NOT implot_POPULATED)
        FetchContent_Populate(implot)
        file(COPY_FILE ${implot_SOURCE_DIR}/implot.h ${PROJECT_SOURCE_DIR}/include/glw/implot.h ONLY_IF_DIFFERENT)
    endif()

    target_compile_definitions(glw PRIVATE GLW_IMGUI)
    target_include_directories(glw PRIVATE ${imgui_SOURCE_DIR} ${imgui_SOURCE_DIR}/backends)
    target_include_directories(glw PRIVATE ${implot_SOURCE_DIR})
    target_compile_definitions(glw PRIVATE [[IMGUI_USER_CONFIG=<glw/imconfig.h>]])
    target_compile_definitions(glw PRIVATE IMGUI_IMPL_OPENGL_LOADER_CUSTOM)

    target_sources(glw PRIVATE
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp

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
