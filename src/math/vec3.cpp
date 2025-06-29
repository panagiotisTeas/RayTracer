#include "vec3.hpp"

vec3::vec3()
    : x(0), y(0), z(0)
{}

vec3::vec3(float iX, float iY, float iZ)
    : x(iX), y(iY), z(iZ)
{}

float vec3::getX() const
{
    return x;
}

float vec3::getY() const
{
    return y;
}

float vec3::getZ() const
{
    return z;
}

bool vec3::operator==(const vec3& other) const 
{
    return x == other.x && y == other.y && z == other.z;
}

void vec3::operator+=(const vec3& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
}

vec3 vec3::operator+(const vec3& vec) const
{
    return vec3(x + vec.x, y + vec.y, z + vec.z);
}

void vec3::operator-=(const vec3& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}

vec3 vec3::operator-(const vec3& vec) const
{
    return vec3(x - vec.x, y - vec.y, z - vec.z);
}

void vec3::operator*=(const float s)
{
    x *= s;
    y *= s;
    z *= s;
}

vec3 vec3::operator*(const float s) const
{
    return vec3(x * s, y * s, z * s);
}

void vec3::operator/=(const float s)
{
    x /= s;
    y /= s;
    z /= s;
}

vec3 vec3::operator/(const float s) const
{
    return vec3(x / s, y / s, z / s);
}

float vec3::operator*(const vec3& vec) const
{
    return x * vec.x + y * vec.y + z * vec.z;
}

float vec3::dot(const vec3& vec) const
{
    return x * vec.x + y * vec.y + z * vec.z;
}

vec3 vec3::operator%(const vec3& vec) const
{
    return vec3(
        y * vec.z - z * vec.y,
        z * vec.x - x * vec.z,
        x * vec.y - y * vec.x
    );
}

vec3 vec3::cross(const vec3& vec) const
{
    return vec3(
        y * vec.z - z * vec.y,
        z * vec.x - x * vec.z,
        x * vec.y - y * vec.x
    );
}

void vec3::operator%=(const vec3& vec)
{
    *this = cross(vec);
}

float vec3::norm() const
{
    return std::sqrt(x*x + y*y + z*z);
}

vec3 vec3::unit_vector() const
{
    return *this / this->norm();
}

std::ostream& operator<<(std::ostream& out, const vec3& vec) {
    return out << vec.getX() << ' ' << vec.getY() << ' ' << vec.getZ();
}