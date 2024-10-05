#include "../point.h"
#include "../line.h"
#include "../IShape.h"
#include "../polygon.h"
#include "../ray.h"
#include "../circle.h"
#include "../vector.h"
#include "../segment.h"

using geometry::Vector;
using geometry::Point;

Vector::Vector() : x(0), y(0) {
}
Vector::Vector(int64_t x1, int64_t y1) : x(x1), y(y1) {
}
Vector::Vector(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
  x = x2 - x1;
  y = y2 - y1;
}
Vector::Vector(const Vector& other) {
  x = other.x;
  y = other.y;
}

Vector::Vector(const Point& p1, const Point& p2) {
  x = p2.x - p1.x;
  y = p2.y - p1.y;
}

Vector Vector::operator+() const {
  return *this;
}

Vector Vector::operator-() const {
  Vector ans(-x, -y);
  return ans;
}

Vector& Vector::operator=(const Vector& other) {
  if (this != &other) {
    x = other.x;
    y = other.y;
  }
  return *this;
}

Vector& Vector::operator+=(const Vector& other) {
  x += other.x;
  y += other.y;
  return *this;
}

Vector& Vector::operator-=(const Vector& other) {
  x -= other.x;
  y -= other.y;
  return *this;
}

Vector& Vector::operator*=(const int64_t lambda) {
  x *= lambda;
  y *= lambda;
  return *this;
}

Vector& Vector::operator/=(const int64_t lambda) {
  x /= lambda;
  y /= lambda;
  return *this;
}

Vector Vector::operator*(const int64_t lambda) const {
  auto tmp = Vector();
  return tmp *= lambda;
}

Vector Vector::operator/(const int64_t lambda) const {
  auto tmp = Vector();
  return tmp /= lambda;
}

Vector geometry::operator+(const Vector& f, const Vector& s) {
  auto tmp = f;
  return tmp += s;
}

Vector geometry::operator-(const Vector& f, const Vector& s) {
  auto tmp = f;
  return tmp -= s;
}

bool Vector::operator==(const Vector& other) const {
  return (this->x == other.x && this->y == other.y);
}

bool Vector::operator!=(const Vector& other) const {
  return !(*this == other);
}

std::string Vector::ToString() const {
  return "Vector(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

int64_t geometry::ScalarProduct(const Vector& f, const Vector& s) {
  return f.x * s.x + f.y * s.y;
}

int64_t geometry::VectorProduct(const Vector& f, const Vector& s) {
  return f.x * s.y - f.y * s.x;
}

long double Vector::Length() const {
  return sqrt(this->x * this->x + this->y * this->y);
}

double geometry::Area(const Vector& f, const Vector& s) {
  return static_cast<double>(std::abs(VectorProduct(f, s))) / 2;
}

Vector geometry::operator-(const Point& p1, const Point& p2) {
  Vector v1(p2.x, p2.y, p1.x, p1.y);
  return v1;
}

