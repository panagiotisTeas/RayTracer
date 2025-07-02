#include "math/tuples.hpp"

Tuple::Tuple()
    : x(0), y(0), z(0), w(0)
{}

Tuple::Tuple(float ux, float uy, float uz, float uw)
    : x(ux), y(uy), z(uz), w(uw)
{}

float Tuple::getX() const
{
    return x;
}

float Tuple::getY() const
{
    return y;
}

float Tuple::getZ() const
{
    return z;
}

float Tuple::getW() const
{
    return w;
}

bool Tuple::isPoint() const
{
    if(w == 1.0f)
        return true;
    
    return false;
}

bool Tuple::isVector() const
{
    if(w == 0.0f)
        return true;
    
    return false;
}