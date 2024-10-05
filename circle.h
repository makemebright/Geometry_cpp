#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include "IShape.h"
#include "vector.h"

namespace geometry {
  class Circle : public IShape {
   public:
    Point center;
    int64_t radius;

    Circle(const Point&, uint64_t);

    Circle& Move(const Vector&) override;

    bool ContainsPoint(const Point&) const override;

    bool CrossesSegment(const Segment&) const override;

    Circle* Clone() const override;

    std::string ToString() const override;
  };
}

#endif