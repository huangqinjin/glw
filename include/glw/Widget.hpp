//
// Created by huangqinjin on 6/23/17.
//

#ifndef GLW_WIDGET_HPP
#define GLW_WIDGET_HPP

#include <string>

namespace glw
{
    class Application
    {
    public:
        Application();
        Application(int argc, char* argv[]);
        ~Application();
        const char* version() const;
        int run();
    };

    struct Point
    {
        int x;
        int y;
        Point() = default;
        Point(int x, int y) : x(x), y(y) {}
    };

    struct Size
    {
        int w;
        int h;
        Size() = default;
        Size(int w, int h) : w(w), h(h) {}
    };



    enum class MouseButton
    {
        LEFT,
        RIGHT,
        MIDDLE,
    };

    enum class KeyAction
    {
        PRESS,
        RELEASE,
        UNKNOWN,
    };

    enum class Key
    {
        UNKNOWN = -1,
        A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        N0 = '0', N1, N2, N3, N4, N5, N6, N7, N8, N9,
        F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        ESC, CTRL, ALT, SHIFT, TAB,
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
        const std::string& title() const;
        void setTitle(const char* title);
        void setTitle(const std::string& title);
        Size size() const;
        void resize(Size sz);
        Point pos() const;
        void move(Point pos);
        void repaint(double dt);

    private:
        virtual void paintEvent(PaintEvent* e);
        virtual void keyEvent(KeyEvent* e);
        virtual void mouseEvent(MouseEvent* e);
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
