//
// Copyright (c) 2017-2021 Huang Qinjin (huangqinjin@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GLW_WIDGET_HPP
#define GLW_WIDGET_HPP

#include <string>

namespace glw
{
    using real = float;

    class Application
    {
    public:
        Application();
        Application(int argc, char* argv[]);
        ~Application();
        const char* version() const;
        int exec();
    };

    struct Point
    {
        real x;
        real y;
        Point() = default;
        Point(real x, real y) : x(x), y(y) {}
    };

    struct Size
    {
        real w;
        real h;
        Size() = default;
        Size(real w, real h) : w(w), h(h) {}
    };



    enum class MouseButton
    {
        LEFT,
        RIGHT,
        MIDDLE,
    };

    enum class CursorAction
    {
        ENTER,
        LEAVE,
        MOVE,
    };

    enum class KeyAction
    {
        RELEASE,
        PRESS,
        REPEAT,
    };

    enum class Key
    {
        UNKNOWN = -1,
        A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        N0 = '0', N1, N2, N3, N4, N5, N6, N7, N8, N9,
        F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        ESC = 256, ENTER, TAB, BACKSPACE, INSERT, DELETE, RIGHT, LEFT, DOWN, UP,
        LSHIFT = 340, LCONTROL, LALT, LSUPER, RSHIFT, RCONTROL, RALT, RSUPER,
    };

    struct PaintEvent
    {
        double dt;
    };

    struct KeyEvent
    {
        Key key;
        KeyAction action;
        int scancode;
        int mods;
    };

    struct MouseEvent
    {
        MouseButton button;
        KeyAction action;
        int mods;
    };

    struct WheelEvent
    {
        real dx;
    };

    struct CursorEvent
    {
        Point dp;
        CursorAction action;
    };

    struct MoveEvent
    {
        Point dp;
    };

    struct SizeEvent
    {
        Size dz;
    };

    class Widget
    {
    public:
        Widget();
        virtual ~Widget();

        void destroy();
        void show();
        void hide();
        void minimize();
        void restore();
        void maximize();
        void close();
        const std::string& name() const;
        void rename(const char* title);
        void rename(const std::string& title);
        Size size() const;
        void resize(Size sz);
        Point pos() const;
        void move(Point pos);
        void repaint(double dt = 0);

    public:
        KeyAction status(MouseButton button) const;
        KeyAction status(Key key) const;

    private:
        virtual void initialize();
        virtual void paintEvent(PaintEvent* e);
        virtual void keyEvent(KeyEvent* e);
        virtual void mouseEvent(MouseEvent* e);
        virtual void wheelEvent(WheelEvent* e);
        virtual void cursorEvent(CursorEvent* e);
        virtual void moveEvent(MoveEvent* e);
        virtual void resizeEvent(SizeEvent* e);
        virtual void closeEvent();

    private:
        friend class Application;
        struct ControlBlock;
        ControlBlock* const cb;
    };
}


#endif //GLW_WIDGET_HPP
