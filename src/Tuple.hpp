//
// Created by Paolo Broglio on 18/02/25.
//

#ifndef TUPLE_H
#define TUPLE_H

class Tuple {
  private:
    float x, y, z, w;
  public:
    Tuple(float x, float y, float z, float w);
    static Tuple point(float x, float y, float z);
    static Tuple vector(float x, float y, float z);

  bool operator==(const Tuple &) const;
  Tuple operator+(const Tuple &) const;
};
#endif
