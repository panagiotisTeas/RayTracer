#include "window/gui_panels.hpp"

void LeftPanel(PPMData& in, PPMRenderSettings& settings)
{
    ImGui::Begin("Left Panel");

    ImGui::InputText("filename", settings.filename, IM_ARRAYSIZE(settings.filename)); //* filename.ppm
    ImGui::DragInt("width", &settings.image_width, 1, 1, 3850); //* width of ppm
    ImGui::DragInt("height", &settings.image_height, 1, 1, 3025); //* height of ppm

    if(ImGui::Button("Render"))
    {
        //* Render

        std::ofstream out(std::string(RESOURCES_PATH) + std::string(settings.filename) + ".ppm"); //* open filename.ppm
    
        out << "P3\n" << settings.image_width << " " << settings.image_height << "\n255\n";
        
        for(int j = 0; j < settings.image_height; j++)
        {
            std::clog << "\r Scanlines(%): " << j * 100 / settings.image_height << " " << std::flush;
        
            for(int i = 0; i < settings.image_width; i++)
            {
                color col = createColor(1.0f, 0.0f, 0.0f);

                int ir = int(255.999 * col.getX());
                int ig = int(255.999 * col.getY());
                int ib = int(255.999 * col.getZ());

                out << ir << ' ' << ig << ' ' << ib << '\n';
            }
        }

        out.close();
        
    }

    //* Display
    if(ImGui::Button("Display"))
    {
        //* Load data and then create texture
        loadPPM(std::string(RESOURCES_PATH) + std::string(settings.filename) + ".ppm", in);
        createTexture(in);
    }

    ImGui::End();
}

void RightPanel()
{
    ImGui::Begin("Right Panel");

    //TODO

    ImGui::End();
}

void BottomPanel()
{
    ImGui::Begin("Bottom Panel");

    //TODO

    ImGui::End();
}

void Viewport(const PPMData& in)
{
    ImGui::Begin("Viewport");

    //* Display image
    renderTexture(in);

    ImGui::End();
}