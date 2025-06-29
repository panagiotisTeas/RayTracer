#pragma once

#include <cmath>
#include <iostream>

class vec3
{
private:
    float x;
    float y;
    float z;

public:
    vec3();
    vec3(float iX, float iY, float iZ);

    float getX() const;
    float getY() const;
    float getZ() const;

    bool operator==(const vec3& other) const;

    void operator+=(const vec3& vec);
    vec3 operator+(const vec3& vec) const;

    void operator-=(const vec3& vec);
    vec3 operator-(const vec3& vec) const;

    void operator*=(const float s);
    vec3 operator*(const float s) const;

    void operator/=(const float s);
    vec3 operator/(const float s) const;

    float operator*(const vec3& vec) const;
    float dot(const vec3& vec) const;

    vec3 operator%(const vec3& vec) const;
    vec3 cross(const vec3& vec) const;
    void operator%=(const vec3& vec);

    float norm() const;
    vec3 unit_vector() const;

};

using point3 = vec3;

std::ostream& operator<<(std::ostream& out, const vec3& v);