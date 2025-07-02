#include "math/utils.hpp"

bool equal(float x, float y)
{
    if(abs(x - y) < EPSILON)
        return true;

    return false;
}