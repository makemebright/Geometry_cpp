#ifndef POLYGON_H
#define POLYGON_H

#include <cstddef>
#include <vector>
#include "IShape.h"
#include "point.h"


namespace geometry {
  
  class Polygon : public IShape {
   public:
    std::vector<Point> vertices;

    explicit Polygon(const std::vector<Point>& v);

    explicit Polygon(const std::vector<Point>&& other);

    Polygon& Move(const Vector&) override;

    bool ContainsPoint(const Point&) const override;

    bool CrossesSegment(const Segment&) const override;

    Polygon* Clone() const override;

    std::string ToString() const override;
  };

}

#endif