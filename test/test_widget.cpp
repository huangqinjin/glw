//
// Created by huangqinjin on 7/18/17.
//

#include <glw/Widget.hpp>
#include <iostream>
#include <GL/gl.h>

using namespace glw;
class MainWindow : public Widget
{
    void initialize() override
    {
        glClearColor(0, 0, 0, 0);
        glShadeModel(GL_SMOOTH);

        std::cout << "initialize" << std::endl;
    }

    void paintEvent(PaintEvent* e) override
    {
        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw the scene:
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1, -1, 0.0);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1, 0.0, 0.0);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0, 1, 0.0);
        glEnd();

        repaint(1);
        std::cout << "paint " << e->dt << std::endl;
    }

    void keyEvent(KeyEvent* e) override
    {
        std::cout << "key " << (char)e->key << ' ' << (int)e->action << std::endl;
    }

    void mouseEvent(MouseEvent* e) override
    {
        std::cout << "mouse " << (int)e->button << ' ' << (int)e->action << std::endl;
    }

    void wheelEvent(WheelEvent* e) override
    {
        std::cout << "wheel " << e->dx << std::endl;
    }

    void cursorEvent(CursorEvent* e) override
    {
        std::cout << "cursor " << (int)e->action << ' ' << e->dp.x << ' ' << e->dp.y << std::endl;
    }

    void moveEvent(MoveEvent* e) override
    {
        std::cout << "move " << e->dp.x << ' ' << e->dp.y << std::endl;
    }

    void resizeEvent(SizeEvent* e) override
    {
        std::cout << "resize " << e->dz.w << ' ' << e->dz.h << std::endl;
    }

    void closeEvent() override
    {
        close();
        std::cout << "close" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    Application app(argc, argv);
    MainWindow w;
    w.rename("MainWindow");
    w.resize({200, 200});
    w.show();
    return app.exec();
}