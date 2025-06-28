#include "image_viewer.hpp"
#include <iostream>

ImageViewer::~ImageViewer() {
    if (texture != 0)
        glDeleteTextures(1, &texture);
}

void ImageViewer::loadFromImage(const ImageData& data) {
    width = data.width;
    height = data.height;

    if (texture != 0)
        glDeleteTextures(1, &texture);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data.pixels.data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void ImageViewer::renderImGui() {
    if (texture == 0) {
        ImGui::Begin("Viewport");
        ImGui::Text("No image loaded.");
        ImGui::End();
    }

    ImVec2 imageSize(static_cast<float>(width), static_cast<float>(height));
    ImGui::Begin("Viewport");
    ImGui::Image(reinterpret_cast<void*>(static_cast<intptr_t>(texture)), imageSize);
    ImGui::End();
}