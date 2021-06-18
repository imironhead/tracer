#include <cmath>
#include "sphere.hpp"


bool Sphere::Hit(
    const Ray& ray,
    float min_time,
    float max_time,
    HitRecord& record) const {
  // If the ray hit the sphere, we can find 2 points which satisfy the
  // equations:
  //
  // r: radius
  // v: a vector, center of the sphere to the origin of the ray.
  // d: direction of the ray
  // t: a scalar, it the ray hit the sphere, t must be real.
  //
  // |v + t * d|^2 = r^2
  auto v = ray.origin_ - this->center_;
  auto a = ray.direction_.LengthSquare();
  auto b = v.Dot(ray.direction_);
  auto c = v.LengthSquare() - this->radius_ * this->radius_;
  auto discriminant = b * b - a * c;

  // If discriminant <  0.0f, the ray can not hit the sphere.
  // If discriminant == 0.0f, the ray can touch the sphere.
  if (discriminant <= 0.0f) { return false; }

  auto temp = std::sqrt(discriminant);

  // Upon hit, t is the smaller one.
  auto tmp_time = (-b - temp) / a;

  if (min_time < tmp_time && tmp_time < max_time) {
    record.time_ = tmp_time;
    record.position_ = ray.PositionAtParameter(tmp_time);
    record.normal_ = (record.position_ - this->center_) / this->radius_;

    return true;
  }

  tmp_time = (-b + temp) / a;

  if (min_time < tmp_time && tmp_time < max_time) {
    record.time_ = tmp_time;
    record.position_ = ray.PositionAtParameter(tmp_time);
    record.normal_ = (record.position_ - this->center_) / this->radius_;

    return true;
  }

  return false;
}
