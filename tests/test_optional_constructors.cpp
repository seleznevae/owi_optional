#include "catch/catch.hpp"
#include "owi/optional.hpp"

#include <array>
#include <string>

TEST_CASE("Default initialization", "[constructors]" ) {
    owi::optional<int> oi;
    REQUIRE_FALSE(oi.has_value());
}

TEST_CASE("Initialize with nullopt", "[constructors]" ) {
    owi::optional<int> oi{owi::nullopt};
    REQUIRE_FALSE(oi.has_value());
}