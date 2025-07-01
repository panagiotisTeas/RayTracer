#pragma once

#include <iostream>
#include <stdexcept>
#include <functional>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
    using ResizeCallback = std::function<void(int width, int height)>;
    using KeyCallback = std::function<void(GLFWwindow*, int, int, int, int)>;

private:
    GLFWwindow* m_window;

    int m_width;
    int m_height;
    const char* m_title;
    bool m_VSync;

    static ResizeCallback s_resizeCallback;
    static KeyCallback s_keyCallback;

public:
    Window(int width, int height, const char* title, bool VSync);
    ~Window();

    bool shouldClose();
    void clearColor(float r, float g, float b, float a);
    void pollEvents();
    void swapBuffer();

    GLFWwindow* getWindow() const;
    int getWidth() const;
    int getHeight() const;
    bool getVSync() const;

    void setVSync(bool VSync);
    void setResizeCallback(const ResizeCallback& callback);
    void setKeyCallback(const KeyCallback& callback);

private:
    void createWindow();

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

};