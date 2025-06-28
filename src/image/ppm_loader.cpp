#include "ppm_loader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

bool PPMloader::load(const std::string& filename, ImageData& out) const {
    std::ifstream file(filename, std::ios::in);

    if (!file)
    {
        std::cerr << "Could not open .ppm file: " << filename << "\n";
        return false;
    }

    std::string line;
    std::getline(file, line);

    if (line != "P3")
    {
        std::cerr << "Invalid .ppm format\n";
        return false;
    }

    while (file.peek() == '#' || std::isspace(file.peek())) {
        if (file.peek() == '#') 
        {
            file.ignore(4096, '\n'); // skip rest of line
        } 
        else 
        {
            file.get(); // skip the whitespace character
        }
    }

    int width = 0;
    int height = 0;
    file >> width >> height;
    
    int maxValue = 0;
    file >> maxValue;

    if (width <= 0 || height <= 0 || maxValue <= 0 || maxValue > 255) 
    {
        std::cerr << "Invalid .ppm metadata\n";
        return false;
    }
    
    out.width = width;
    out.height = height;
    out.channels = 3;
    out.pixels.resize(width * height * out.channels);
    
    int r, g, b;
    int index = 0;

    while (file >> r >> g >> b && index + 2 < out.pixels.size())
    {
        out.pixels[index++] = static_cast<uint8_t>(r);
        out.pixels[index++] = static_cast<uint8_t>(g);
        out.pixels[index++] = static_cast<uint8_t>(b);
    }

    if (index != out.pixels.size()) {
        std::cerr << "Not enough pixel data\n";
        return false;
    }

    return true;
}