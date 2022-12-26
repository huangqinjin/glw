cmake_minimum_required(VERSION 3.21)
project(glw)

option(GLW_IMGUI "Integrate Dear ImGui" ON)

include(FetchContent)

find_package(glfw3 3.2 REQUIRED)

add_library(glw src/window.cpp)
add_library(glw::glw ALIAS glw)

target_include_directories(glw PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_compile_features(glw PUBLIC cxx_std_11)
target_link_libraries(glw PRIVATE glfw)


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
        file(COPY_FILE ${imgui_SOURCE_DIR}/imconfig.h ${PROJECT_SOURCE_DIR}/include/glw/imconfig.h)
    endif()

    FetchContent_GetProperties(implot)
    if(NOT implot_POPULATED)
        FetchContent_Populate(implot)
        file(COPY_FILE ${implot_SOURCE_DIR}/implot.h ${PROJECT_SOURCE_DIR}/include/glw/implot.h ONLY_IF_DIFFERENT)
    endif()

    target_compile_definitions(glw PRIVATE GLW_IMGUI)
    target_include_directories(glw PRIVATE ${imgui_SOURCE_DIR} ${imgui_SOURCE_DIR}/backends)
    target_include_directories(glw PRIVATE ${implot_SOURCE_DIR})

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
