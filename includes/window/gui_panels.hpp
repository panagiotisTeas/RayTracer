#pragma once

#include <imgui.h>

#include "ppm/ppm_data.hpp"
#include "ppm/ppm_loader.hpp"
#include "ppm/ppm_renderer.hpp"
#include "ppm/ppm_render_settings.hpp"

#include "math/colors.hpp"

void LeftPanel(PPMData& in, PPMRenderSettings& settings);
void RightPanel();
void BottomPanel();
void Viewport(const PPMData& in);