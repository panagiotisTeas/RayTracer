#pragma once

#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_internal.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

class GUI
{
public:
    GUI(GLFWwindow* window);
    ~GUI();

    void dockspace();
    void begin();
    void end();
};