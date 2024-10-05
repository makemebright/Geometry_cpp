#ifndef VECTOR_H
#define VECTOR_H

#include "IShape.h"
#include "point.h"
#include "line.h"
#include <iostream>

namespace geometry {

  class Vector {
   public:
    int64_t x;
    int64_t y;

    Vector();
    Vector(int64_t x1, int64_t y1);
    Vector(int64_t x1, int64_t y1, int64_t x2, int64_t y2);
    Vector(const Point&, const Point&);
    Vector(const Vector& other);
    Vector operator+() const;
    Vector operator-() const;
    Vector& operator=(const Vector& other);
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);
    Vector& operator*=(const int64_t lambda);
    Vector& operator/=(const int64_t lambda);
    Vector operator*(const int64_t lambda) const;
    Vector operator/(const int64_t lambda) const;
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    long double Length() const;
    std::string ToString() const;
  };
  int64_t ScalarProduct(const Vector&, const Vector&);
  int64_t VectorProduct(const Vector&, const Vector&);
  double Area(const Vector&, const Vector&);
  Vector operator+(const Vector& f, const Vector& s);
  Vector operator-(const Vector& f, const Vector& s);
  Vector operator-(const Point& p1, const Point& p2);
}

#endif