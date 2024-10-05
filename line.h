#ifndef LINE_H
#define LINE_H
#include <cmath>
#include <iomanip>
#include <string>
#include "IShape.h"
#include "point.h"

namespace geometry {

  class Line: public IShape {
   public:
    int64_t a;
    int64_t b;
    int64_t c;

    explicit Line(const Point& p1, const Point& p2);

    explicit Line(const Segment& s);

    Line(int64_t a, int64_t b, int64_t c);

    Line(const Line& other);

    Line& Move(const Vector& v) override;
    bool ContainsPoint(const Point& p) const override;
    bool CrossesSegment(const Segment&) const override;
    Line* Clone() const override;
    std::string ToString() const override;    
  };
  Vector Guide(const Line& l);
  bool Parallel(const Line& l1, const Line& l2);
  double LinesDist(const Line& l1, const Line& l2);
}

#endif