#pragma once

#include "image_loader.hpp"

class PGMloader : public ImageLoader
{
public:
    bool load(const std::string& filename, ImageData& out) const override;
};