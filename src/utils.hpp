//
// Created by Paolo Broglio on 18/02/25.
//
#ifndef UTILS_H
#define UTILS_H

#include <cmath>

constexpr float EPSILON = 0.00001f;

inline bool floatsAreEqual(float a, float b) {
  return fabs(a - b) < EPSILON;
}

#endif