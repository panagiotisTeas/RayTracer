#pragma once

#include <vector>
#include <cstdint>

struct ImageData
{
    int width = 0;
    int height = 0;
    int channels = 0; //* 1 PBM/PGM, 3 PPM, <=4 PAM
    
    std::vector<uint8_t> pixels;
};
