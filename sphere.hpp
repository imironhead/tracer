#ifndef __TRACER_SPHERE_H__
#define __TRACER_SPHERE_H__

#include "hitable.hpp"
#include "ray.hpp"
#include "vector_3d.hpp"


class Sphere : Hitable {
  public:
    Vector3D  center_;
    float     radius_;

  public:
    Sphere() {}
    Sphere(const Vector3D& center, float radius)
        : center_(center), radius_(radius) {}

    virtual bool Hit(
      const Ray& ray,
      float min_time,
      float max_time,
      HitRecord& record) const;
};


#endif
