#ifndef __TRACER_RAY_H__
#define __TRACER_RAY_H__

#include "vector_3d.hpp"


class Ray {
  public:
    Vector3D  origin_;
    Vector3D  direction_;

  public:
    Ray() {}
    Ray(const Vector3D& origin, const Vector3D& direction)
        : origin_(origin), direction_(direction) {}

    explicit Ray(const Ray& that)
        : origin_(that.origin_), direction_(that.direction_) {}

    Vector3D PositionAtParameter(float parameter) const {
      return this->origin_ + this->direction_ * parameter;
    }
};

#endif
