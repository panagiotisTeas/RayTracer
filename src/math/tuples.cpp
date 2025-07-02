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

void Tuple::operator+=(const Tuple& tup)
{
    x += tup.getX();
    y += tup.getY();
    z += tup.getZ();
    w += tup.getW();
}

Tuple Tuple::operator+(const Tuple& tup) const
{
    return Tuple(x + tup.getX(), y + tup.getY(), z + tup.getZ(), w + tup.getW());
}

void Tuple::operator-=(const Tuple& tup)
{
    x -= tup.getX();
    y -= tup.getY();
    z -= tup.getZ();
    w -= tup.getW();
}

Tuple Tuple::operator-(const Tuple& tup) const
{
    return Tuple(x - tup.getX(), y - tup.getY(), z - tup.getZ(), w - tup.getW());
}

Tuple Tuple::operator-() const
{
    return Tuple(-x, -y, -z, -w);
}

void Tuple::operator*=(const float s)
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

void Tuple::operator/=(const float s)
{
    x /= s;
    y /= s;
    z /= s;
    w /= s;
}

Tuple Tuple::operator*(const float s) const
{
    return Tuple(s * x, s * y, s * z, s * w);
}

Tuple operator*(const float s, const Tuple& tup)
{
    return Tuple(s * tup.getX(), s * tup.getY(), s * tup.getZ(), s * tup.getW());
}

Tuple Tuple::operator/(const float s) const
{
    return Tuple(x / s, y / s, z / s, w / s);
}

float Tuple::length() const
{
    return sqrt(x * x + y * y + z * z + w * w);
}

Tuple createVector(float x, float y, float z)
{
    return Tuple(x, y, z, 0.0f);
}

Tuple createPoint(float x, float y, float z)
{
    return Tuple(x, y, z, 1.0f);
}

float length(const Tuple& tup)
{
    return sqrt(tup.getX() * tup.getX() + tup.getY() * tup.getY() + tup.getZ() * tup.getZ() + tup.getW() * tup.getW());
}

Tuple normalize(const Tuple& tup)
{
    return Tuple(tup.getX(), tup.getY(), tup.getZ(), tup.getW()) / length(tup);
}

float dot(const Tuple& tup1, const Tuple& tup2)
{
    return tup1.getX() * tup2.getX() + tup1.getY() * tup2.getY() + tup1.getZ() * tup2.getZ() + tup1.getW() * tup2.getW();
}

vec3 cross(const vec3& vec1, const vec3& vec2)
{
    return createVector(vec1.getY() * vec2.getZ() - vec1.getZ() * vec2.getY(),
                        vec1.getZ() * vec2.getX() - vec1.getX() * vec2.getZ(),
                        vec1.getX() * vec2.getY() - vec1.getY() * vec2.getX());
}
