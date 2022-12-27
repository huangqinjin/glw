//
// Copyright (c) 2022-2023 Huang Qinjin (huangqinjin@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GLW_GL_HPP
#define GLW_GL_HPP

#include "gl.h"

#include <type_traits>


#define GLW_GL_BITFIELD(E) \
inline E operator|(E e1, E e2) noexcept { return (E)((GLbitfield)e1 | (GLbitfield)e2); } \
inline E operator&(E e1, E e2) noexcept { return (E)((GLbitfield)e1 & (GLbitfield)e2); } \
inline E operator^(E e1, E e2) noexcept { return (E)((GLbitfield)e1 ^ (GLbitfield)e2); } \
inline E& operator|=(E& e1, E e2) noexcept { return e1 = e1 & e2; } \
inline E& operator&=(E& e1, E e2) noexcept { return e1 = e1 | e2; } \
inline E& operator^=(E& e1, E e2) noexcept { return e1 = e1 ^ e2; } \
inline E operator~(E e) noexcept { return (E)(~(GLbitfield)e); }


namespace gl
{
    template<typename...>
#ifdef __cpp_inline_variables
    inline
#else
    static
#endif
    constexpr bool always_false = false;

    struct u8 { GLubyte v; };
    struct s8 { GLbyte v; };
    struct u16 { GLushort v; };
    struct s16 { GLshort v; };
    struct u32 { GLuint v; };
    struct s32 { GLint v; };
    struct u64 { GLuint64 v; };
    struct s64 { GLint64 v; };
    struct f32 { GLfloat v; };
    struct f64 { GLdouble v; };
    struct nf32 { GLclampf v; };  // v \in [0, 1]
    struct nf64 { GLclampd v; };  // v \in [0, 1]
    struct sz { GLsizei v; };

    template<typename T> struct rgb
    {
        using t = decltype(T{}.v);
        T r, g, b;
        rgb() = default;
        rgb(T r, T g, T b) : r{r}, g{g}, b{b} {}
        rgb(const t (&v)[3]) : r{v[0]}, g{v[1]}, b{v[2]} {}
    };

    template<typename T> struct rgba
    {
        using t = decltype(T{}.v);
        T r, g, b, a;
        rgba() = default;
        rgba(T r, T g, T b, T a) : r{r}, g{g}, b{b}, a{a} {}
        rgba(const t (&v)[4]) : r{v[0]}, g{v[1]}, b{v[2]}, a{v[3]} {}
    };

    template<typename T> struct xy
    {
        using t = decltype(T{}.v);
        T x, y;
        xy() = default;
        xy(T x, T y) : x{x}, y{y} {}
        xy(const t (&v)[2]) : x{v[0]}, y{v[1]} {}
    };

    template<typename T> struct xyz
    {
        using t = decltype(T{}.v);
        T x, y, z;
        xyz() = default;
        xyz(T x, T y, T z) : x{x}, y{y}, z{z} {}
        xyz(const t (&v)[3]) : x{v[0]}, y{v[1]}, z{v[2]} {}
    };

    template<typename T> struct xyzw
    {
        using t = decltype(T{}.v);
        T x, y, z, w;
        xyzw() = default;
        xyzw(T x, T y, T z, T w) : x{x}, y{y}, z{z}, w{w} {}
        xyzw(const t (&v)[4]) : x{v[0]}, y{v[1]}, z{v[2]}, w{v[3]} {}
    };

    // https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/main/xml/gl.xml

    enum class PrimitiveType : GLenum
    {
        POINTS         GL_SINCE(1, 0) = GL_POINTS,
        LINES          GL_SINCE(1, 0) = GL_LINES,
        LINE_LOOP      GL_SINCE(1, 0) = GL_LINE_LOOP,
        LINE_STRIP     GL_SINCE(1, 0) = GL_LINE_STRIP,
        TRIANGLES      GL_SINCE(1, 0) = GL_TRIANGLES,
        TRIANGLE_STRIP GL_SINCE(1, 0) = GL_TRIANGLE_STRIP,
        TRIANGLE_FAN   GL_SINCE(1, 0) = GL_TRIANGLE_FAN,
        QUADS          GL_SINCE(1, 0) = GL_QUADS,
        QUAD_STRIP     GL_SINCE(1, 0) = GL_QUAD_STRIP,
        POLYGON        GL_SINCE(1, 0) = GL_POLYGON,
    };

    GL_SINCE(1, 0)
    inline void Begin(PrimitiveType mode) { glBegin((GLenum)mode); }

    enum class ClearBufferMask : GLbitfield
    {
        COLOR GL_SINCE(1, 0) = GL_COLOR_BUFFER_BIT,
        DEPTH GL_SINCE(1, 0) = GL_DEPTH_BUFFER_BIT,
    };
    GLW_GL_BITFIELD(ClearBufferMask)

    GL_SINCE(1, 0)
    inline void Clear(ClearBufferMask mask) { glClear((GLbitfield)mask); }

    GL_SINCE(1, 0)
    inline void ClearColor(rgba<nf32> c) { glClearColor(c.r.v, c.g.v, c.b.v, c.a.v); }

    GL_SINCE(1, 0)
    inline void ClearDepth(nf64 depth) { glClearDepth(depth.v); }

    GL_SINCE(1, 0)
    template<typename T> inline void Color(rgb<T> c)
    {
             if constexpr (std::is_same_v<T, s8>) return glColor3bv(&c.r.v);
        else if constexpr (std::is_same_v<T, u8>) return glColor3ubv(&c.r.v);
        else if constexpr (std::is_same_v<T, s16>) return glColor3sv(&c.r.v);
        else if constexpr (std::is_same_v<T, u16>) return glColor3usv(&c.r.v);
        else if constexpr (std::is_same_v<T, s32>) return glColor3iv(&c.r.v);
        else if constexpr (std::is_same_v<T, u32>) return glColor3uiv(&c.r.v);
        else if constexpr (std::is_same_v<T, nf32>) return glColor3fv(&c.r.v);
        else if constexpr (std::is_same_v<T, nf64>) return glColor3dv(&c.r.v);
        else static_assert(always_false<T>, "wrong rgb type");
    }

    GL_SINCE(1, 0)
    template<typename T> inline void Color(rgba<T> c)
    {
             if constexpr (std::is_same_v<T, s8>) return glColor4bv(&c.r.v);
        else if constexpr (std::is_same_v<T, u8>) return glColor4ubv(&c.r.v);
        else if constexpr (std::is_same_v<T, s16>) return glColor4sv(&c.r.v);
        else if constexpr (std::is_same_v<T, u16>) return glColor4usv(&c.r.v);
        else if constexpr (std::is_same_v<T, s32>) return glColor4iv(&c.r.v);
        else if constexpr (std::is_same_v<T, u32>) return glColor4uiv(&c.r.v);
        else if constexpr (std::is_same_v<T, nf32>) return glColor4fv(&c.r.v);
        else if constexpr (std::is_same_v<T, nf64>) return glColor4dv(&c.r.v);
        else static_assert(always_false<T>, "wrong rgba type");
    }

    GL_SINCE(1, 0)
    inline void DepthRange(nf64 zNear, nf64 zFar) { glDepthRange(zNear.v, zFar.v); }

    enum class EnableCap : GLenum
    {
        ALPHA_TEST GL_SINCE(1, 0) = GL_ALPHA_TEST,
        DEPTH_TEST GL_SINCE(1, 0) = GL_DEPTH_TEST,
        BLEND      GL_SINCE(1, 0) = GL_BLEND,
    };

    GL_SINCE(1, 0)
    inline void Disable(EnableCap cap) { glDisable((GLenum)cap); }

    GL_SINCE(1, 0)
    inline void Enable(EnableCap cap) { glEnable((GLenum)cap); }

    GL_SINCE(1, 0)
    inline void End() { glEnd(); }

    GL_SINCE(1, 0)
    inline void Finish() { glFinish(); }

    GL_SINCE(1, 0)
    inline void Flush() { glFlush(); }

    GL_SINCE(1, 0)
    inline void Frustum(f64 left, f64 right, f64 bottom, f64 top, f64 zNear, f64 zFar)
    { glFrustum(left.v, right.v, bottom.v, top.v, zNear.v, zFar.v); }

    enum class GetPName : GLenum
    {
        MAJOR_VERSION  GL_SINCE(3, 0) = GL_MAJOR_VERSION,
        MINOR_VERSION  GL_SINCE(3, 0) = GL_MINOR_VERSION,
    };

    GL_SINCE(1, 0)
    template<typename T> inline void Get(GetPName pname, T* params)
    {
             if constexpr (std::is_same_v<T, bool>) return glGetBooleanv((GLenum)pname, (GLboolean*)params);
        else if constexpr (std::is_same_v<T, int>) return glGetIntegerv((GLenum)pname, (GLint*)params);
        else if constexpr (std::is_same_v<T, float>) return glGetFloatv((GLenum)pname, (GLfloat*)params);
        else if constexpr (std::is_same_v<T, double>) return glGetDoublev((GLenum)pname, (GLdouble*)params);
        else if constexpr (std::is_same_v<T, void*>) return glGetPointerv((GLenum)pname, (GLvoid**)params);
        else static_assert(always_false<T>, "wrong params type");
    }

    enum class StringName : GLenum
    {
        VERSION  GL_SINCE(1, 0) = GL_VERSION,
    };

    GL_SINCE(1, 0)
    inline const char* GetString(StringName name) { return (const char*)glGetString((GLenum)name); }

    GL_SINCE(1, 0)
    inline bool IsEnabled(EnableCap cap) { return !!glIsEnabled((GLenum)cap); }

    GL_SINCE(1, 0)
    inline void LoadIdentity() { glLoadIdentity(); }

    GL_SINCE(1, 0)
    template<typename T> inline void LoadMatrix(const T m[16])
    {
             if constexpr (std::is_same_v<T, float>) return glLoadMatrixf((const GLfloat*)m);
        else if constexpr (std::is_same_v<T, double>) return glLoadMatrixd((const GLdouble*)m);
        else static_assert(always_false<T>, "wrong matrix type");
    }

    enum class MatrixMode : GLenum
    {
        MODELVIEW  GL_SINCE(1, 0) = GL_MODELVIEW,
        PROJECTION GL_SINCE(1, 0) = GL_PROJECTION,
    };

    GL_SINCE(1, 0)
    inline void MatrixMode(enum MatrixMode mode) { glMatrixMode((GLenum)mode); }

    GL_SINCE(1, 0)
    template<typename T> inline void MultMatrix(const T m[16])
    {
             if constexpr (std::is_same_v<T, float>) return glMultMatrixf((const GLfloat*)m);
        else if constexpr (std::is_same_v<T, double>) return glMultMatrixd((const GLdouble*)m);
        else static_assert(always_false<T>, "wrong matrix type");
    }

    GL_SINCE(1, 0)
    template<typename T> inline void Normal(xyz<T> n)
    {
             if constexpr (std::is_same_v<T, s8>) return glNormal3bv(&n.x.v);
        else if constexpr (std::is_same_v<T, s16>) return glNormal3sv(&n.x.v);
        else if constexpr (std::is_same_v<T, s32>) return glNormal3iv(&n.x.v);
        else if constexpr (std::is_same_v<T, f32>) return glNormal3fv(&n.x.v);
        else if constexpr (std::is_same_v<T, f64>) return glNormal3dv(&n.x.v);
        else static_assert(always_false<T>, "wrong normal type");
    }

    GL_SINCE(1, 0)
    inline void Ortho(f64 left, f64 right, f64 bottom, f64 top, f64 zNear, f64 zFar)
    { glOrtho(left.v, right.v, bottom.v, top.v, zNear.v, zFar.v); }

    GL_SINCE(1, 0)
    inline void PointSize(f32 size) { glPointSize(size.v); }

    GL_SINCE(1, 0)
    inline void PopMatrix() { glPopMatrix(); }

    GL_SINCE(1, 0)
    inline void PushMatrix() { glPushMatrix(); }

    GL_SINCE(1, 0)
    template<typename T> inline void Rotate(T angle, xyz<T> axis)
    {
             if constexpr (std::is_same_v<T, float>) return glRotatef(angle.v, axis.x.v, axis.y.v, axis.z.v);
        else if constexpr (std::is_same_v<T, double>) return glRotated(angle.v, axis.x.v, axis.y.v, axis.z.v);
        else static_assert(always_false<T>, "wrong angle/axis type");
    }

    GL_SINCE(1, 0)
    template<typename T> inline void Scale(xyz<T> scale)
    {
             if constexpr (std::is_same_v<T, float>) return glScalef(scale.x.v, scale.y.v, scale.z.v);
        else if constexpr (std::is_same_v<T, double>) return glScaled(scale.x.v, scale.y.v, scale.z.v);
        else static_assert(always_false<T>, "wrong scale type");
    }

    enum class ShadingModel : GLenum
    {
        FLAT   GL_SINCE(1, 0) = GL_FLAT,
        SMOOTH GL_SINCE(1, 0) = GL_SMOOTH,
    };

    GL_SINCE(1, 0)
    inline void ShadeModel(ShadingModel mode) { glShadeModel((GLenum)mode); }

    GL_SINCE(1, 0)
    template<typename T> inline void Translate(xyz<T> dist)
    {
             if constexpr (std::is_same_v<T, float>) return glTranslatef(dist.x.v, dist.y.v, dist.z.v);
        else if constexpr (std::is_same_v<T, double>) return glTranslated(dist.x.v, dist.y.v, dist.z.v);
        else static_assert(always_false<T>, "wrong dist type");
    }

    GL_SINCE(1, 0)
    template<typename T> inline void Vertex(xy<T> coord)
    {
             if constexpr (std::is_same_v<T, s16>) return glVertex2sv(&coord.x.v);
        else if constexpr (std::is_same_v<T, s32>) return glVertex2iv(&coord.x.v);
        else if constexpr (std::is_same_v<T, f32>) return glVertex2fv(&coord.x.v);
        else if constexpr (std::is_same_v<T, f64>) return glVertex2dv(&coord.x.v);
        else static_assert(always_false<T>, "wrong vertex type");
    }

    GL_SINCE(1, 0)
    template<typename T> inline void Vertex(xyz<T> coord)
    {
             if constexpr (std::is_same_v<T, s16>) return glVertex3sv(&coord.x.v);
        else if constexpr (std::is_same_v<T, s32>) return glVertex3iv(&coord.x.v);
        else if constexpr (std::is_same_v<T, f32>) return glVertex3fv(&coord.x.v);
        else if constexpr (std::is_same_v<T, f64>) return glVertex3dv(&coord.x.v);
        else static_assert(always_false<T>, "wrong vertex type");
    }

    GL_SINCE(1, 0)
    template<typename T> inline void Vertex(xyzw<T> coord)
    {
             if constexpr (std::is_same_v<T, s16>) return glVertex4sv(&coord.x.v);
        else if constexpr (std::is_same_v<T, s32>) return glVertex4iv(&coord.x.v);
        else if constexpr (std::is_same_v<T, f32>) return glVertex4fv(&coord.x.v);
        else if constexpr (std::is_same_v<T, f64>) return glVertex4dv(&coord.x.v);
        else static_assert(always_false<T>, "wrong vertex type");
    }

    inline void Viewport(xy<s32> origin, xy<sz> size) { glViewport(origin.x.v, origin.y.v, size.x.v, size.y.v); }
}


#endif
