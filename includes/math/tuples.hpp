#pragma once

#include <cmath>

//* An ordered list of points which will be used to represent points and vectors
class Tuple
{
private:
    float x;
    float y;
    float z;
    float w; //* w = 0.0f -> vector | w = 1.0f -> point

public:
    Tuple();
    Tuple(float ux, float uy, float uz, float uw);

    //* Getters

    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;

    //* Point vs Vector

    bool isPoint() const;
    bool isVector() const;

    //* Operations
    //* Addition

    void operator+=(const Tuple& tup);
    Tuple operator+(const Tuple& tup) const;
    //? Keep in mind ( point + vector -> point | point + point -> not defined | vector + vector -> vector | vector + point -> point )

    //* Subtraction

    void operator-=(const Tuple& tup);
    Tuple operator-(const Tuple& tup) const;
    //? Keep in mind ( point - vector -> point | point - point -> vector | vector - vector -> point | vector - point -> not defined )

    //* Negation

    Tuple operator-() const;

    //* Multiplication/Division by Scalar

    void operator*=(const float s);
    void operator/=(const float s);
    Tuple operator*(const float s) const;
    friend Tuple operator*(const float s, const Tuple& tup);
    Tuple operator/(const float s) const;

    //* Magnitude

    float length() const;

};

//* Factory functions

using vec3 = Tuple;
using pt3 = Tuple;

Tuple createVector(float x, float y, float z);
Tuple createPoint(float x, float y, float z);

//* Tuple util functions

float length(const Tuple& tup);
Tuple normalize(const Tuple& tup);
float dot(const Tuple& tup1, const Tuple& tup2);
//! Only on vectors
vec3 cross(const vec3& tup1, const vec3& tup2); 