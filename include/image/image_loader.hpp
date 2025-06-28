#pragma once

#include <string>

#include "image_data.hpp"

class ImageLoader
{
public:
    virtual ~ImageLoader() = default;
    virtual bool load(const std::string& filename, ImageData& out) const = 0;
};