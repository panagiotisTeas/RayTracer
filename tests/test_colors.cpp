#include <catch2/catch_test_macros.hpp>

#include "math/colors.hpp"
#include "math/utils.hpp"

TEST_CASE("color hadamard product test", "[Colors]")
{
    color col1 = createColor(1.0f, 0.2f, 0.4f);
    color col2 = createColor(0.9f, 1.0f, 0.1f);
    color col3 = hadamardProduct(col1, col2);

    REQUIRE(equal(col3.getX(), 0.9f));
    REQUIRE(equal(col3.getY(), 0.2f));
    REQUIRE(equal(col3.getZ(), 0.04f));
}