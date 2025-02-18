//
// Created by Paolo Broglio on 18/02/25.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "../src/Tuple.hpp"
#include "../src/utils.hpp"

///
/// TUPLES
///
TEST_CASE("Tuple::point creates a Tuple with w = 1") {
    REQUIRE(Tuple::point(4, -4, 3) == Tuple(4, -4, 3, 1));
}
TEST_CASE("Tuple::vector creates a Tuple with w = 0") {
    REQUIRE(Tuple::vector(4, -4, 3) == Tuple(4, -4, 3, 0));
}
TEST_CASE("Tuple::operator+ adds two vectors") {
    Tuple vec1 = Tuple::vector(4, -4, 3);
    Tuple vec2 = Tuple::vector(4, -4, 3);
    REQUIRE(vec1 + vec2 == Tuple::vector(8, -8, 6));
}
TEST_CASE("Tuple::operator+ adds a vector and a point") {
    Tuple vec = Tuple::vector(4, -4, 3);
    Tuple point = Tuple::point(4, -4, 3);
    REQUIRE(vec + point == Tuple::point(8, -8, 6));
}
///
/// UTILS
///
TEST_CASE("floatsAreEqual returns true if floats are equal") {
    REQUIRE(floatsAreEqual(4.3, 4.3) == true);
}