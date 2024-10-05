#include "../point.h"
#include "../ray.h"
#include "../line.h"
#include "../segment.h"
#include "../IShape.h"
#include "../polygon.h"
#include "../circle.h"
#include "../vector.h"

using geometry::Segment;
using geometry::Vector;
using geometry::Point;
using geometry::Ray;

Ray::Ray(const Point& other, const Vector& vec) : p(other), v(vec) {
}

Ray::Ray(const Point& other1, const Point& other2) {
  p = other1;
  v = Vector(other1, other2);
}

Ray::Ray(const Ray& other) {
  p = other.p;
  v = other.v;
}

Ray& Ray::Move(const Vector& vec) {
  p = p.Move(vec);
  return *this;
}

bool Ray::ContainsPoint(const Point& other) const {
  Vector vec(p.x, p.y, other.x, other.y);
  return (ScalarProduct(vec, v) >= 0 && VectorProduct(v, vec) == 0);
}

bool Ray::CrossesSegment(const Segment& s) const {
  Vector v1(p.x, p.y);
  Vector v2 = v1 + v;
  Point p2(v2.x, v2.y);
  Line l1(p, p2);
  if (!l1.CrossesSegment(s)) {
    return false;
  }
  Vector ao(s.a.x, s.a.y, p.x, p.y);
  Vector ab(s.a.x, s.a.y, s.b.x, s.b.y);
  if (VectorProduct(ao, ab) * VectorProduct(v, ab) < 0) {
    return true;
  }
  if (VectorProduct(ao, ab) == 0 && VectorProduct(v, ab) == 0) {
    return ((*this).ContainsPoint(s.a) || (*this).ContainsPoint(s.b));
  }
  return false;
}

Ray* Ray::Clone() const {
  auto copy = new Ray(*this);
  return copy;
}

std::string Ray::ToString() const {
  return "Ray(" + p.ToString() + ", " + v.ToString() + ")";
}