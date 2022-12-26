//
// Copyright (c) 2017-2023 Huang Qinjin (huangqinjin@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)
//
#include <glw/window.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <atomic>

using namespace glw;

namespace
{
    struct node
    {
        node* next;
    };

    struct list : node
    {
        list()
        {
            next = this;
        }

        bool empty() const
        {
            return next == this;
        }

        void add(node* x)
        {
            x->next = this->next;
            this->next = x;
        }

        void remove(node* x)
        {
            node** p = &this->next;
            while(*p != this)
            {
                if(*p == x)
                {
                    *p = x->next;
                    x->next = nullptr;
                    break;
                }
            }
        }
    } windows;
}

struct Window::ControlBlock : node
{
    GLFWwindow* w;
    std::string title;
    Point pos;
    Point cur;
    Size sz;
    uint64_t ts;

    // Events
    std::atomic<uint64_t> refresh{ uint64_t(-1) };

    static Window* get(GLFWwindow* window)
    {
        return (Window*)glfwGetWindowUserPointer(window);
    }

    static void error(int err, const char* description)
    {
        std::cerr << "gl error[" << err << "]: " << description << std::endl;
    }

    static void paint(GLFWwindow* window)
    {
        glfwMakeContextCurrent(window);
        Window* w = get(window);
        uint64_t now = glfwGetTimerValue();
        PaintEvent e{ (now - w->cb->ts) * 1.0 / glfwGetTimerFrequency() };
        w->cb->ts = now;
        w->cb->refresh.store(-1, std::memory_order_relaxed);
        w->paintEvent(&e);
        glfwSwapBuffers(window);
    }

    static void keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        KeyEvent e{ static_cast<Key>(key), static_cast<KeyAction>(action), scancode, mods };
        get(window)->keyEvent(&e);
    }

    static void mouse(GLFWwindow* window, int button, int action, int mods)
    {
        MouseEvent e{ static_cast<MouseButton>(button), static_cast<KeyAction>(action), mods };
        get(window)->mouseEvent(&e);
    }

    static void wheel(GLFWwindow* window, double xoffset, double yoffset)
    {
        WheelEvent e{ static_cast<real>(yoffset) };
        get(window)->wheelEvent(&e);
    }

    static void cursor(GLFWwindow* window, double xpos, double ypos)
    {
        Window* w = get(window);
        Point pos{ static_cast<real>(xpos), static_cast<real>(ypos) };
        CursorEvent e{ {pos.x - w->cb->cur.x, pos.y - w->cb->cur.y}, CursorAction::MOVE };
        if(e.dp.x != 0 || e.dp.y != 0)
        {
            w->cb->cur = pos;
            w->cursorEvent(&e);
        }
    }

    static void cursor(GLFWwindow* window, int entered)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        Window* w = get(window);
        CursorEvent e{ {0, 0}, entered ? CursorAction::ENTER : CursorAction::LEAVE };
        w->cb->cur = { static_cast<real>(xpos), static_cast<real>(ypos) };
        w->cursorEvent(&e);
    }

    static void move(GLFWwindow* window, int xpos, int ypos)
    {
        Window* w = get(window);
        Point pos{ static_cast<real>(xpos), static_cast<real>(ypos) };
        MoveEvent e{ { pos.x - w->cb->pos.x, pos.y - w->cb->pos.y} };
        w->cb->pos = pos;
        w->moveEvent(&e);
    }

    static void resize(GLFWwindow* window, int width, int height)
    {
        Window* w = get(window);
        Size sz{ static_cast<real>(width), static_cast<real>(height) };
        SizeEvent e{ { sz.w - w->cb->sz.w, sz.h - w->cb->sz.h } };
        w->cb->sz = sz;
        w->resizeEvent(&e);
    }

    static void close(GLFWwindow* window)
    {
        get(window)->closeEvent();
    }
};

Application::Application() : Application(0, nullptr) {}

Application::Application(int argc, char* argv[])
{
    if(!glfwInit())
    {
        std::terminate();
    }

    glfwSetErrorCallback(&Window::ControlBlock::error);
    glfwWindowHint(GLFW_VISIBLE, 0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_REFRESH_RATE, 1);
}

Application::~Application()
{
    glfwTerminate();
}

const char* Application::version() const
{
    return glfwGetVersionString();
}

int Application::exec()
{
    while(true)
    {
        unsigned c = 0;
        uint64_t ts = -1;
        node* p = windows.next;
        while(p != &windows)
        {
            auto cb = static_cast<Window::ControlBlock*>(p);
            if(cb->w)
            {
                ++c;
                uint64_t now = glfwGetTimerValue();
                uint64_t refresh = cb->refresh.load(std::memory_order_relaxed);
                if(refresh <= now) cb->paint(cb->w);
                else if(refresh < ts) ts = refresh;
            }
            p = p->next;
        }

        if(c == 0)
        {
            break;
        }
        else if(ts == -1)
        {
            glfwWaitEvents();
        }
        else
        {
            uint64_t now = glfwGetTimerValue();
            if(now < ts)
            {
                glfwWaitEventsTimeout((ts - now) * 1.0 / glfwGetTimerFrequency());
            }
            else
            {
                glfwPollEvents();
            }
        }
    }
    return 0;
}

Window::Window() : cb(new ControlBlock{})
{
    cb->sz = {100, 100};
    cb->pos = {100, 100};
    windows.add(cb);
}

Window::~Window()
{
    destroy();
    windows.remove(cb);
    delete cb;
}

void Window::destroy()
{
    glfwDestroyWindow(cb->w);
    cb->w = nullptr;
}

void Window::show()
{
    if(!cb->w)
    {
        cb->w = glfwCreateWindow(static_cast<int>(cb->sz.w), static_cast<int>(cb->sz.h),
                                 cb->title.c_str(), nullptr, nullptr);
        glfwSetWindowPos(cb->w, static_cast<int>(cb->pos.x), static_cast<int>(cb->pos.y));
        glfwSetWindowUserPointer(cb->w, this);
        glfwSetWindowRefreshCallback(cb->w, &ControlBlock::paint);
        glfwSetKeyCallback(cb->w, &ControlBlock::keyboard);
        glfwSetMouseButtonCallback(cb->w, &ControlBlock::mouse);
        glfwSetScrollCallback(cb->w, &ControlBlock::wheel);
        glfwSetCursorPosCallback(cb->w, &ControlBlock::cursor);
        glfwSetCursorEnterCallback(cb->w, &ControlBlock::cursor);
        glfwSetWindowPosCallback(cb->w, &ControlBlock::move);
        glfwSetWindowSizeCallback(cb->w, &ControlBlock::resize);
        glfwSetWindowCloseCallback(cb->w, &ControlBlock::close);
        cb->ts = glfwGetTimerValue();
        glfwMakeContextCurrent(cb->w);
        glfwSwapInterval(1);
        initialize();
        SizeEvent e{ cb->sz };
        resizeEvent(&e);
    }
    glfwShowWindow(cb->w);
}

void Window::hide()
{
    glfwHideWindow(cb->w);
}

void Window::minimize()
{
    glfwIconifyWindow(cb->w);
}

void Window::restore()
{
    glfwRestoreWindow(cb->w);
}

void Window::maximize()
{
    glfwMaximizeWindow(cb->w);
}

void Window::close()
{
    if(glfwWindowShouldClose(cb->w)) destroy();
    else glfwSetWindowShouldClose(cb->w, 1);
}

const char* Window::name() const
{
    return cb->title.c_str();
}

void Window::rename(const char* title)
{
    if(cb->w) glfwSetWindowTitle(cb->w, title);
    cb->title = title;
}

Size Window::size() const
{
    return cb->sz;
}

void Window::resize(Size sz)
{
    if(cb->w) glfwSetWindowSize(cb->w, static_cast<int>(sz.w), static_cast<int>(sz.h));
    else cb->sz = sz;
}

Point Window::pos() const
{
    return cb->pos;
}

void Window::move(Point pos)
{
    if(cb->w) glfwSetWindowPos(cb->w, static_cast<int>(pos.x), static_cast<int>(pos.y));
    else cb->pos = pos;
}

void Window::repaint(double dt)
{
    cb->refresh.store(dt <= 0 ? 0 :
        glfwGetTimerValue() + (uint64_t)(dt * glfwGetTimerFrequency()),
        std::memory_order_relaxed);
    glfwPostEmptyEvent();
}

KeyAction Window::status(MouseButton button) const
{
    return static_cast<KeyAction>(glfwGetMouseButton(cb->w, static_cast<int>(button)));
}

KeyAction Window::status(Key key) const
{
    return static_cast<KeyAction>(glfwGetKey(cb->w, static_cast<int>(key)));
}

void Window::initialize() {}
void Window::paintEvent(PaintEvent*) {}
void Window::keyEvent(KeyEvent*) {}
void Window::mouseEvent(MouseEvent*) {}
void Window::wheelEvent(WheelEvent*) {}
void Window::cursorEvent(CursorEvent*) {}
void Window::moveEvent(MoveEvent*) {}
void Window::resizeEvent(SizeEvent*) {}
void Window::closeEvent() { close(); }
