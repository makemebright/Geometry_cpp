#include "../point.h"
#include "../circle.h"
#include "../line.h"
#include "../segment.h"
#include "../IShape.h"
#include "../polygon.h"
#include "../ray.h"
#include "../vector.h"

using geometry::Point;
using geometry::Segment;
using geometry::Line;
using geometry::Vector;

Point::Point() : x(0), y(0) {
}

Point::Point(int64_t x, int64_t y) : x(x), y(y) {
}

Point::Point(const Point& other) {
  x = other.x;
  y = other.y;
}

Point& Point::Move(const Vector& v) {
  x += v.x;
  y += v.y;
  return *this;
}

bool Point::ContainsPoint(const Point& other) const {
  return (x == other.x && y == other.y);
}

bool Point::CrossesSegment(const Segment& s) const {
  Vector v1(s.a.x, s.a.y, x, y);
  Vector v2(x, y, s.b.x, s.b.y);
  return (ScalarProduct(v1, v2) >= 0 && VectorProduct(v1, v2) == 0);
}

Point* Point::Clone() const {
  auto point = new Point(*this);
  return point;
}

std::string Point::ToString() const {
  return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

long double geometry::LineAndPointDist(const Point& p, const Line& l) {
  return (std::abs((static_cast<long double>(l.a * p.x + l.b * p.y + l.c)) / sqrt(l.a * l.a + l.b * l.b)));
}

long double geometry::SegmentAndPointDist(const Point& p, const Segment& s) {
  Vector ap(s.a.x, s.a.y, p.x, p.y);
  Line l(s.a, s.b);
  Vector ab(s.a.x, s.a.y, s.b.x, s.b.y);
  Vector bp(s.b.x, s.b.y, p.x, p.y);
  if (ScalarProduct(ap, ab) <= 0) {
    return ap.Length();
  }
  if (ScalarProduct(bp, ab) >= 0) {
    return bp.Length();
  }
  return (LineAndPointDist(p, l));
}

