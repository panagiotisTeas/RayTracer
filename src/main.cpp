#include "window/window.hpp"

int main()
{
    Window window(800, 600, "Ray Tracer", true);

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

        //* Render

        window.swapBuffer();
        window.pollEvents();
    }
}