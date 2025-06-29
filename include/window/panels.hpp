#pragma once

#include <imgui.h>

#include <iostream>
#include <fstream>
#include <string>

#include "render_settings.hpp"

#include "ppm_loader.hpp"
#include "pgm_loader.hpp"
#include "pbm_loader.hpp"

#include "image_viewer.hpp"
#include "image_data.hpp"

void ImGuiPPMRender(PPMloader& ppmLoader, RenderSettings& settings, ImageViewer& viewer, ImageData& image); 