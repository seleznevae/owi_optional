#include "catch/catch.hpp"
#include "owi/optional.hpp"

#include <array>
#include <string>

TEST_CASE("Equality operators", "[compare]" ) {
    owi::optional<int> oi_e1;
    owi::optional<int> oi_e2{owi::nullopt};
    owi::optional<int> oi_1{1};
    owi::optional<int> oi_1_{1};
    owi::optional<int> oi_2{2};

    REQUIRE(oi_e1 == oi_e2);
    REQUIRE(oi_e1 == owi::nullopt);
    REQUIRE(oi_e1 == std::nullopt);
    REQUIRE(oi_1 == oi_1_);
    REQUIRE(oi_1 == 1);
    REQUIRE(oi_1 == std::optional{1});

    REQUIRE(oi_e2 == oi_e1);
    REQUIRE(owi::nullopt == oi_e1);
    REQUIRE(std::nullopt == oi_e1);
    REQUIRE(oi_1_ == oi_1);
    REQUIRE(1 == oi_1);
    REQUIRE(std::optional{1} == oi_1);

    REQUIRE(oi_e1 != oi_1);
    REQUIRE(oi_e1 != oi_2);
    REQUIRE(oi_1 != oi_2);
    REQUIRE(oi_1 != owi::nullopt);
    REQUIRE(oi_1 != std::nullopt);
    REQUIRE(oi_1 != std::optional{32});
}

TEST_CASE("Less, greater operators", "[compare]" ) {
    REQUIRE(owi::optional<int>{1} <= owi::optional<int>{1});
    REQUIRE(owi::optional<int>{1} <= owi::optional<int>{2});
    REQUIRE(owi::optional<int>{1} < owi::optional<int>{2});

    REQUIRE(owi::optional<int>{1} <= std::optional<int>{1});
    REQUIRE(owi::optional<int>{1} <= std::optional<int>{2});
    REQUIRE(owi::optional<int>{1} < std::optional<int>{2});

    REQUIRE(std::optional<int>{1} <= owi::optional<int>{1});
    REQUIRE(std::optional<int>{1} <= owi::optional<int>{2});
    REQUIRE(std::optional<int>{1} < owi::optional<int>{2});

    REQUIRE(owi::optional<int>{1} <= 1);
    REQUIRE(owi::optional<int>{1} <= 42);
    REQUIRE(owi::optional<int>{1} < 42);

    REQUIRE(1 >= owi::optional<int>{1});
    REQUIRE(42 >= owi::optional<int>{1});
    REQUIRE(42 > owi::optional<int>{1});


    REQUIRE(owi::optional<int>{1} >= owi::optional<int>{1});
    REQUIRE(owi::optional<int>{1} >= owi::optional<int>{0});
    REQUIRE(owi::optional<int>{1} > owi::optional<int>{0});

    REQUIRE(owi::optional<int>{1} >= std::optional<int>{1});
    REQUIRE(owi::optional<int>{1} >= std::optional<int>{0});
    REQUIRE(owi::optional<int>{1} > std::optional<int>{0});

    REQUIRE(std::optional<int>{1} >= owi::optional<int>{1});
    REQUIRE(std::optional<int>{1} >= owi::optional<int>{0});
    REQUIRE(std::optional<int>{1} > owi::optional<int>{0});

    REQUIRE(owi::optional<int>{1} >= 1);
    REQUIRE(owi::optional<int>{1} >= -42);
    REQUIRE(owi::optional<int>{1} > -42);

    REQUIRE(1 <= owi::optional<int>{1});
    REQUIRE(-42 <= owi::optional<int>{1});
    REQUIRE(-42 < owi::optional<int>{1});

}