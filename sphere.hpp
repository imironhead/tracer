#ifndef __TRACER_MATH_SPHERE_H__
#define __TRACER_MATH_SPHERE_H__

#include "hitable.hpp"


class Material;

class Sphere : public Hitable {
public:
    Vec3        center;
    float       radius;
    Material*   material_ptr;

public:
    Sphere() {}
    Sphere(const Vec3& c, float r, Material* m) :
        center(c), radius(r), material_ptr(m) {}

    virtual bool hit(
        const Ray& ray,
        float min_time,
        float max_time,
        Hitable::Record& hit_record) const;
};


#endif

