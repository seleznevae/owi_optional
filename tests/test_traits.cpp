#include "catch/catch.hpp"
#include "owi/optional.hpp"


TEST_CASE("Test traits", "[traits]" ) {
    using owi_i = owi::optional<int>;

    REQUIRE(std::is_swappable_v<owi_i> == true);
    // TODO: add more traits checks
}

