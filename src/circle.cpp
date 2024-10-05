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
using geometry::Circle;
using geometry::Vector;

Circle::Circle(const Point& p, uint64_t r) : center(p), radius(r) {
}

Circle& Circle::Move(const Vector& vector) {
  center.Move(vector);
  return *this;
}

bool Circle::ContainsPoint(const Point& point) const {
  Vector target(point.x, point.y, center.x, center.y);
  int64_t l = target.x * target.x + target.y * target.y;
  return (l <= radius * radius);
}

bool Circle::CrossesSegment(const Segment& s) const {
  long double len = geometry::SegmentAndPointDist(center, s);
  long double epsilon = 10e-12;
  auto rad = static_cast<long double>(radius);
  long double delta = len - rad;
  Vector ca(center, s.a);
  Vector cb(center, s.b);  
  bool flag = (ca.x * ca.x + ca.y * ca.y < radius * radius);
  flag = (flag && (cb.x * cb.x + cb.y * cb.y < radius * radius));
  return (delta <= epsilon) && (!flag);
}

Circle* Circle::Clone() const {
  auto copy = new Circle(center, radius);
  return copy;
}

std::string Circle::ToString() const {
  return "Circle(" + center.ToString() + ", " + std::to_string(radius) + ")";
}
