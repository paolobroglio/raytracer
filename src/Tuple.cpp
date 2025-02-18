//
// Created by Paolo Broglio on 18/02/25.
//
#include "Tuple.hpp"
#include "utils.hpp"

Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
}

float Tuple::magnitude() const {
    return sqrtf(x * x + y * y + z * z + w * w);
}

Tuple Tuple::point(float x, float y, float z) {
    return {x, y, z, 1};
}

Tuple Tuple::vector(float x, float y, float z) {
    return {x, y, z, 0};
}

bool Tuple::operator==(const Tuple &other) const {
    const bool equalX = floatsAreEqual(this->x, other.x);
    const bool equalY = floatsAreEqual(this->y, other.y);
    const bool equalZ = floatsAreEqual(this->z, other.z);
    const bool equalW = floatsAreEqual(this->w, other.w);

    return equalX && equalY && equalZ && equalW;
}

Tuple Tuple::operator+(const Tuple &other) const {
    return {x + other.x, y + other.y, z + other.z, w + other.w};
}

Tuple Tuple::operator-(const Tuple &other) const {
    return {x - other.x, y - other.y, z - other.z, w - other.w};
}

Tuple Tuple::operator-() const {
    return {-x, -y, -z, -w};
}

Tuple Tuple::operator*(const float &scalar) const {
    return {x * scalar, y * scalar, z * scalar, w * scalar};
}

Tuple Tuple::operator/(const float &scalar) const {
    return {x / scalar, y / scalar, z / scalar, w / scalar};
}
