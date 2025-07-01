#include "window/window.hpp"
#include "window/gui.hpp"
#include "window/gui_panels.hpp"

#include "ppm/ppm_data.hpp"
#include "ppm/ppm_renderer.hpp"
#include "ppm/ppm_render_settings.hpp"

int main()
{
    Window window(800, 600, "Ray Tracer", true);
    GUI gui(window.getWindow());

    PPMData image;
    PPMRenderSettings settings;

    //* Window Callbacks

    window.setResizeCallback([&](int width, int height) 
    {});

    window.setKeyCallback([](GLFWwindow* win, int key, int sc, int act, int mods) 
    {
        if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS)
            glfwSetWindowShouldClose(win, true);
    });

    while(!window.shouldClose())
    {
        window.clearColor(1.0f, 0.5f, 0.25f, 1.0f);

        gui.begin();
        gui.dockspace();

        //* Start render

        LeftPanel(image, settings);
        RightPanel();
        BottomPanel();
        Viewport(image);

        //* End render

        gui.end();

        window.swapBuffer();
        window.pollEvents();
    }
}