//
// Created by huangqinjin on 7/18/17.
//

#include <glw/Widget.hpp>
#include <iostream>
#include <GL/gl.h>
#include <Eigen/Geometry>

using namespace glw;
using namespace Eigen;

class MainWindow : public Widget
{
    const bool orth;
    Affine3f T = Affine3f::Identity();

public:
    explicit MainWindow(bool orth) : orth(orth) {}

private:
    void initialize() override
    {
        glClearColor(0, 0, 0, 0);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH_TEST);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        if(orth) glOrtho(-1, 1, -1, 1, 1, 3 /* -1 */);
        else glFrustum(-1.0, 1.0, -1.0, 1.0, 1, 100);
        glMatrixMode(GL_MODELVIEW);

        T = Translation3f(0, 0, -2.f);

        std::cout << "initialize" << std::endl;
    }

    void paintEvent(PaintEvent* e) override
    {
        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadMatrixf(T.data());
        glTranslatef(-0.5f, -0.5f, -0.5f);

        GLfloat data[8][3] = {
                {0, 0, 0},
                {1, 0, 0},
                {1, 1, 0},
                {0, 1, 0},
                {0, 1, 1},
                {0, 0, 1},
                {1, 0, 1},
                {1, 1, 1},
        };

        glBegin(GL_QUADS);
        glColor3fv(data[0]); glVertex3fv(data[0]);
        glColor3fv(data[1]); glVertex3fv(data[1]);
        glColor3fv(data[2]); glVertex3fv(data[2]);
        glColor3fv(data[3]); glVertex3fv(data[3]);
        glEnd();

        glBegin(GL_QUADS);
        glColor3fv(data[2]); glVertex3fv(data[2]);
        glColor3fv(data[3]); glVertex3fv(data[3]);
        glColor3fv(data[4]); glVertex3fv(data[4]);
        glColor3fv(data[7]); glVertex3fv(data[7]);
        glEnd();

        glBegin(GL_QUADS);
        glColor3fv(data[4]); glVertex3fv(data[4]);
        glColor3fv(data[7]); glVertex3fv(data[7]);
        glColor3fv(data[6]); glVertex3fv(data[6]);
        glColor3fv(data[5]); glVertex3fv(data[5]);
        glEnd();

        glBegin(GL_QUADS);
        glColor3fv(data[6]); glVertex3fv(data[6]);
        glColor3fv(data[5]); glVertex3fv(data[5]);
        glColor3fv(data[0]); glVertex3fv(data[0]);
        glColor3fv(data[1]); glVertex3fv(data[1]);
        glEnd();

        glBegin(GL_QUADS);
        glColor3fv(data[0]); glVertex3fv(data[0]);
        glColor3fv(data[3]); glVertex3fv(data[3]);
        glColor3fv(data[4]); glVertex3fv(data[4]);
        glColor3fv(data[5]); glVertex3fv(data[5]);
        glEnd();

        glBegin(GL_QUADS);
        glColor3fv(data[1]); glVertex3fv(data[1]);
        glColor3fv(data[2]); glVertex3fv(data[2]);
        glColor3fv(data[7]); glVertex3fv(data[7]);
        glColor3fv(data[6]); glVertex3fv(data[6]);
        glEnd();

        // Draw the scene:
//        glBegin(GL_TRIANGLES);
//        glColor3f(1.0f, 0.0f, 0.0f);
//        glVertex3f(-1, -1, 0.0);
//
//        glColor3f(0.0f, 1.0f, 0.0f);
//        glVertex3f(1, 0.0, 0.0);
//
//        glColor3f(0.0f, 0.0f, 1.0f);
//        glVertex3f(0.0, 1, 0.0);
//        glEnd();
//
//        repaint(1);
        std::cout << "paint " << e->dt << std::endl;
    }

    void keyEvent(KeyEvent* e) override
    {
        std::cout << "key " << (char)e->key << ' ' << (int)e->action << std::endl;
    }

    void mouseEvent(MouseEvent* e) override
    {
        std::cout << "mouse " << (int)e->button << ' ' << (int)e->action << std::endl;
        if(e->button == MouseButton::MIDDLE && e->action == KeyAction::RELEASE)
        {
            initialize();
            repaint();
        }
    }

    void wheelEvent(WheelEvent* e) override
    {
        std::cout << "wheel " << e->dx << std::endl;

        if(orth) T.linear() *= (1 + e->dx * 0.1f);
        else T.translation() += Vector3f(0, 0, -e->dx * 0.1f);
        repaint();
    }

    void cursorEvent(CursorEvent* e) override
    {
        if(KeyAction::PRESS == status(MouseButton::LEFT))
        {
            Vector3f axis(e->dp.y, e->dp.x, 0);
            T.linear() = AngleAxisf(axis.norm() * 0.01f, axis.normalized()) * T.linear();
        }
        else if(KeyAction::PRESS == status(MouseButton::RIGHT))
        {
            Vector3f dir(e->dp.x, -e->dp.y, 0);
            T.translation() += dir * 0.01f;
        }
        else
        {
            return;
        }
        repaint();
        std::cout << "cursor " << ' ' << (int)e->action << ' ' << e->dp.x << ' ' << e->dp.y << std::endl;
    }

    void moveEvent(MoveEvent* e) override
    {
        std::cout << "move " << e->dp.x << ' ' << e->dp.y << std::endl;
    }

    void resizeEvent(SizeEvent* e) override
    {
        auto sz = size();
        auto s = static_cast<GLsizei>(std::min(sz.w, sz.h));
        glViewport(0, 0, s, s);

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
    std::cout << "STDCPP_DEFAULT_NEW_ALIGNMENT = "
              #ifdef __STDCPP_DEFAULT_NEW_ALIGNMENT__
              << __STDCPP_DEFAULT_NEW_ALIGNMENT__
              #else
              << "NULL"
              #endif
              << "    EIGEN_MAX_STATIC_ALIGN_BYTES = "
              << EIGEN_MAX_STATIC_ALIGN_BYTES
              << std::endl;

    Application app(argc, argv);
    MainWindow w(argc <= 1);
    w.rename("MainWindow");
    w.resize({200, 200});
    w.show();
    return app.exec();
}