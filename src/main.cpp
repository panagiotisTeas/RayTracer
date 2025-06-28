#include <iostream>

#include "window.hpp"
#include "gui.hpp"

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

        ImGuiPPMRender(ppmLoader, viewer, image);

        viewer.renderImGui();

        gui.end();

        win.swapBuffer();
        win.pollEvents();
    }
}

void ImGuiPPMRender(PPMloader& ppmLoader, ImageViewer& viewer, ImageData& image)
{
    ImGui::Begin("PPM Controls");

    if(ImGui::Button("Render"))
    {
        int image_width = 256;
        int image_height = 256;
    
        std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
        
        for(int j = 0; j < image_height; j++)
        {
            std::clog << "\r Scanlines remaining: " << (image_height - j) << " " << std::flush;
        
            for(int i = 0; i < image_width; i++)
            {
                auto r = double(i) / (image_width - 1);
                auto g = double(j) / (image_height - 1);
                auto b = 0.0;
        
                int ir = int(255.999 * r);
                int ig = int(255.999 * g);
                int ib = int(255.999 * b);
            }
        }
        
        std::clog << "\r Done \n";

        ppmLoader.load(std::string(RESOURCES_PATH) + "test.ppm", image);
        viewer.loadFromImage(image);
    }

    ImGui::End();
}