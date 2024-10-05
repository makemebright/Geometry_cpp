#ifndef SEGMENT_H
#define SEGMENT_H

#include "IShape.h"
#include "point.h"

namespace geometry {

  class Segment: public IShape {
   public:
    Point a;
    Point b;

    Segment();
    explicit Segment(const Point& p1, const Point& p2);
    Segment(const Segment& other);

    Segment& Move(const Vector& v) override;
    bool ContainsPoint(const Point& p) const override;
    bool CrossesSegment(const Segment&) const override;
    Segment* Clone() const override;
    std::string ToString() const override;
  };
}

#endif