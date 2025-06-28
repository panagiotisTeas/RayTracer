#pragma once

#include "image_data.hpp"
#include <glad/glad.h>
#include <imgui.h>

class ImageViewer {
public:
    ImageViewer() = default;
    ~ImageViewer();

    void loadFromImage(const ImageData& data);
    void renderImGui();

private:
    GLuint texture = 0;
    int width = 0;
    int height = 0;
};