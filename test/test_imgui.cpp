#include <glw/window.hpp>
#include <glw/imgui.h>
#include <glw/implot.h>
#include <GL/glew.h>

using namespace glw;

class MainWindow : public Window
{
    bool show_demo_window = true;
    bool show_another_window = false;
    bool show_plot_window = true;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    float f = 0.0f;
    int counter = 0;

    void paintEvent(PaintEvent* e) override
    {
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
           ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);
            ImGui::Checkbox("ImPlot Demo Window", &show_plot_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // 4. Show ImPlot demo window.
        if (show_plot_window)
            ImPlot::ShowDemoWindow(&show_plot_window);

        repaint();
    }

    void initialize() override
    {
        float font_pixels = 13.0f;
        ImGuiIO& io = ImGui::GetIO();
        // io.Fonts->AddFontDefault();
        io.Fonts->AddFontFromFileTTF(GLW_IMGUI_FONTS "Cousine-Regular.ttf", font_pixels);
        io.Fonts->AddFontFromFileTTF(GLW_IMGUI_FONTS "DroidSans.ttf", font_pixels);
        io.Fonts->AddFontFromFileTTF(GLW_IMGUI_FONTS "Karla-Regular.ttf", font_pixels);
        io.Fonts->AddFontFromFileTTF(GLW_IMGUI_FONTS "ProggyClean.ttf", font_pixels);
        io.Fonts->AddFontFromFileTTF(GLW_IMGUI_FONTS "ProggyTiny.ttf", font_pixels);
        io.Fonts->AddFontFromFileTTF(GLW_IMGUI_FONTS "Roboto-Medium.ttf", font_pixels);
    }
};


int main(int argc, char* argv[])
{
    Application app(argc, argv);
    MainWindow w;
    w.rename("ImGui+ImPlot GLFW+OpenGL3");
    w.resize({ 1280, 720 });
    w.show();
    return app.exec();
}
