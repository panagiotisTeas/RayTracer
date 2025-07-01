#include "ppm/ppm_loader.hpp"

bool loadPPM(const std::string& filename, PPMData& out)
{
    //* Open file
    std::ifstream file(filename, std::ios::in);

    //* If it cannot open file
    if (!file)
    {
        std::cerr << "Could not open .ppm file: " << filename << "\n";
        return false;
    }

    std::string line;
    std::getline(file, line);

    //* .ppm files must start with P3
    if (line != "P3")
    {
        std::cerr << "Invalid .ppm format\n";
        return false;
    }

    //* Ignore comments and whitespaces
    while (file.peek() == '#' || std::isspace(file.peek())) {
        if (file.peek() == '#') 
        {
            file.ignore(4096, '\n'); //* skip rest of line
        } 
        else 
        {
            file.get(); //* skip the whitespace character
        }
    }

    //* Get image dimensions
    int width = 0;
    int height = 0;
    file >> width >> height;
    
    //* Get maximum RGB values
    int maxValue = 0;
    file >> maxValue;

    //* Check if the data that it is passed is within bounds
    if (width <= 0 || height <= 0 || maxValue <= 0 || maxValue > 255) 
    {
        std::cerr << "Invalid .ppm metadata\n";
        return false;
    }
    
    out.width = width;
    out.height = height;
    out.pixels.resize(width * height * out.channels);
    
    int r, g, b;
    int index = 0;

    //* Get RGB values
    while (file >> r >> g >> b && index + 2 < out.pixels.size())
    {
        out.pixels[index++] = static_cast<uint8_t>(r);
        out.pixels[index++] = static_cast<uint8_t>(g);
        out.pixels[index++] = static_cast<uint8_t>(b);
    }

    //* Check if we filled all pixels
    if (index != out.pixels.size()) {
        std::cerr << "Not enough pixel data\n";
        return false;
    }

    return true;
}