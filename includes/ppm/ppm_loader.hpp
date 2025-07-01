#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "ppm/ppm_data.hpp"

bool loadPPM(const std::string& filename, PPMData& out);