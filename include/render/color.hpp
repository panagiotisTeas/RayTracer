#pragma once

#include <iostream>
#include <fstream>

#include "vec3.hpp"

using color3 = vec3;

void write_color(std::ofstream& out, const color3& pixel_color);