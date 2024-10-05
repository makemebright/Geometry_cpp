#include "../segment.h"
#include "../IShape.h"
#include "../polygon.h"
#include "../ray.h"
#include "../circle.h"
#include "../point.h"
#include "../line.h"
#include "../vector.h"

using geometry::Point;
using geometry::Segment;
using geometry::Polygon;
using geometry::Vector;

Polygon::Polygon(const std::vector<Point>& v) : vertices(v) {
}

Polygon::Polygon(const std::vector<Point>&& other) : vertices(other) {
}

Polygon& Polygon::Move(const Vector& v) {
  for (size_t i = 0; i < vertices.size(); ++i) {
    vertices[i] = vertices[i].Move(v);
  }
  return *this;
}

bool Polygon::ContainsPoint(const Point& p) const {
  Segment s1(vertices[vertices.size() - 1], vertices[0]);
  auto edges = new Segment[vertices.size()];
  edges[0] = s1;
  for (size_t i = 1; i < vertices.size(); ++i) {
    Segment s(vertices[i - 1], vertices[i]);
    edges[i] = s;
  }
  bool need_to_change = true;
  int64_t counter;
  int64_t degree = 1;
  while (need_to_change) {
    counter = 0;
    need_to_change = false;
    Point inf(100000 * degree, p.y + 1);
    Ray ray(p, inf);
    for (size_t i = 0; i < vertices.size(); ++i) {
      if (edges[i].ContainsPoint(p)) {
        delete[] edges;
        return true;
      }
      if (ray.ContainsPoint(edges[i].a)) {
        need_to_change = true;
        degree *= 10;
        break;
      }
      if (ray.CrossesSegment(edges[i])) {
        ++counter;
      }
    }
  }
  if (counter % 2 == 0) {
    delete[] edges;
    return false;
  }
  delete[] edges;
  return true;
}

bool Polygon::CrossesSegment(const Segment& other) const {
  for (size_t i = 0; i < vertices.size(); ++i) {
    Segment tmp(vertices[i], vertices[(i + 1) % vertices.size()]);
    if (tmp.CrossesSegment(other)) {
      return true;
    }
  }
  return false;
}

Polygon* Polygon::Clone() const {
  auto copy = new Polygon(*this);
  return copy;
}

std::string Polygon::ToString() const {
  std::string str = "Polygon(";
  for (size_t i = 0; i < vertices.size() - 1; ++i) {
    str += vertices[i].ToString() + ", ";
  }
  return str + vertices[vertices.size() - 1].ToString() + ")";
}
