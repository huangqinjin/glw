//
// Created by huangqinjin on 6/23/17.
//

#include <glw/Widget.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cfloat>

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
    Size sz;
    double ts;
    double dt;

    static Widget* get(GLFWwindow* window)
    {
        return (Widget*)glfwGetWindowUserPointer(window);
    }

    static void error(int err, const char* description)
    {
        std::cout << "gl error[" << err << "]: " << description << std::endl;
    }

    static void paint(GLFWwindow* window)
    {
        glfwMakeContextCurrent(window);
        Widget* w = get(window);
        double ts = glfwGetTime();
        PaintEvent e{ ts - w->cb->ts };
        w->cb->ts = ts;
        w->cb->dt = DBL_MAX;
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

    static void move(GLFWwindow* window, int xpos, int ypos)
    {
        Widget* w = get(window);
        MoveEvent e{ {xpos - w->cb->pos.x, ypos - w->cb->pos.y} };
        w->cb->pos = {xpos, ypos};
        w->moveEvent(&e);
    }

    static void resize(GLFWwindow* window, int width, int height)
    {
        Widget* w = get(window);
        SizeEvent e{ {width - w->cb->sz.w, height - w->cb->sz.h} };
        w->cb->sz = {width, height};
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
    glfwSwapInterval(1);
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
                if(cb->dt <= glfwGetTime() - cb->ts)
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
    cb->dt = DBL_MAX;
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
        cb->w = glfwCreateWindow(cb->sz.w, cb->sz.h, cb->title.c_str(), 0, 0);
        glfwSetWindowPos(cb->w, cb->pos.x, cb->pos.y);
        glfwSetWindowUserPointer(cb->w, this);
        glfwSetWindowRefreshCallback(cb->w, &ControlBlock::paint);
        glfwSetKeyCallback(cb->w, &ControlBlock::keyboard);
        glfwSetMouseButtonCallback(cb->w, &ControlBlock::mouse);
        glfwSetWindowPosCallback(cb->w, &ControlBlock::move);
        glfwSetWindowSizeCallback(cb->w, &ControlBlock::resize);
        glfwSetWindowCloseCallback(cb->w, &ControlBlock::close);
        cb->ts = glfwGetTime();
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
    //glfwMaximizeWindow(cb->w);
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
    cb->dt = dt;
}

void Widget::paintEvent(PaintEvent* e) {}
void Widget::keyEvent(KeyEvent* e) {}
void Widget::mouseEvent(MouseEvent* e) {}
void Widget::moveEvent(MoveEvent* e) {}
void Widget::resizeEvent(SizeEvent* e) {}
void Widget::closeEvent() { close(); }