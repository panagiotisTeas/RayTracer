#include <catch2/catch_test_macros.hpp>

#include "math/tuples.hpp"

TEST_CASE("tuple implementation test", "[Tuples]")
{
    Tuple point(1.0f, 2.0f, 3.0f, 1.0f);
    Tuple vector(1.0f, 2.0f, 3.0f, 0.0f);

    REQUIRE(point.getX() == 1.0f);
    REQUIRE(point.getY() == 2.0f);
    REQUIRE(point.getZ() == 3.0f);
    REQUIRE(point.getW() == 1.0f);

    REQUIRE(point.isPoint() == true);
    REQUIRE(point.isVector() == false);
    REQUIRE(vector.isPoint() == false);
    REQUIRE(vector.isVector() == true);
}