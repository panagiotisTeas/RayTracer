#include "panels.hpp"

void ImGuiPPMRender(PPMloader& ppmLoader, RenderSettings& settings, ImageViewer& viewer, ImageData& image)
{
    ImGui::Begin("PPM Controls");

    ImGui::InputText("filename", settings.file, IM_ARRAYSIZE(settings.file));
    ImGui::DragInt("width", &settings.width, 1, 0, 3850);
    ImGui::DragInt("height", &settings.height, 1, 0, 3025);

    if(ImGui::Button("Render"))
    {
        std::ofstream out(std::string(RESOURCES_PATH) + std::string(settings.file) + ".ppm");
    
        out << "P3\n" << settings.width << " " << settings.height << "\n255\n";
        
        for(int j = 0; j < settings.height; j++)
        {
            std::clog << "\r Scanlines remaining: " << (settings.height - j) << " " << std::flush;
        
            for(int i = 0; i < settings.width; i++)
            {
                auto r = double(i) / (settings.width - 1);
                auto g = double(j) / (settings.height - 1);
                auto b = 0.0;
        
                int ir = int(255.999 * r);
                int ig = int(255.999 * g);
                int ib = int(255.999 * b);

                out << ir << ' ' << ig << ' ' << ib << '\n';
            }
        }

        out.close();
        
    }

    if(ImGui::Button("Display"))
    {
        ppmLoader.load(std::string(RESOURCES_PATH) + std::string(settings.file) + ".ppm", image);
        viewer.loadFromImage(image);
    }

    ImGui::End();
}