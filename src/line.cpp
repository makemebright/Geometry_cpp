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

Line::Line(const Point& p1, const Point& p2) {
  a = -(p2.y - p1.y);
  b = (p2.x - p1.x);
  c = -(a * p1.x + b * p1.y);
}

Line::Line(const Segment& s) {
  a = Line(s.a, s.b).a;
  b = Line(s.a, s.b).b;
}

Line::Line(int64_t a, int64_t b, int64_t c) : a(a), b(b), c(c) {
}

Line::Line(const Line& other) {
  a = other.a;
  b = other.b;
  c = other.c;
}

Line& Line::Move(const Vector& v) {
  int64_t p = a * v.x + b * v.y + c;
  c = 2 * c - p;
  return *this;
}

bool Line::ContainsPoint(const Point& p) const {
  return a * p.x + b * p.y + c == 0;
}

bool Line::CrossesSegment(const Segment& s) const {
  int64_t sign1 = a * s.a.x + b * s.a.y + c;
  int64_t sign2 = a * s.b.x + b * s.b.y + c;
  return (!(sign1 * sign2 > 0));
}

Line* Line::Clone() const {
  auto copy = new Line(*this);
  return copy;
}

std::string Line::ToString() const {
  return "Line(" + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ")";
}

Vector geometry::Guide(const Line& l) {
  return {l.b, -l.a};
}

bool geometry::Parallel(const Line& l1, const Line& l2) {
  return (l1.a * l2.b == l2.a * l1.b);
}

// Vector geometry::LinesIntersection(const Line& l1, const Line& l2) {
//   auto a2 = static_cast<double>(l2.a);
//   auto b2 = static_cast<double>(l2.b);
//   auto c2 = static_cast<double>(l2.c);
//   auto a1 = static_cast<double>(l1.a);
//   auto b1 = static_cast<double>(l1.b);
//   auto c1 = static_cast<double>(l1.c);
//   double det = a1 * b2 - b1 * a2;
//   return {(-c1 * b2 + c2 * b1) / det, (-a1 * c2 + a2 * c1) / det};
// }

double geometry::LinesDist(const Line& l1, const Line& l2) {
  if (l1.b != 0) {
    double tan = static_cast<double>(l1.a) / l1.b;
    double cos = sqrt(1 / (1 + tan * tan));
    return std::abs((-(static_cast<double>(l1.c)) / l1.b + static_cast<double>(l2.c) / l2.b) * cos);
  }
  return std::abs(-(static_cast<double>(l1.c)) / l1.a + static_cast<double>(l2.c) / l2.a);
}

