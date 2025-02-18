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
TEST_CASE("Tuple::operator- subtract two points") {
    Tuple p1 = Tuple::point(3, 2, 1);
    Tuple p2 = Tuple::point(5, 6, 7);
    REQUIRE(p1 - p2 == Tuple::vector(-2, -4, -6));
}
TEST_CASE("Tuple::operator- subtract a vector from a point") {
    Tuple vec = Tuple::vector(5, 6, 7);
    Tuple point = Tuple::point(3, 2, 1);
    REQUIRE(point - vec == Tuple::point(-2, -4, -6));
}
TEST_CASE("Tuple::operator- subtract two vectors") {
    Tuple vec1 = Tuple::vector(3, 2, 1);
    Tuple vec2 = Tuple::vector(5, 6, 7);
    REQUIRE(vec1 - vec2 == Tuple::vector(-2, -4, -6));
}
TEST_CASE("Tuple::operator- negates a tuple") {
    Tuple t = Tuple(1, -2, 3, -4);
    REQUIRE(-t == Tuple(-1, 2, -3, 4));
}
TEST_CASE("Tuple::operator* multiplies each field by a scalar") {
    Tuple t = Tuple(1, -2, 3, -4);
    float scalar = 3.5f;
    REQUIRE(t * scalar == Tuple(3.5, -7, 10.5, -14));
}
TEST_CASE("Tuple::operator/ divides each field by a scalar") {
    Tuple t = Tuple(1, -2, 3, -4);
    float scalar = 2.0f;
    REQUIRE(t / scalar == Tuple(0.5, -1, 1.5, -2));
}
TEST_CASE("Tuple::magnitude returns the magnitude of a vector") {
    Tuple vec1 = Tuple::vector(1, 0, 0);
    Tuple vec2 = Tuple::vector(0, 1, 0);
    Tuple vec3 = Tuple::vector(0, 0, 1);
    Tuple vec4 = Tuple::vector(1, 2, 3);
    Tuple vec5 = Tuple::vector(-1, -2, -3);

    REQUIRE(vec1.magnitude() == 1);
    REQUIRE(vec2.magnitude() == 1);
    REQUIRE(vec3.magnitude() == 1);
    REQUIRE(floatsAreEqual(vec4.magnitude(),sqrt(14)));
    REQUIRE(floatsAreEqual(vec5.magnitude(),sqrt(14)));
}
///
/// UTILS
///
TEST_CASE("floatsAreEqual returns true if floats are equal") {
    REQUIRE(floatsAreEqual(4.3, 4.3) == true);
}