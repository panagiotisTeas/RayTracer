#include <catch2/catch_test_macros.hpp>

#include "math/tuples.hpp"
#include "math/utils.hpp"

TEST_CASE("tuple implementation test", "[Tuples]")
{
    Tuple point(1.0f, 2.0f, 3.0f, 1.0f);
    Tuple vector(1.0f, 2.0f, 3.0f, 0.0f);
    Tuple random(1.0f, 2.0f, 3.0f, 0.5f);

    REQUIRE(point.getX() == 1.0f);
    REQUIRE(point.getY() == 2.0f);
    REQUIRE(point.getZ() == 3.0f);
    REQUIRE(point.getW() == 1.0f);

    REQUIRE(point.isPoint() == true);
    REQUIRE(point.isVector() == false);
    REQUIRE(vector.isPoint() == false);
    REQUIRE(vector.isVector() == true);
    REQUIRE(random.isPoint() == false);
    REQUIRE(random.isVector() == false);
}

TEST_CASE("factory function test", "[Tuples]")
{
    vec3 vector = createVector(1.0f, 2.0f, 3.0f);
    pt3 point = createPoint(1.0f, 2.0f, 3.0f);

    REQUIRE(point.isPoint() == true);
    REQUIRE(point.isVector() == false);
    REQUIRE(vector.isPoint() == false);
    REQUIRE(vector.isVector() == true);
}

TEST_CASE("tuple operations test", "[Tuples]")
{
    //* Addition
    
    Tuple tup1(1.0f, -2.0f, 3.0f, 1.0f);
    Tuple tup2(-4.0f, 5.0f, -6.0f, 0.0f);

    Tuple tup3 = tup1 + tup2;

    REQUIRE(tup3.getX() == -3.0f);
    REQUIRE(tup3.getY() == 3.0f);
    REQUIRE(tup3.getZ() == -3.0f);
    REQUIRE(tup3.getW() == 1.0f);

    tup3 += tup1;

    REQUIRE(tup3.getX() == -2.0f);
    REQUIRE(tup3.getY() == 1.0f);
    REQUIRE(tup3.getZ() == 0.0f);
    REQUIRE(tup3.getW() == 2.0f);

    //* Subtraction

    Tuple tup4 = tup1 - tup2;

    REQUIRE(tup4.getX() == 5.0f);
    REQUIRE(tup4.getY() == -7.0f);
    REQUIRE(tup4.getZ() == 9.0f);
    REQUIRE(tup4.getW() == 1.0f);

    tup4 -= tup1;

    REQUIRE(tup4.getX() == 4.0f);
    REQUIRE(tup4.getY() == -5.0f);
    REQUIRE(tup4.getZ() == 6.0f);
    REQUIRE(tup4.getW() == 0.0f);

    //* Negation

    Tuple tup5 = -tup1;
    REQUIRE(tup5.getX() == -1.0f);
    REQUIRE(tup5.getY() == 2.0f);
    REQUIRE(tup5.getZ() == -3.0f);
    REQUIRE(tup5.getW() == -1.0f);

    //* Multiplication/Division by Scalar

    tup5 /= 2.0f;

    REQUIRE(equal(tup5.getX(), -0.5f));
    REQUIRE(equal(tup5.getY(), 1.0f));
    REQUIRE(equal(tup5.getZ(), -1.5f));
    REQUIRE(equal(tup5.getW(), -0.5f));

    tup5 *= 2.0f;

    REQUIRE(equal(tup5.getX(), -1.0f));
    REQUIRE(equal(tup5.getY(), 2.0f));
    REQUIRE(equal(tup5.getZ(), -3.0f));
    REQUIRE(equal(tup5.getW(), -1.0f));

    Tuple tup6 = 2.0f * tup5;
    Tuple tup7 = tup5 * 2.0f;
    Tuple tup8 = tup5 / 2.0f;

    REQUIRE(equal(tup6.getX(), -2.0f));
    REQUIRE(equal(tup6.getY(), 4.0f));
    REQUIRE(equal(tup6.getZ(), -6.0f));
    REQUIRE(equal(tup6.getW(), -2.0f));

    REQUIRE(equal(tup7.getX(), -2.0f));
    REQUIRE(equal(tup7.getY(), 4.0f));
    REQUIRE(equal(tup7.getZ(), -6.0f));
    REQUIRE(equal(tup7.getW(), -2.0f));

    REQUIRE(equal(tup8.getX(), -0.5f));
    REQUIRE(equal(tup8.getY(), 1.0f));
    REQUIRE(equal(tup8.getZ(), -1.5f));
    REQUIRE(equal(tup8.getW(), -0.5f));

    //* Magnitude

    vec3 vector1 = createVector(1.0f, 0.0f, 0.0f);
    vec3 vector2 = createVector(0.0f, 1.0f, 0.0f);
    vec3 vector3 = createVector(0.0f, 0.0f, 1.0f);
    vec3 vector4 = createVector(1.0f, 2.0f, 3.0f);
    vec3 vector5 = createVector(-1.0f, -2.0f, -3.0f);

    REQUIRE(equal(vector1.length(), 1.0f));
    REQUIRE(equal(vector2.length(), 1.0f));
    REQUIRE(equal(vector3.length(), 1.0f));
    REQUIRE(equal(vector4.length(), sqrt(14.0f)));
    REQUIRE(equal(vector5.length(), sqrt(14.0f)));

    //* Normalize

    vec3 vector6 = normalize(createVector(1.0f, 2.0f, 3.0f));
    
    REQUIRE(equal(vector6.length(), 1.0f));

    //* Dot product

    vec3 vector7 = createVector(1.0f, 2.0f, 3.0f);
    vec3 vector8 = createVector(2.0f, 3.0f, 4.0f);

    REQUIRE(dot(vector7, vector8) == 20.0f);

    //* Cross product

    vec3 vector9 = cross(vector7, vector8);
    vec3 vector10 = cross(vector8, vector7);

    REQUIRE(vector9.getX() == -1.0f);
    REQUIRE(vector9.getY() == 2.0f);
    REQUIRE(vector9.getZ() == -1.0f);

    REQUIRE(vector10.getX() == 1.0f);
    REQUIRE(vector10.getY() == -2.0f);
    REQUIRE(vector10.getZ() == 1.0f);
}