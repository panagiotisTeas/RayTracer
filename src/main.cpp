#include <iostream>

#include "window.hpp"
#include "panels.hpp"
#include "gui.hpp"

#include "render_settings.hpp"

#include "ppm_loader.hpp"
#include "pgm_loader.hpp"
#include "pbm_loader.hpp"

#include "image_viewer.hpp"
#include "image_data.hpp"

void ImGuiPPMRender(PPMloader& ppmLoader, ImageViewer& viewer, ImageData& image);

int main()
{
    Window win(800, 600, "Ray Tracer", true);
    GUI gui(win.getWindow());

    ImageData image;
    PPMloader ppmLoader;
    PGMloader pgmLoader;
    PBMloader pbmLoader;
    ImageViewer viewer;
    RenderSettings settings;

    win.setResizeCallback([&](int width, int height) 
    {});

    win.setKeyCallback([](GLFWwindow* win, int key, int sc, int act, int mods) 
    {
        if (key == GLFW_KEY_ESCAPE && act == GLFW_PRESS)
            glfwSetWindowShouldClose(win, true);
    });

    while(!win.shouldClose())
    {
        win.clearColor(1.0f, 0.5f, 0.25f, 1.0f);
        
        gui.begin();
        gui.Dockspace();

        ImGuiPPMRender(ppmLoader, settings, viewer, image);

        viewer.renderImGui();

        gui.end();

        win.swapBuffer();
        win.pollEvents();
    }
}

