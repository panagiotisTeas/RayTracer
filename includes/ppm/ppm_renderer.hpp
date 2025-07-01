#pragma once

#include "ppm/ppm_data.hpp"

#include <glad/glad.h>
#include <imgui.h>

void createTexture(PPMData& in);
void renderTexture(const PPMData& in);