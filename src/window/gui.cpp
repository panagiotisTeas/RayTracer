#include "window/gui.hpp"

GUI::GUI(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext(); //* Create ImGui context

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; //* Enable docking feature

    //* Set default ImGui dark theme
    ImGui::StyleColorsDark();

    //* Initialize ImGui for GLFW and OpenGL
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

}

GUI::~GUI()
{
    //* Cleanup OpenGL3 and GLFW backend and Destroy ImGui context
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

//* Creates a dockspace layout
void GUI::dockspace()
{
    static bool opt_fullscreen_persistent = true;
    bool opt_fullscreen = opt_fullscreen_persistent;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    //* Setup window flags for the main dockspace window
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen) {
        //* Set the window to cover the entire viewport
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    //* Begin main dockspace window
    ImGui::Begin("DockSpace Demo", nullptr, window_flags);
    ImGui::PopStyleVar(2);

    //* Create dockspace only on the first frame
    static bool first_time = true;
    if (first_time) {
        first_time = false;

        //* Remove any existing dock layout
        ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
        ImGui::DockBuilderRemoveNode(dockspace_id); 
        //* Add a new dockspace node
        ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
        ImGui::DockBuilderSetNodeSize(dockspace_id, ImGui::GetMainViewport()->Size);

        //* Split main node into left and right
        ImGuiID left   = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Left, 0.2f, nullptr, &dockspace_id);
        ImGuiID right  = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Right, 0.2f, nullptr, &dockspace_id);
        ImGuiID bottom = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Down, 0.25f, nullptr, &dockspace_id);

        ImGuiID center = dockspace_id; //* Remaining central node

        //* Dock windows into the created areas
        ImGui::DockBuilderDockWindow("Left Panel", left);
        ImGui::DockBuilderDockWindow("Right Panel", right);
        ImGui::DockBuilderDockWindow("Bottom Panel", bottom);
        ImGui::DockBuilderDockWindow("Viewport", center);

        ImGui::DockBuilderFinish(dockspace_id);
    }

    //* Create and render the dockspace
    ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    ImGui::End(); //* End the main dockspace window
}

void GUI::begin()
{
    //* Start a new frame for OpenGL, GLFW and ImGui
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void GUI::end()
{
    ImGui::Render(); //* Finalize the frame
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); //* Render ImGui draw data
}