#include "ppm/ppm_renderer.hpp"

//! loadPPM must be called first
void createTexture(PPMData& in)
{
    //* Delete the existing texture, if it exists
    if(in.texture != 0)
    {
        glDeleteTextures(1, &in.texture);
    }

    //* Create new texture
    glGenTextures(1, &in.texture);
    glBindTexture(GL_TEXTURE_2D, in.texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, in.width, in.height, 0, GL_RGB, GL_UNSIGNED_BYTE, in.pixels.data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
}

//! createTexture must be called first
void renderTexture(const PPMData& in)
{
    if(in.texture == 0)
    {
        ImGui::Text("No Image loaded!");
    }
    else
    {
        ImVec2 imageSize(static_cast<float>(in.width), static_cast<float>(in.height));
        ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(in.texture)), imageSize);
    }
}