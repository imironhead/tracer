#ifndef __TRACER_MATH_HITABLE_H__
#define __TRACER_MATH_HITABLE_H__

#include "ray.hpp"
#include "vec.hpp"


class Material;

class Hitable {
public:
    class Record {
    public:
        Vec3        position;
        Vec3        normal;
        Material*   material_ptr;
    };

public:
    virtual bool hit(
        const Ray& ray,
        float min_time,
        float max_time,
        Hitable::Record& hit_record) const = 0;
};

#endif

