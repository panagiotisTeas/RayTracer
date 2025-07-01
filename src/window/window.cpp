#include "window/window.hpp"

Window::ResizeCallback Window::s_resizeCallback = nullptr;
Window::KeyCallback Window::s_keyCallback = nullptr;

Window::Window(int width, int height, const char* title, bool VSync)
    : m_window(nullptr), m_width(width), m_height(height), m_title(title)
{
    //* Initialize GLFW
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    //* Window Hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    createWindow();

    //* Initialize GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        glfwDestroyWindow(m_window);
        glfwTerminate(); 
        throw std::runtime_error("Failed to initialize GLAD");
    }

    setVSync(VSync);

    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
    glfwSetKeyCallback(m_window, keyCallback);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void Window::clearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::swapBuffer()
{
    glfwSwapBuffers(m_window);
}

GLFWwindow* Window::getWindow() const
{
    return m_window;
}

int Window::getWidth() const
{
    return m_width;
}

int Window::getHeight() const
{
    return m_height;
}

bool Window::getVSync() const
{
    return m_VSync;
}

void Window::setVSync(bool VSync)
{
    m_VSync = VSync;
    glfwSwapInterval(VSync ? 1 : 0);
}

void Window::setResizeCallback(const ResizeCallback& callback)
{
    s_resizeCallback = callback;
}

void Window::setKeyCallback(const KeyCallback& callback)
{
    s_keyCallback = callback;
}

void Window::createWindow()
{
    m_window = glfwCreateWindow(m_width, m_height, m_title, 0, 0);
    if (m_window == nullptr)
    {
        glfwTerminate(); 
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_window);
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);

    if (s_resizeCallback)
        s_resizeCallback(width, height);
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (s_keyCallback)
        s_keyCallback(window, key, scancode, action, mods);
}