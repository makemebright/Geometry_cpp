#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vector.h"
#include "IShape.h"

namespace geometry {
  class Ray : public IShape {
   public:
    Point p;
    Vector v;

    explicit Ray(const Point&, const Vector&);

    explicit Ray(const Point&, const Point&);

    Ray(const Ray& other);

    Ray& Move(const Vector&) override;

    bool ContainsPoint(const Point&) const override;

    bool CrossesSegment(const Segment&) const override;

    Ray* Clone() const override;

    std::string ToString() const override;
  };
}

#endif