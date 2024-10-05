#ifndef ISHAPE_H
#define ISHAPE_H
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
#include <memory>

namespace geometry {
  class Point;
  class Segment;
  class Vector;
  class Line;

  class IShape {
   public:
    virtual IShape& Move(const Vector&) = 0;
    virtual bool ContainsPoint(const Point&) const = 0;
    virtual bool CrossesSegment(const Segment&) const = 0;
    virtual IShape* Clone() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~IShape() = default;
  };
}

#endif