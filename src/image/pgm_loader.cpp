#include "pgm_loader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

bool PGMloader::load(const std::string& filename, ImageData& out) const {
    std::ifstream file(filename, std::ios::in);

    if (!file)
    {
        std::cerr << "Could not open .pgm file: " << filename << "\n";
        return false;
    }

    std::string line;
    std::getline(file, line);

    if (line != "P2")
    {
        std::cerr << "Invalid .pgm format\n";
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
        std::cerr << "Invalid .pgm metadata\n";
        return false;
    }
    
    out.width = width;
    out.height = height;
    out.channels = 1;
    out.pixels.resize(width * height * out.channels);
    
    int gray;
    int index = 0;

    while (file >> gray && index < out.pixels.size())
    {
        out.pixels[index++] = static_cast<uint8_t>(gray);
    }

    if (index != out.pixels.size()) {
        std::cerr << "Not enough pixel data\n";
        return false;
    }

    return true;
}