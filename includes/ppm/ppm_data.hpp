#pragma once

#include <vector>
#include <cstdint>

#include <glad/glad.h>

struct PPMData
{
    int width = 0;
    int height = 0;
    int channels = 3; //* Refers to RGB
    
    std::vector<uint8_t> pixels;

    GLuint texture = 0;
};