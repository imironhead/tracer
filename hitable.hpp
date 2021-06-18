#ifndef __TRACER_HITABLE_H__
#define __TRACER_HITABLE_H__

#include "ray.hpp"
#include "vector_3d.hpp"


class HitRecord {
  public:
    float     time_;
    Vector3D  position_;
    Vector3D  normal_;
};


class Hitable {
  public:
    virtual bool Hit(
      const Ray& ray,
      float min_time,
      float max_time,
      HitRecord& record) const = 0;
};


#endif
