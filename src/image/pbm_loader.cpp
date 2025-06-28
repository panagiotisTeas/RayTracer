#include "pbm_loader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

bool PBMloader::load(const std::string& filename, ImageData& out) const {
    std::ifstream file(filename, std::ios::in);

    if (!file)
    {
        std::cerr << "Could not open .pbm file: " << filename << "\n";
        return false;
    }

    std::string line;
    std::getline(file, line);

    if (line != "P1")
    {
        std::cerr << "Invalid .pbm format\n";
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

    if (width <= 0 || height <= 0) 
    {
        std::cerr << "Invalid .pbm metadata\n";
        return false;
    }
    
    out.width = width;
    out.height = height;
    out.channels = 1;
    out.pixels.resize(width * height * out.channels);
    
    int bit;
    int index = 0;

    while (file >> bit && index < out.pixels.size())
    {
        out.pixels[index++] = static_cast<uint8_t>(bit);
    }

    if (index != out.pixels.size()) {
        std::cerr << "Not enough pixel data\n";
        return false;
    }

    return true;
}