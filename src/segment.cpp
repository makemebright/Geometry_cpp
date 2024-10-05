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

Segment::Segment() = default;

Segment::Segment(const Point& p1, const Point& p2) {
  a = p1;
  b = p2;
}

Segment::Segment(const Segment& other) {
  a = other.a;
  b = other.b;
}

Segment& Segment::Move(const Vector& v) {
  a = a.Move(v);
  b = b.Move(v);
  return *this;
}

bool Segment::ContainsPoint(const Point& p) const {
  Vector v1(a.x, a.y, p.x, p.y);
  Vector v2(p.x, p.y, b.x, b.y);
  return (ScalarProduct(v1, v2) >= 0 && VectorProduct(v1, v2) == 0);
}

bool Segment::CrossesSegment(const Segment& s2) const {
  Vector ab(a.x, a.y, b.x, b.y);
  Vector cd(s2.a.x, s2.a.y, s2.b.x, s2.b.y);
  Vector ac(a.x, a.y, s2.a.x, s2.a.y);
  Vector ad(a.x, a.y, s2.b.x, s2.b.y);
  Vector cb(s2.a.x, s2.a.y, b.x, b.y);
  if (((VectorProduct(ab, ac) * VectorProduct(ab, ad) <= 0) && (VectorProduct(cd, ac) * VectorProduct(cd, cb) >= 0)) &&
      !(VectorProduct(ab, ac) == 0 && VectorProduct(ab, ad) == 0 && VectorProduct(cd, ac) == 0 &&
        VectorProduct(cd, cb) == 0)) {
    return true;
  }
  if (VectorProduct(ab, ac) == 0 && VectorProduct(ab, ad) == 0 && VectorProduct(cd, ac) == 0 &&
      VectorProduct(cd, cb) == 0) {
    if (s2.a.CrossesSegment(*this) || s2.b.CrossesSegment(*this) || a.CrossesSegment(s2) || b.CrossesSegment(s2)) {
      return true;
    }
  }
  return false;
}

Segment* Segment::Clone() const {
  auto copy = new Segment(*this);
  return copy;
}

std::string Segment::ToString() const {
  return "Segment(" + a.ToString() + ", " + b.ToString() + ")";
}


