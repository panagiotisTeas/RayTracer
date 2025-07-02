#pragma once

#include "math/tuples.hpp"

using color = Tuple;

//* Factory functions

Tuple createColor(float r, float g, float b);

//* Color util functions

//* Blending two colors
color hadamardProduct(const color& col1, const color& col2);