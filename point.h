#ifndef POINT_H
#define POINT_H
#include "IShape.h"

namespace geometry {

  class Point: public IShape {
   public:
    int64_t x;
    int64_t y;

    Point();
    Point(int64_t x, int64_t y);
    Point(const Point& other);

    Point& Move(const Vector& v) override;
    bool ContainsPoint(const Point& other) const override;
    bool CrossesSegment(const Segment&) const override;
    Point* Clone() const override;
    std::string ToString() const override;
  };

  Vector operator-(const Point& p1, const Point& p2);

  long double LineAndPointDist(const Point& p, const Line& l);

  long double SegmentAndPointDist(const Point& p, const Segment& s);
}

#endif