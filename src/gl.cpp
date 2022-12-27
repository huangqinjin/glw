//
// Copyright (c) 2022-2023 Huang Qinjin (huangqinjin@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)
//

#include <stdexcept>

class gl_function_not_supported : public std::domain_error
{
public:
    explicit gl_function_not_supported(const char* f)
        : domain_error(f) {}
};

#define GLF(R, f, ...) GLW_API R (GLW_GLCALL *f)(__VA_ARGS__) = [](auto... args) { \
    auto g = (decltype(f))glGetProcAddress(#f); \
    if (!g) g = [](auto...) -> R { throw gl_function_not_supported(#f); }; \
    return (f = g)(args...); \
}

#include <glw/gl.h>


// https://github.com/opencv/opencv/blob/4.x/modules/core/src/gl_core_3_1.cpp

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static GLfunc getProc(const char* name)
{
    static const auto handle = LoadLibraryW(L"opengl32");
    static const auto wglGetProcAddress = (GLfunc(WINAPI*)(LPCSTR))GetProcAddress(handle, "wglGetProcAddress");
    GLfunc f = wglGetProcAddress(name);
    if (!f) f = (GLfunc)GetProcAddress(handle, name);
    return f;
};

#elif defined(__APPLE__)
#include <dlfcn.h>

static GLfunc getProc(const char* name)
{
    static const auto handle = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY | RTLD_LOCAL);
    return (GLfunc)dlsym(handle, name);
}

#elif defined(__linux__)
#include <dlfcn.h>

static GLfunc getProc(const char* name)
{
    static const auto handle = dlopen("libGLX.so.0", RTLD_LAZY | RTLD_LOCAL);
    static const auto glXGetProcAddress = (GLfunc(*)(const char*))dlsym(handle, "glXGetProcAddress");
    return glXGetProcAddress(name);
}

#else

static GLfunc getProc(const char*)
{
    return nullptr;
}

#endif

GLW_API GLfunc (*glGetProcAddress)(const char* name) = getProc;

