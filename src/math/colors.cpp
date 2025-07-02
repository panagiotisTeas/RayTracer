#include "math/colors.hpp"

Tuple createColor(float r, float g, float b)
{
    return Tuple(r, g, b, 0.0f);
}

color hadamardProduct(const color& col1, const color& col2)
{
    return createColor(col1.getX() * col2.getX(), col1.getY() * col2.getY(), col1.getZ() * col2.getZ());
}