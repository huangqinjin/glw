#include <glw/window.hpp>
#include <glw/gl.hpp>
#include <Eigen/Geometry>
#include <unsupported/Eigen/OpenGLSupport>
#include <iostream>

using namespace glw;
using namespace Eigen;

class MainWindow : public Window
{
    const bool orth;
    Affine3f T = Affine3f::Identity();

public:
    explicit MainWindow(bool orth) : orth(orth) {}

private:
    void initialize() override
    {
        gl::ClearColor({ gl::nf32{0}, gl::nf32{0}, gl::nf32{0}, gl::nf32{0} });
        gl::ShadeModel(gl::ShadingModel::SMOOTH);
        gl::Enable(gl::EnableCap::DEPTH_TEST);

        gl::MatrixMode(gl::MatrixMode::PROJECTION);
        gl::LoadIdentity();
        if(orth) gl::Ortho(gl::f64{-1}, gl::f64{1}, gl::f64{-1}, gl::f64{1}, gl::f64{1}, gl::f64{3/* -1 */});
        else gl::Frustum(gl::f64{-1}, gl::f64{1}, gl::f64{-1}, gl::f64{1}, gl::f64{1}, gl::f64{100});
        gl::MatrixMode(gl::MatrixMode::MODELVIEW);

        T = Translation3f(0, 0, -2.f);

        std::cout << "initialize" << std::endl;
    }

    void paintEvent(PaintEvent* e) override
    {
        // Clear the screen.
        gl::Clear(gl::ClearBufferMask::COLOR | gl::ClearBufferMask::DEPTH);

        Eigen::glLoadMatrix(T);
        Eigen::glTranslate(Vector3d::Constant(-0.5f));

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

        gl::Begin(gl::PrimitiveType::QUADS);
        gl::Color<gl::nf32>(data[0]); gl::Vertex<gl::f32>(data[0]);
        gl::Color<gl::nf32>(data[1]); gl::Vertex<gl::f32>(data[1]);
        gl::Color<gl::nf32>(data[2]); gl::Vertex<gl::f32>(data[2]);
        gl::Color<gl::nf32>(data[3]); gl::Vertex<gl::f32>(data[3]);

        gl::Color<gl::nf32>(data[2]); gl::Vertex<gl::f32>(data[2]);
        gl::Color<gl::nf32>(data[3]); gl::Vertex<gl::f32>(data[3]);
        gl::Color<gl::nf32>(data[4]); gl::Vertex<gl::f32>(data[4]);
        gl::Color<gl::nf32>(data[7]); gl::Vertex<gl::f32>(data[7]);

        gl::Color<gl::nf32>(data[4]); gl::Vertex<gl::f32>(data[4]);
        gl::Color<gl::nf32>(data[7]); gl::Vertex<gl::f32>(data[7]);
        gl::Color<gl::nf32>(data[6]); gl::Vertex<gl::f32>(data[6]);
        gl::Color<gl::nf32>(data[5]); gl::Vertex<gl::f32>(data[5]);

        gl::Color<gl::nf32>(data[6]); gl::Vertex<gl::f32>(data[6]);
        gl::Color<gl::nf32>(data[5]); gl::Vertex<gl::f32>(data[5]);
        gl::Color<gl::nf32>(data[0]); gl::Vertex<gl::f32>(data[0]);
        gl::Color<gl::nf32>(data[1]); gl::Vertex<gl::f32>(data[1]);

        gl::Color<gl::nf32>(data[0]); gl::Vertex<gl::f32>(data[0]);
        gl::Color<gl::nf32>(data[3]); gl::Vertex<gl::f32>(data[3]);
        gl::Color<gl::nf32>(data[4]); gl::Vertex<gl::f32>(data[4]);
        gl::Color<gl::nf32>(data[5]); gl::Vertex<gl::f32>(data[5]);

        gl::Color<gl::nf32>(data[1]); gl::Vertex<gl::f32>(data[1]);
        gl::Color<gl::nf32>(data[2]); gl::Vertex<gl::f32>(data[2]);
        gl::Color<gl::nf32>(data[7]); gl::Vertex<gl::f32>(data[7]);
        gl::Color<gl::nf32>(data[6]); gl::Vertex<gl::f32>(data[6]);
        gl::End();

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
        auto s = static_cast<GLsizei>((std::min)(sz.w, sz.h));
        gl::Viewport({ gl::s32{0}, gl::s32{0} }, { gl::sz{s}, gl::sz{s} });

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