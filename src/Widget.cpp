//
// Created by huangqinjin on 6/23/17.
//

#include <glw/Widget.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cfloat>
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
    } widgets;
}

struct Widget::ControlBlock : node
{
    GLFWwindow* w;
    std::string title;
    Point pos;
    Point cur;
    Size sz;
    double ts;
    std::atomic<double> dt;

    static Widget* get(GLFWwindow* window)
    {
        return (Widget*)glfwGetWindowUserPointer(window);
    }

    static void error(int err, const char* description)
    {
        std::cerr << "gl error[" << err << "]: " << description << std::endl;
    }

    static void paint(GLFWwindow* window)
    {
        glfwMakeContextCurrent(window);
        Widget* w = get(window);
        double ts = glfwGetTime();
        PaintEvent e{ ts - w->cb->ts };
        w->cb->ts = ts;
        w->cb->dt.store(DBL_MAX, std::memory_order_relaxed);
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
        Widget* w = get(window);
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
        Widget* w = get(window);
        CursorEvent e{ {0, 0}, entered ? CursorAction::ENTER : CursorAction::LEAVE };
        w->cb->cur = { static_cast<real>(xpos), static_cast<real>(ypos) };
        w->cursorEvent(&e);
    }

    static void move(GLFWwindow* window, int xpos, int ypos)
    {
        Widget* w = get(window);
        Point pos{ static_cast<real>(xpos), static_cast<real>(ypos) };
        MoveEvent e{ { pos.x - w->cb->pos.x, pos.y - w->cb->pos.y} };
        w->cb->pos = pos;
        w->moveEvent(&e);
    }

    static void resize(GLFWwindow* window, int width, int height)
    {
        Widget* w = get(window);
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

    glfwSetErrorCallback(&Widget::ControlBlock::error);
    glfwWindowHint(GLFW_VISIBLE, 0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
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
        node* p = widgets.next;
        while(p != &widgets)
        {
            auto cb = static_cast<Widget::ControlBlock*>(p);
            if(cb->w)
            {
                ++c;
                if(cb->dt.load(std::memory_order_relaxed) <= glfwGetTime() - cb->ts)
                    cb->paint(cb->w);
            }
            p = p->next;
        }

        if(c == 0) break;
        glfwPollEvents();
    }
    return 0;
}

Widget::Widget() : cb(new ControlBlock{})
{
    cb->sz = {100, 100};
    std::atomic_init(&cb->dt, DBL_MAX);
    widgets.add(cb);
}

Widget::~Widget()
{
    destroy();
    widgets.remove(cb);
    delete cb;
}

void Widget::destroy()
{
    glfwDestroyWindow(cb->w);
    cb->w = nullptr;
}

void Widget::show()
{
    if(!cb->w)
    {
        cb->w = glfwCreateWindow(cb->sz.w, cb->sz.h, cb->title.c_str(), nullptr, nullptr);
        glfwSetWindowPos(cb->w, cb->pos.x, cb->pos.y);
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
        cb->ts = glfwGetTime();
        glfwMakeContextCurrent(cb->w);
        glfwSwapInterval(1);
        initialize();
        SizeEvent e{ cb->sz };
        resizeEvent(&e);
    }
    glfwShowWindow(cb->w);
}

void Widget::hide()
{
    glfwHideWindow(cb->w);
}

void Widget::minimize()
{
    glfwIconifyWindow(cb->w);
}

void Widget::restore()
{
    glfwRestoreWindow(cb->w);
}

void Widget::maximize()
{
    glfwMaximizeWindow(cb->w);
}

void Widget::close()
{
    if(glfwWindowShouldClose(cb->w)) destroy();
    else glfwSetWindowShouldClose(cb->w, 1);
}

const std::string& Widget::name() const
{
    return cb->title;
}

void Widget::rename(const char* title)
{
    if(cb->w) glfwSetWindowTitle(cb->w, title);
    cb->title = title;
}

void Widget::rename(const std::string& title)
{
    rename(title.c_str());
}

Size Widget::size() const
{
    return cb->sz;
}

void Widget::resize(Size sz)
{
    if(cb->w) glfwSetWindowSize(cb->w, sz.w, sz.h);
    else cb->sz = sz;
}

Point Widget::pos() const
{
    return cb->pos;
}

void Widget::move(Point pos)
{
    if(cb->w) glfwSetWindowPos(cb->w, pos.x, pos.y);
    else cb->pos = pos;
}

void Widget::repaint(double dt)
{
    cb->dt.store(dt, std::memory_order_relaxed);
}

KeyAction Widget::status(MouseButton button) const
{
    return static_cast<KeyAction>(glfwGetMouseButton(cb->w, static_cast<int>(button)));
}

void Widget::initialize() {}
void Widget::paintEvent(PaintEvent* e) {}
void Widget::keyEvent(KeyEvent* e) {}
void Widget::mouseEvent(MouseEvent* e) {}
void Widget::wheelEvent(WheelEvent* e) {}
void Widget::cursorEvent(CursorEvent* e) {}
void Widget::moveEvent(MoveEvent* e) {}
void Widget::resizeEvent(SizeEvent* e) {}
void Widget::closeEvent() { close(); }
