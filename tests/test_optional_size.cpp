#include "catch/catch.hpp"
#include "owi/optional.hpp"

#include <array>
#include <string>

TEST_CASE("Size of owi::optional is equal to std::optional", "[size]" ) {
    REQUIRE( sizeof(std::optional<char>) == sizeof(owi::optional<char>) );
    REQUIRE( sizeof(std::optional<int>) == sizeof(owi::optional<int>) );
    REQUIRE( sizeof(std::optional<long>) == sizeof(owi::optional<long>) );
    REQUIRE( sizeof(std::optional<std::string>) == sizeof(owi::optional<std::string>) );
    REQUIRE( sizeof(std::optional<std::array<char, 125>>) == sizeof(owi::optional<std::array<char, 125>>) );
}